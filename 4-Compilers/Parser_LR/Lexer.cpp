#include"Lexer.h"

#include<iostream>
#include<fstream>
#include<iomanip>
#define fileName "input.txt"

using namespace std;

Lexer::Lexer()
{
	rowCnt = 1;
	tokenCnt = 0;
	charCnt = 0;
	rowPos = 1;
	tokenStream.clear();
	errorStream.clear();
	symbolTable.clear();
	fill(symbolCnt.begin(), symbolCnt.end(), 0);
};

void Lexer::scan()
{
	ifstream fin;
	fin.open(fileName);
	if (!fin.is_open())
	{
		cout << "打开文件" << fileName << "失败\n请检查文件名或路径是否正确！（见Lexer.cpp第六行）\n";
		exit(1);
	}

	char c;						//当前读取的字符
	char c1 = 0;					//下一次读取的字符
	string str = "";				//当前读取到的单词
	bool eol = false;				//end-of-line,用于标记是否到达行尾
	int commentRow;				//注释所在行数
	bool flag = true;

	while ((c = fin.get()) != EOF)
	{
		eol = false;
		//空格或制表符
		if (c == ' ' || c == '\t')
		{
			//标识符、字符串、字符常量、数字常量、块注释均需处理空格和制表符
			//不是上面列举的这些则跳过
			TokenType tokenType = dfa.getTokenType();
			if (tokenType != IDENTIFIER
				&& tokenType != STRING_LITERAL
				&& tokenType != CHAR_CONSTANTS
				&& tokenType != NUMERIC_CONSTANTS
				&& tokenType != BLOCK_COMMENT)
				continue;
		}

		//换行符
		if (c == '\n')
		{
			rowCnt++;
			rowPos++;
			//行注释、预处理命令、字符串字面量、标识符、字符常量、数字常量均需处理换行符
			//不是上面列举的这些则跳过
			TokenType tokenType = dfa.getTokenType();
			if (tokenType != BLOCK_COMMENT
				&& tokenType != LINE_COMMENT
				&& tokenType != PREPROCESSOR
				&& tokenType != STRING_LITERAL
				&& tokenType != IDENTIFIER
				&& tokenType != CHAR_CONSTANTS
				&& tokenType != NUMERIC_CONSTANTS)
				continue;

			//如果需要处理换行符，由于'\n'不能计入统计字符数，charCnt减1,抵消下面的加1
			charCnt--;
		}

		//字符计数加1
		charCnt++;

		//将当前读到的字符连接在str后
		str += c;

		Token token;

		//识别出了token
		bool finish = dfa.transition(c, eol);
		if (dfa.getTokenType() == BLOCK_COMMENT && flag)
		{
			commentRow = rowPos;
			flag = false;
		}
		if (finish)
		{
			if (dfa.getTokenType() == BLOCK_COMMENT)
			{
				flag = true;
			}
			//需要回退（换行符不作回退处理）
			if (dfa.getPutbackFlag() && c != '\n')
			{
				fin.putback(c);		//将当前字符放回ifstream流fin中
				str.pop_back();		//去掉str中多读入的字符
				charCnt--;
			}

			token.tokenType = dfa.getTokenType();

			//注释或预处理命令不加进记号流中
			if (token.tokenType == LINE_COMMENT
				|| token.tokenType == BLOCK_COMMENT
				|| token.tokenType == PREPROCESSOR)
			{
				str = "";
				dfa.setArg(0, false, UNKNOWN);		//DFA回到初始状态
				continue;
			}

			token.str = str;

			//检测到错误（错误类型为连续的枚举类型）
			if (token.tokenType >= NUMERIC_ERROR && token.tokenType <= ILLEGAL_CHAR)
			{
				Error error;
				error.errorType = token.tokenType;
				error.str = str;
				error.rowPos = rowPos;
				if (eol) error.rowPos--;
				errorStream.push_back(error);		//加入到错误流中
			}
			//没有错误
			else
			{
				if (keywordList.count(str))			//在关键字列表中	
					token.tokenType = KEYWORD;
				else
				{
					if (token.tokenType == IDENTIFIER && !symbolTable.count(str))
						symbolTable.insert(str);
				}
				tokenStream.push_back(token);		//加入到记号流中
				tokenCnt++;
				symbolCnt[token.tokenType]++;
			}

			dfa.setArg(0, false, UNKNOWN);			//DFA回到初态
			str = "";		//清空str
		}

		token.tokenType = dfa.getTokenType();

		//如果是文件的最后一个字符
		if ((c1 = fin.get()) == EOF)
		{
			if (token.tokenType >= NUMERIC_ERROR && token.tokenType <= ILLEGAL_CHAR)
			{
				Error error;
				error.errorType = token.tokenType;
				error.str = str;
				error.rowPos = rowPos;
				if (eol) error.rowPos--;
				errorStream.push_back(error);
			}

			if (dfa.getState() != 0)
			{
				//识别出了token
				if (dfa.transition(';', eol))
				{
					Token token;
					token.tokenType = dfa.getTokenType();

					if (token.tokenType >= NUMERIC_ERROR && token.tokenType <= ILLEGAL_CHAR)
					{
						Error error;
						error.errorType = token.tokenType;
						error.str = str;
						error.rowPos = rowPos;
						if (eol) error.rowPos--;
						errorStream.push_back(error);
					}
					else
					{
						token.str = str;
						tokenStream.push_back(token);
						if (token.tokenType == IDENTIFIER && !symbolTable.count(str))
							symbolTable.insert(str);
						symbolCnt[token.tokenType]++;
						tokenCnt++;
					}
				}
			}
		}
		fin.putback(c1);
	}

	TokenType tokenType = dfa.getTokenType();

	if (tokenType == BLOCK_COMMENT)
	{
		Error error;
		error.errorType = COMMENT_ERROR;
		error.str = str;
		error.rowPos = rowPos;
		error.rowPos = commentRow;
		errorStream.push_back(error);
	}
	else if (tokenType == STRING_LITERAL)
	{
		Error error;
		error.errorType = STRING_ERROR;
		error.str = str;
		error.rowPos = rowPos;
		errorStream.push_back(error);
	}
	else if (tokenType == CHAR_CONSTANTS)
	{
		Error error;
		error.errorType = CHAR_ERROR;
		error.str = str;
		error.rowPos = rowPos;
		errorStream.push_back(error);
	}
}

void Lexer::printTokenStream()
{
	cout << "******************************************************" << endl;
	cout << "Token Stream:" << endl << endl;
	for (auto token : tokenStream)
	{
		if (token.str[token.str.size() - 1] == '\n')
			token.str.pop_back();
		cout << '<' << setw(20) << tokenName[token.tokenType];
		cout << " , " << setw(10) << token.str << "\t>" << endl;
	}
	cout << endl << "******************************************************" << endl << endl;

	ofstream fout;
	fout.open("output\\TokenStream.txt");
	fout << "Token Stream:" << endl << endl;
	for (auto token : tokenStream)
	{
		if (token.str[token.str.size() - 1] == '\n')
			token.str.pop_back();
		fout << '<' << setw(20) << tokenName[token.tokenType];
		fout << " , " << setw(10) << token.str << "\t>" << endl;
	}

}

void Lexer::printInfo()
{
	cout << "******************************************************" << endl;
	cout << "Statistical Information:" << endl;
	cout << "Row Count: " << rowCnt << endl;
	cout << "Character Count: " << charCnt << endl;
	cout << "Token Count: " << tokenCnt << endl << endl;
	for (int i = NUMERIC_ERROR; i <= STRING_LITERAL; i++)
	{
		if (symbolCnt[i] != 0)
		{
			cout << tokenName[i] << ": " << symbolCnt[i] << endl;
		}
	}
	cout << endl << "******************************************************" << endl << endl;

	ofstream fout;
	fout.open("output\\StatisticalInformation.txt");
	fout << "Statistical Information:" << endl;
	fout << "Row Count: " << rowCnt << endl;
	fout << "Character Count: " << charCnt << endl;
	fout << "Token Count: " << tokenCnt << endl << endl;
	for (int i = NUMERIC_ERROR; i <= STRING_LITERAL; i++)
	{
		if (symbolCnt[i] != 0)
		{
			fout << tokenName[i] << ": " << symbolCnt[i] << endl;
		}
	}

}

void Lexer::printErrorStream()
{
	cout << "******************************************************" << endl;

	cout << "Error counts: " << errorStream.size() << endl;
	cout << "Error Stream:" << endl << endl;
	for (auto r : errorStream)
	{
		//删掉\n
		if (r.str[r.str.size() - 1] == '\n')
			r.str.pop_back();
		cout << "Row: " << r.rowPos << endl;
		cout << "Error Type: " << errorName[r.errorType] << endl;
		cout << r.str << endl << endl;
	}
	cout << endl << "******************************************************" << endl << endl;


	ofstream fout;
	fout.open("output\\ErrorStream.txt");
	fout << "Error counts: " << errorStream.size() << endl;
	fout << "Error Stream:" << endl << endl;
	for (auto r : errorStream)
	{
		//删掉\n
		if (r.str[r.str.size() - 1] == '\n')
			r.str.pop_back();
		fout << "Row: " << r.rowPos << endl;
		fout << "Error Type: " << errorName[r.errorType] << endl;
		fout << r.str << endl << endl;
	}
}

void Lexer::printSymbolTable()
{
	cout << "******************************************************" << endl;
	cout << "Symbol Table:" << endl << endl;
	for (auto r : symbolTable)
	{
		cout << r << endl;
	}
	cout << endl << "******************************************************" << endl << endl;

	ofstream fout;
	fout.open("output\\SymbolTable.txt");
	fout << "Symbol Table:" << endl << endl;
	for (auto r : symbolTable)
	{
		fout << r << endl;
	}
}

deque<Token> Lexer::getInputString()
{
	deque<Token> inputString;
	inputString.clear();
	for (auto r : tokenStream)
	{
		inputString.push_back(r);
	}
	return inputString;
}
#include"Lexer.h"

#include<iostream>
#include<fstream>
#include<iomanip>
#define fileName "test.txt"

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
		cout << "���ļ�"<< fileName<<"ʧ��\n�����ļ�����·���Ƿ���ȷ������Lexer.cpp�����У�\n";
		exit(1);
	}

	char c;						//��ǰ��ȡ���ַ�
	char c1=0;					//��һ�ζ�ȡ���ַ�
	string str="";				//��ǰ��ȡ���ĵ���
	bool eol=false;				//end-of-line,���ڱ���Ƿ񵽴���β
	int commentRow;				//ע����������
	bool flag = true;

	while ((c = fin.get()) != EOF)
	{
		eol = false;
		//�ո���Ʊ��
		if (c == ' ' || c == '\t')
		{
			//��ʶ�����ַ������ַ����������ֳ�������ע�;��账��ո���Ʊ��
			//���������оٵ���Щ������
			TokenType tokenType = dfa.getTokenType();
			if (tokenType != IDENTIFIER
				&& tokenType != STRING_LITERAL
				&& tokenType != CHAR_CONSTANTS
				&& tokenType != NUMERIC_CONSTANTS
				&& tokenType != BLOCK_COMMENT)
				continue;
		}

		//���з�
		if (c == '\n')
		{
			rowCnt++;
			rowPos++;
			//��ע�͡�Ԥ��������ַ�������������ʶ�����ַ����������ֳ������账���з�
			//���������оٵ���Щ������
			TokenType tokenType = dfa.getTokenType();
			if (tokenType != BLOCK_COMMENT
				&& tokenType != LINE_COMMENT
				&& tokenType != PREPROCESSOR
				&& tokenType != STRING_LITERAL
				&& tokenType != IDENTIFIER
				&& tokenType != CHAR_CONSTANTS
				&& tokenType != NUMERIC_CONSTANTS)
				continue;

			//�����Ҫ�����з�������'\n'���ܼ���ͳ���ַ�����charCnt��1,��������ļ�1
			charCnt--;
		}

		//�ַ�������1
		charCnt++;

		//����ǰ�������ַ�������str��
		str += c;

		Token token;

		//ʶ�����token
		bool finish = dfa.transition(c, eol);
		if (dfa.getTokenType() == BLOCK_COMMENT&&flag)
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
			//��Ҫ���ˣ����з��������˴���
			if (dfa.getPutbackFlag()&&c!='\n')
			{
				fin.putback(c);		//����ǰ�ַ��Ż�ifstream��fin��
				str.pop_back();		//ȥ��str�ж������ַ�
				charCnt--;
			}

			token.tokenType = dfa.getTokenType();

			//ע�ͻ�Ԥ��������ӽ��Ǻ�����
			if (token.tokenType == LINE_COMMENT
				|| token.tokenType == BLOCK_COMMENT
				|| token.tokenType == PREPROCESSOR)
			{
				str = "";
				dfa.setArg(0, false, UNKNOWN);		//DFA�ص���ʼ״̬
				continue;
			}

			token.str = str;

			//��⵽���󣨴�������Ϊ������ö�����ͣ�
			if (token.tokenType >= NUMERIC_ERROR && token.tokenType <= ILLEGAL_CHAR)
			{
				Error error;
				error.errorType = token.tokenType;
				error.str = str;
				error.rowPos = rowPos;
				if (eol) error.rowPos--;
				errorStream.push_back(error);		//���뵽��������
			}
			//û�д���
			else
			{
				if (keywordList.count(str))			//�ڹؼ����б���	
					token.tokenType = KEYWORD;
				else
				{
					if (token.tokenType == IDENTIFIER && !symbolTable.count(str))
						symbolTable.insert(str);
				}
				tokenStream.push_back(token);		//���뵽�Ǻ�����
				tokenCnt++;
				symbolCnt[token.tokenType]++;
			}

			dfa.setArg(0, false, UNKNOWN);			//DFA�ص���̬
			str = "";		//���str
		}

		token.tokenType = dfa.getTokenType();

		//������ļ������һ���ַ�
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
				//ʶ�����token
				if (dfa.transition(';',eol))
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
		//ɾ��\n
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
		//ɾ��\n
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
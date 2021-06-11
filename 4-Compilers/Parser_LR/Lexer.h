#pragma once
#include<vector>
#include<string>
#include<set>
#include<array>
#include<deque>
#include"DFA.h"

using namespace std;

typedef struct
{
	TokenType tokenType;
	string str;
}Token;

typedef struct
{
	TokenType errorType;
	string str;
	int rowPos;
}Error;

class Lexer
{
public:
	Lexer();					//构造函数
	~Lexer() {};				//析构函数
	void scan();				//扫描程序
	void printInfo();			//打印统计信息
	void printTokenStream();	//打印记号流
	void printErrorStream();	//打印错误流
	void printSymbolTable();	//打印符号表
	deque<Token> getInputString();	//获取输入串

private:
	DFA dfa;					//DFA
	vector<Token>tokenStream;	//记号流
	vector<Error>errorStream;	//错误流
	set<string>symbolTable;		//符号表
	array<int, 100>symbolCnt;	//各类符号计数
	int rowCnt;					//行计数
	int tokenCnt;				//单词计数
	int charCnt;				//字符计数
	int rowPos;					//错误定位行
};

const vector<string>tokenName = {
	"NUMERIC_ERROR",
	"CHAR_ERROR",
	"STRING_ERROR",
	"COMMENT_ERROR",
	"ILLEGAL_CHAR",
	"UNKNOWN",
	"IDENTIFIER",
	"KEYWORD",
	"ADD",
	"SUB",
	"ADD_ASSIGN",
	"INC",
	"SUB_ASSIGN",
	"DEC",
	"ARROW",
	"MUL",
	"MUL_ASSIGN",
	"DIV",
	"DIV_ASSIGN",
	"LINE_COMMENT",
	"BLOCK_COMMENT",
	"MOD",
	"MOD_ASSIGN",
	"EQUAL",
	"ASSIGN",
	"BIT_AND_ASSIGN",
	"BIT_AND",
	"AND",
	"BIT_OR_ASSIGN",
	"BIT_OR",
	"OR",
	"BIT_XOR_ASSIGN",
	"BIT_XOR",
	"XOR",
	"LESS",
	"GREATER",
	"LESS_EQUAL",
	"GREATER_EQUAL",
	"NOT_EQUAL",
	"SHL",
	"SHR",
	"SHL_ASSIGN",
	"SHR_ASSIGN",
	"NOT",
	"BIT_NOT",
	"DOT",
	"L_PARENTHESIS",
	"R_PARENTHESIS",
	"L_BRACKET",
	"R_BRACKET",
	"L_BRACE",
	"R_BRACE",
	"SEMICOLON",
	"COLON",
	"COMMA",
	"QUESTION",
	"NUMERIC_CONSTANTS",
	"CHAR_CONSTANTS",
	"PREPROCESSOR",
	"STRING_LITERAL"
};

const vector<string>errorName = {
	"NUMERIC_ERROR (Incomplete numeric constant)",
	"CHAR_ERROR: (Lack the right quote)",
	"STRING_ERROR: (Lack the right quote)",
	"COMMENT_ERROR: (Unterminated comment)",
	"ILLEGAL_CHAR"
};

const set<string> keywordList = {
	"auto",
	"break",
	"case",
	"char",
	"const",
	"continue",
	"default",
	"do",
	"double",
	"else",
	"enum",
	"extern",
	"float",
	"for",
	"goto",
	"if",
	"inline",
	"int",
	"long",
	"register",
	"restrict",
	"return",
	"short",
	"signed",
	"sizeof",
	"static",
	"struct",
	"switch",
	"typedef",
	"union",
	"unsigned",
	"void",
	"volatile",
	"while",
	"_Bool",
	"_Complex",
	"_Imaginary"
};


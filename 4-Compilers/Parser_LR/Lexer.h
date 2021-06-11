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
	Lexer();					//���캯��
	~Lexer() {};				//��������
	void scan();				//ɨ�����
	void printInfo();			//��ӡͳ����Ϣ
	void printTokenStream();	//��ӡ�Ǻ���
	void printErrorStream();	//��ӡ������
	void printSymbolTable();	//��ӡ���ű�
	deque<Token> getInputString();	//��ȡ���봮

private:
	DFA dfa;					//DFA
	vector<Token>tokenStream;	//�Ǻ���
	vector<Error>errorStream;	//������
	set<string>symbolTable;		//���ű�
	array<int, 100>symbolCnt;	//������ż���
	int rowCnt;					//�м���
	int tokenCnt;				//���ʼ���
	int charCnt;				//�ַ�����
	int rowPos;					//����λ��
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


#pragma once

enum TokenType {
	NUMERIC_ERROR,		//数字常量错误
	CHAR_ERROR,			//字符常量错误
	STRING_ERROR,		//字符串字面量错误
	COMMENT_ERROR,		//注释错误
	ILLEGAL_CHAR,		//非法字符错误
	UNKNOWN,			//未知
	IDENTIFIER,			//标识符
	KEYWORD,			//关键字
	ADD,				//加
	SUB,				//减
	ADD_ASSIGN,			//加赋值
	INC,				//自增
	SUB_ASSIGN,			//减赋值
	DEC,				//自减
	ARROW,				//箭头
	MUL,				//乘法
	MUL_ASSIGN,			//乘赋值
	DIV,				//除
	DIV_ASSIGN,			//除赋值
	LINE_COMMENT,		//行注释0
	BLOCK_COMMENT,		//块注释
	MOD,				//模
	MOD_ASSIGN,			//模赋值
	EQUAL,				//等于
	ASSIGN,				//赋值
	BIT_AND_ASSIGN,		//位与赋值
	BIT_AND,			//位与
	AND,				//与
	BIT_OR_ASSIGN,		//位或赋值
	BIT_OR,				//位或
	OR,					//或
	BIT_XOR_ASSIGN,		//位异或赋值
	BIT_XOR,			//位异或
	XOR,				//异或
	LESS,				//小于
	GREATER,			//大于
	LESS_EQUAL,			//小于等于
	GREATER_EQUAL,		//大于等于
	NOT_EQUAL,			//不等于
	SHL,				//左移
	SHR,				//右移
	SHL_ASSIGN,			//左移赋值
	SHR_ASSIGN,			//右移赋值
	NOT,				//非
	BIT_NOT,			//按位取反
	DOT,				//点
	L_PARENTHESIS,		//左圆括号
	R_PARENTHESIS,		//右圆括号
	L_BRACKET,			//左方括号
	R_BRACKET,			//右方括号
	L_BRACE,			//左花括号
	R_BRACE,			//右花括号
	SEMICOLON,			//分号
	COLON,				//冒号
	COMMA,				//逗号
	QUESTION,			//问号
	NUMERIC_CONSTANTS,	//数字常量
	CHAR_CONSTANTS,		//字符常量
	PREPROCESSOR,		//预处理命令
	STRING_LITERAL		//字符串字面量
};




#pragma once

enum TokenType {
	NUMERIC_ERROR,		//���ֳ�������
	CHAR_ERROR,			//�ַ���������
	STRING_ERROR,		//�ַ�������������
	COMMENT_ERROR,		//ע�ʹ���
	ILLEGAL_CHAR,		//�Ƿ��ַ�����
	UNKNOWN,			//δ֪
	IDENTIFIER,			//��ʶ��
	KEYWORD,			//�ؼ���
	ADD,				//��
	SUB,				//��
	ADD_ASSIGN,			//�Ӹ�ֵ
	INC,				//����
	SUB_ASSIGN,			//����ֵ
	DEC,				//�Լ�
	ARROW,				//��ͷ
	MUL,				//�˷�
	MUL_ASSIGN,			//�˸�ֵ
	DIV,				//��
	DIV_ASSIGN,			//����ֵ
	LINE_COMMENT,		//��ע��0
	BLOCK_COMMENT,		//��ע��
	MOD,				//ģ
	MOD_ASSIGN,			//ģ��ֵ
	EQUAL,				//����
	ASSIGN,				//��ֵ
	BIT_AND_ASSIGN,		//λ�븳ֵ
	BIT_AND,			//λ��
	AND,				//��
	BIT_OR_ASSIGN,		//λ��ֵ
	BIT_OR,				//λ��
	OR,					//��
	BIT_XOR_ASSIGN,		//λ���ֵ
	BIT_XOR,			//λ���
	XOR,				//���
	LESS,				//С��
	GREATER,			//����
	LESS_EQUAL,			//С�ڵ���
	GREATER_EQUAL,		//���ڵ���
	NOT_EQUAL,			//������
	SHL,				//����
	SHR,				//����
	SHL_ASSIGN,			//���Ƹ�ֵ
	SHR_ASSIGN,			//���Ƹ�ֵ
	NOT,				//��
	BIT_NOT,			//��λȡ��
	DOT,				//��
	L_PARENTHESIS,		//��Բ����
	R_PARENTHESIS,		//��Բ����
	L_BRACKET,			//������
	R_BRACKET,			//�ҷ�����
	L_BRACE,			//������
	R_BRACE,			//�һ�����
	SEMICOLON,			//�ֺ�
	COLON,				//ð��
	COMMA,				//����
	QUESTION,			//�ʺ�
	NUMERIC_CONSTANTS,	//���ֳ���
	CHAR_CONSTANTS,		//�ַ�����
	PREPROCESSOR,		//Ԥ��������
	STRING_LITERAL		//�ַ���������
};





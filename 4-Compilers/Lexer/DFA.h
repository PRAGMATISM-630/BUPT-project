#pragma once
#include<cctype>
#include"TokenType.h"

class DFA
{
public:
	//���캯��
	DFA() :state(0), putbackFlag(false) {};
	//��������
	~DFA() {};
	//״̬ת�ƺ�����eol(end-of-line)���ڱ���Ƿ����һ�е�ĩβ
	bool transition(char ch,bool &eol);			
	//�����Զ�����ǰʶ���token����
	TokenType getTokenType() { return tokenType; }	
	//���ص�ǰ�Զ����Ƿ���Ҫ���˵ı�־
	bool getPutbackFlag() { return putbackFlag; }
	//���ص�ǰ�Զ�����״̬
	int getState() { return state; }
	//״̬ת�ƹ����������޸�״̬���Ƿ���˱�־�Լ�ʶ���token����
	inline void setArg(int s, bool p, TokenType t);

private:
	int state;						//��ǰ״̬
	bool putbackFlag;				//����Ƿ���Ҫ����
	TokenType tokenType;			//token����
};
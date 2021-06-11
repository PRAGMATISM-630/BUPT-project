#pragma once
#include<cctype>
#include"TokenType.h"

class DFA
{
public:
	//构造函数
	DFA() :state(0), putbackFlag(false) {};
	//析构函数
	~DFA() {};
	//状态转移函数，eol(end-of-line)用于标记是否读到一行的末尾
	bool transition(char ch, bool& eol);
	//返回自动机当前识别的token类型
	TokenType getTokenType() { return tokenType; }
	//返回当前自动机是否需要回退的标志
	bool getPutbackFlag() { return putbackFlag; }
	//返回当前自动机的状态
	int getState() { return state; }
	//状态转移过程中用于修改状态、是否回退标志以及识别的token类型
	inline void setArg(int s, bool p, TokenType t);

private:
	int state;						//当前状态
	bool putbackFlag;				//标记是否需要回退
	TokenType tokenType;			//token类型
};

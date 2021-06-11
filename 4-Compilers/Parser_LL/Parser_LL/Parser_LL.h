#pragma once
#include"../Lexer/Lexer.h"
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<deque>
#include<map>
#include<utility>
#include<stack>
#include<string>
#include<algorithm>
#include<fstream>
#include<iostream>
#include<sstream>
#include<iomanip>

using namespace std;

typedef string Nonterminal,Terminal;
typedef deque<string> Candidate;

class Parser
{
public:
	//构造函数
	Parser() :isLL1(true),isEmpty(false) {};

	//判断是否是LL1文法
	bool getIsLL1() { return isLL1; }

	//判断是否是空文法
	bool getIsEmpty() { return isEmpty; }

	//判断字符串s是否为终结符
	inline bool isTerminal(string s);		

	//判断字符串s是否为非终结符
	inline bool isNonterminal(string s);	

	//读取文法
	void getGrammer();

	//打印文法
	void printGrammer();

	//消左递归
	void eliminateLeftRecursion();		

	//消除公共左因子
	void eliminateLeftCommonToken();

	//消除某个非终结符产生式的公共左因子
	void eliminateLeftCommonTokenOfN(pair<Nonterminal, vector<Candidate>>);

	//构造所有非终结符的FIRST集
	void constructFirst();		

	//构造非终结符N的FIRST集
	void constructFirstOfN(Nonterminal,map<Nonterminal, bool>*);	

	//构造所有非终结符的FOLLOW集
	void constructFollow();									

	//构造非终结符N的FOLLOW集
	void constructFollowOfN(Nonterminal,map<Nonterminal, bool>*,Nonterminal);

	//获取一个候选式的FIRST集
	unordered_set<string> getFirstOfCandidate(Candidate);

	//打印first集
	void printFirstSet();									

	//打印follow集
	void printFollowSet();	

	//构造预测分析表
	void constructTable();

	//打印预测分析表
	void printTable();

	//读取词法分析器处理过后的输入串
	void getInputString(deque<Token>);

	//分析过程
	void analysis();

	//输出当前栈内容
	inline void printStack();

	//输出当前输入串内容
	inline void printInputString();

	//将候选式（是一个string的deque）连接起来转化为string
	inline string candidate2String(Candidate);

private:
	bool isLL1;			//文法是否为LL1文法
	bool isEmpty;		//文法是否为空文法

	vector<Nonterminal>nonterminals;							//非终结符
	vector<Terminal>terminals;									//终结符
	Nonterminal startSymbol;									//起始符
	unordered_map<Nonterminal, vector<Candidate>>productions;	//产生式

	unordered_map<Nonterminal, unordered_set<string>>firstSet;	//first集
	unordered_map<Nonterminal, unordered_set<string>>followSet;	//follow集

	map<pair<string, string>, Candidate> table;	//预测分析表

	stack<string>tokenStack;			//符号栈
	deque<Token>inputString;			//输入串
};

#pragma once
#include"Lexer.h"
#include<fstream>
#include<iostream>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<deque>
#include<iomanip>
#include<deque>
#include<map>
#include<stack>

using namespace std;


typedef string Nonterminal, Terminal;
typedef deque<string> Candidate;
typedef struct
{
	int seq;
	vector<pair<Nonterminal, Candidate>> item;
}Items;

class Parser
{
public:
	bool isTerminal(string);
	bool isNonterminal(string);
	void getGrammer();
	void printGrammer();
	void extendGrammer();
	void constructTable();
	void printTable();
	void printInputString();
	void printStack();
	void analyze(deque<Token>);
	//void cons(Items ,Nonterminal);
	//void construct();

private:
	bool isEmpty;		//文法是否为空文法
	int seq;

	map<pair<int, string>, string> action;					//action表
	map<pair<int, string>, string> goTo;					//goto表

	stack<string>symbolStack;			//符号栈
	stack<string>stateStack;			//状态栈
	deque<Token>inputString;			//输入串

	
	vector<Items> ItemSet;				//项目集规范族

	vector<Nonterminal>nonterminals;							//非终结符
	vector<Terminal>terminals;									//终结符
	Nonterminal startSymbol;									//起始符
	unordered_map<Nonterminal, vector<Candidate>>productions;	//产生式
	map<int, pair<Nonterminal, Candidate>>num2pro;				//编号和产生式的映射

};

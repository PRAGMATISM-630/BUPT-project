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
	bool isEmpty;		//�ķ��Ƿ�Ϊ���ķ�
	int seq;

	map<pair<int, string>, string> action;					//action��
	map<pair<int, string>, string> goTo;					//goto��

	stack<string>symbolStack;			//����ջ
	stack<string>stateStack;			//״̬ջ
	deque<Token>inputString;			//���봮

	
	vector<Items> ItemSet;				//��Ŀ���淶��

	vector<Nonterminal>nonterminals;							//���ս��
	vector<Terminal>terminals;									//�ս��
	Nonterminal startSymbol;									//��ʼ��
	unordered_map<Nonterminal, vector<Candidate>>productions;	//����ʽ
	map<int, pair<Nonterminal, Candidate>>num2pro;				//��źͲ���ʽ��ӳ��

};

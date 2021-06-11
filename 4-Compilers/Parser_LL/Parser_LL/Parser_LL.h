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
	//���캯��
	Parser() :isLL1(true),isEmpty(false) {};

	//�ж��Ƿ���LL1�ķ�
	bool getIsLL1() { return isLL1; }

	//�ж��Ƿ��ǿ��ķ�
	bool getIsEmpty() { return isEmpty; }

	//�ж��ַ���s�Ƿ�Ϊ�ս��
	inline bool isTerminal(string s);		

	//�ж��ַ���s�Ƿ�Ϊ���ս��
	inline bool isNonterminal(string s);	

	//��ȡ�ķ�
	void getGrammer();

	//��ӡ�ķ�
	void printGrammer();

	//����ݹ�
	void eliminateLeftRecursion();		

	//��������������
	void eliminateLeftCommonToken();

	//����ĳ�����ս������ʽ�Ĺ���������
	void eliminateLeftCommonTokenOfN(pair<Nonterminal, vector<Candidate>>);

	//�������з��ս����FIRST��
	void constructFirst();		

	//������ս��N��FIRST��
	void constructFirstOfN(Nonterminal,map<Nonterminal, bool>*);	

	//�������з��ս����FOLLOW��
	void constructFollow();									

	//������ս��N��FOLLOW��
	void constructFollowOfN(Nonterminal,map<Nonterminal, bool>*,Nonterminal);

	//��ȡһ����ѡʽ��FIRST��
	unordered_set<string> getFirstOfCandidate(Candidate);

	//��ӡfirst��
	void printFirstSet();									

	//��ӡfollow��
	void printFollowSet();	

	//����Ԥ�������
	void constructTable();

	//��ӡԤ�������
	void printTable();

	//��ȡ�ʷ������������������봮
	void getInputString(deque<Token>);

	//��������
	void analysis();

	//�����ǰջ����
	inline void printStack();

	//�����ǰ���봮����
	inline void printInputString();

	//����ѡʽ����һ��string��deque����������ת��Ϊstring
	inline string candidate2String(Candidate);

private:
	bool isLL1;			//�ķ��Ƿ�ΪLL1�ķ�
	bool isEmpty;		//�ķ��Ƿ�Ϊ���ķ�

	vector<Nonterminal>nonterminals;							//���ս��
	vector<Terminal>terminals;									//�ս��
	Nonterminal startSymbol;									//��ʼ��
	unordered_map<Nonterminal, vector<Candidate>>productions;	//����ʽ

	unordered_map<Nonterminal, unordered_set<string>>firstSet;	//first��
	unordered_map<Nonterminal, unordered_set<string>>followSet;	//follow��

	map<pair<string, string>, Candidate> table;	//Ԥ�������

	stack<string>tokenStack;			//����ջ
	deque<Token>inputString;			//���봮
};

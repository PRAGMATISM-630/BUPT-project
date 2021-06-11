#include"Parser_LR.h"
#include"arg.h"
using namespace std;

#define GRAMMER_FILE "grammer.txt"

bool Parser::isTerminal(string s)
{
	if (find(terminals.begin(), terminals.end(), s) == terminals.end())
		return false;
	return true;
}

bool Parser::isNonterminal(string s)
{
	if (find(nonterminals.begin(), nonterminals.end(), s) == nonterminals.end())
		return false;
	return true;
}

inline void trim(string& s)			//去掉一个字符串首尾的空格
{
	if (!s.empty())
	{
		s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
	}
}

inline Candidate split(string s, char c)		//将字符串s以字符c分割，得到的子串构成一个string类的双端队列
{
	Candidate candidate;
	string tmp;									//用来暂存分割后的字符串
	stringstream input(s);						//用字符串s初始化字符串流
	while (getline(input, tmp, c))
		if (tmp.find_first_not_of(' ') != -1)	//tmp只由空格构成时，不加入candidate
			candidate.push_back(tmp);
	return candidate;
}

void Parser::getGrammer()
{
	ifstream fin;
	fin.open(GRAMMER_FILE);
	if (!fin.is_open())			//打开文件失败
	{
		cout << "打开文件" << GRAMMER_FILE << "失败\n请检查文件名或路径是否正确！\n";
		exit(1);
	}

	string s;
	string tmp;
	getline(fin, s);		//跳过第1行
	getline(fin, s);		//读取第2行非终结符
	if (s == "")
		isEmpty = true;
	stringstream input(s);	//非终结符在字符串流s中
	while (getline(input, tmp, ' '))	//以空格作为分界符，将s分成多个子串，每个子串代表一个非终结符
		if (tmp.find_first_not_of(' ') != -1)		//子串如果不是只由空格组成的串
			nonterminals.push_back(tmp);

	getline(fin, s);		//跳过第3行
	getline(fin, s);		//跳过第4行
	getline(fin, s);		//读取第5行终结符
	if (s == "")
		isEmpty = true;
	input = stringstream(s);
	while (getline(input, tmp, ' '))
		if (tmp.find_first_not_of(' ') != -1)
			terminals.push_back(tmp);

	getline(fin, s);		//跳过第6行
	getline(fin, s);		//跳过第7行
	getline(fin, s);		//读取第8行起始符
	trim(s);
	if (s == "")
		isEmpty = true;
	startSymbol = s;

	getline(fin, s);		//跳过第9行
	getline(fin, s);		//跳过第10行
	while (getline(fin, s))	//读取11行以后的产生式
	{
		if (s == "")	//读到了空行
			continue;
		auto start = s.find_first_not_of(' ');		//找到第一个不为空格的字符，从该字符开始处理
		auto pos = s.substr(start).find(' ');		//找到第一个不为空格字符后第一个为空格的字符
		Nonterminal a = s.substr(start, pos);		//两者之间组成产生式的左边
		pos = s.substr(start).find("->");
		string s1 = s.substr(start).substr(pos + 2);	//找到产生式的右边
		input = stringstream(s1);
		while (getline(input, tmp, '|'))			//以'|'作为分隔符，将多个产生式分开
		{
			trim(tmp);
			Candidate candidate = split(tmp, ' ');
			productions[a].push_back(candidate);
		}
	}

	if (productions.size() == 0)
		isEmpty = true;
}

void Parser::printGrammer()
{
	cout << "\n*********************************************************************************\n\n";
	cout.setf(std::ios::left);
	cout << "非终结符:" << endl;
	for (auto nonterminal : nonterminals)
		cout << nonterminal << ' ';
	cout << endl << endl;

	cout << "终结符:" << endl;
	for (auto terminal : terminals)
		cout << terminal << '\t';
	cout << endl << endl;

	cout << "起始符:" << endl;
	cout << startSymbol << endl << endl;

	cout << "产生式:" << endl;
	for (auto production : productions)
	{
		for (auto candidate : production.second)
		{
			cout << setw(NONTERMINAL_WIDTH) << production.first << "-> ";
			for (auto oneToken : candidate)
			{
				cout << (oneToken == "epsilon" ? "ε" : oneToken) << ' ';
			}
			cout << endl;
		}
	}
	cout << "\n*********************************************************************************\n\n";
}

void Parser::extendGrammer()
{
	Nonterminal newNonterminal = startSymbol + "'";	//新的非终结符
	Candidate candidate;
	candidate.push_back(startSymbol);
	productions[newNonterminal].push_back(candidate);
	nonterminals.push_back(newNonterminal);
	startSymbol = newNonterminal;

	//建立编号和产生式的映射
	int cnt = 1;
	for (auto production : productions)
	{
		for (auto candidate : production.second)
		{
			if (production.first == startSymbol)
				num2pro[0] = make_pair(production.first, candidate);
			else
				num2pro[cnt++] = make_pair(production.first, candidate);
		}
	}
	cout << "Extended Grammer:\n";
	for (int i = 0; i < cnt; i++)
	{
		cout << num2pro[i].first << " -> ";
		for (auto r : num2pro[i].second)
			cout << r;
		cout << endl;
	}
	
}

void Parser::constructTable()
{
	action[make_pair(0, "(")] = "s4";
	action[make_pair(0, "num")] = "s5";
	action[make_pair(1, "+")] = "s6";
	action[make_pair(1, "-")] = "s7";
	action[make_pair(1, "$")] = "acc";
	action[make_pair(2, "+")] = "r3";
	action[make_pair(2, "-")] = "r3";
	action[make_pair(2, "*")] = "s8";
	action[make_pair(2, "/")] = "s9";
	action[make_pair(2, ")")] = "r3";
	action[make_pair(2, "$")] = "r3";
	action[make_pair(3, "+")] = "r6";
	action[make_pair(3, "-")] = "r6";
	action[make_pair(3, "*")] = "r6";
	action[make_pair(3, "/")] = "r6";
	action[make_pair(3, ")")] = "r6";
	action[make_pair(3, "$")] = "r6";
	action[make_pair(4, "(")] = "s4";
	action[make_pair(4, "num")] = "s5";
	action[make_pair(5, "+")] = "r8";
	action[make_pair(5, "-")] = "r8";
	action[make_pair(5, "*")] = "r8";
	action[make_pair(5, "/")] = "r8";
	action[make_pair(5, ")")] = "r8";
	action[make_pair(5, "$")] = "r8";
	action[make_pair(6, "(")] = "s4";
	action[make_pair(6, "num")] = "s5";
	action[make_pair(7, "(")] = "s4";
	action[make_pair(7, "num")] = "s5";
	action[make_pair(8, "(")] = "s4";
	action[make_pair(8, "num")] = "s5";
	action[make_pair(9, "(")] = "s4";
	action[make_pair(9, "num")] = "s5";
	action[make_pair(10, "+")] = "s6";
	action[make_pair(10, "-")] = "s7";
	action[make_pair(10, ")")] = "s15";
	action[make_pair(11, "+")] = "r1";
	action[make_pair(11, "-")] = "r1";
	action[make_pair(11, "*")] = "s8";
	action[make_pair(11, "/")] = "s9";
	action[make_pair(11, ")")] = "r1";
	action[make_pair(11, "$")] = "r1";
	action[make_pair(12, "+")] = "r2";
	action[make_pair(12, "-")] = "r2";
	action[make_pair(12, "*")] = "s8";
	action[make_pair(12, "/")] = "s9";
	action[make_pair(12, ")")] = "r2";
	action[make_pair(12, "$")] = "r2";
	action[make_pair(13, "+")] = "r4";
	action[make_pair(13, "-")] = "r4";
	action[make_pair(13, "*")] = "r4";
	action[make_pair(13, "/")] = "r4";
	action[make_pair(13, ")")] = "r4";
	action[make_pair(13, "$")] = "r4";
	action[make_pair(14, "+")] = "r5";
	action[make_pair(14, "-")] = "r5";
	action[make_pair(14, "*")] = "r5";
	action[make_pair(14, "/")] = "r5";
	action[make_pair(14, ")")] = "r5";
	action[make_pair(14, "$")] = "r5";
	action[make_pair(15, "+")] = "r7";
	action[make_pair(15, "-")] = "r7";
	action[make_pair(15, "*")] = "r7";
	action[make_pair(15, "/")] = "r7";
	action[make_pair(15, ")")] = "r7";
	action[make_pair(15, "$")] = "r7";
	goTo[make_pair(0, "E")] = "1";
	goTo[make_pair(0, "T")] = "2";
	goTo[make_pair(0, "F")] = "3";
	goTo[make_pair(4, "E")] = "10";
	goTo[make_pair(4, "T")] = "2";
	goTo[make_pair(4, "F")] = "3";
	goTo[make_pair(6, "T")] = "11";
	goTo[make_pair(6, "F")] = "3";
	goTo[make_pair(7, "T")] = "12";
	goTo[make_pair(7, "F")] = "3";
	goTo[make_pair(8, "F")] = "13";
	goTo[make_pair(9, "F")] = "14";
}

void Parser::printTable()
{
	cout << "\n\nSLR(1) Analysis Table:\n";
	cout.setf(ios::left);
	cout << setw(5) << "";
	vector<Terminal>tmp = terminals;
	tmp.push_back("$");
	vector<Nonterminal>tmp2 = nonterminals;
	auto iter = find(tmp2.begin(), tmp2.end(), startSymbol);
	tmp2.erase(iter);
	for (auto terminal : tmp)
	{
		cout << setw(5) << terminal;
	}
	for (auto nonterminal : tmp2)
	{
		cout << setw(5) << nonterminal;
	}
	cout << endl;
	for(int i=0;i<=15;i++)
	{
		cout << setw(5) << i;
		for (auto terminal : tmp)
		{
			cout << setw(5) << action[make_pair(i, terminal)];
		}

		for (auto nonterminal : tmp2)
		{
			cout << setw(5) << goTo[make_pair(i, nonterminal)];
		}
		cout << endl;
	}
}

void Parser::printInputString()
{
	cout << setw(15) << "Input String:  ";
	for (auto r : inputString)
		cout <<r.str<<' ';
	cout << endl;
}

void Parser::printStack()
{
	cout.setf(ios::left);
	cout <<setw(15)<< "State Stack:  ";
	auto tmp = stateStack;
	string s = "";
	while (!tmp.empty())
	{
		s = tmp.top() +" "+ s;
		tmp.pop();
	}
	cout << s << endl;

	cout << setw(15) << "Symbol Stack:  ";
	tmp = symbolStack;
	s = "";
	while (!tmp.empty())
	{
		s = tmp.top() + " " + s;
		tmp.pop();
	}
	cout << s << endl;

}

void Parser::analyze(deque<Token> input)
{
	cout << "\n\nAnalysis:\n";

	bool acc = false;			//标记是否分析完毕
	bool err = false;			//标记是否出错

	stateStack.push("0");		//初始化栈和双端队列
	symbolStack.push("$");
	inputString = input;
	Token token;
	token.str = "$";
	inputString.push_back(token);

	int cnt = 0;				//步骤数

	while (!acc && !err)		//分析未结束，未出错
	{
		cout << endl<< ++cnt << ":" << endl;
		printStack();			//打印当前栈内容
		printInputString();		//打印当前输入串内容
		
		//从分析表中获取所需采取的动作
		int num1 = stoi(stateStack.top());
		if (inputString.front().tokenType == NUMERIC_CONSTANTS)
			inputString.front().str = "num";
		string act = action[make_pair(num1, inputString.front().str)];

		if (act == "acc")			//接受
		{
			acc = true;
			cout << setw(15) << "action: "<<"accept\n";
		}
		else if (act == "")			//错误
		{
			err = true;
			cout << setw(15) << "action: "<<"error\n";
			return;
		}
		else if (act[0] == 's')		//移进
		{
			int state = stoi(act.substr(1));
			stateStack.push(act.substr(1));
			string s = inputString.front().str;
			symbolStack.push(s);
			inputString.pop_front();
			cout << setw(15) << "action:  " <<"shift "<< state << endl;
		}
		else if(act[0]=='r')		//归约
		{
			int num = stoi(act.substr(1));
			auto tmp = num2pro[num];
			cout << setw(15) << "action: "<<"reduce " << tmp.first << " -> ";
			for (auto r : tmp.second)
				cout << r;
			cout << endl;
			
			int size = tmp.second.size();
			while (size--)
			{
				stateStack.pop();
				symbolStack.pop();
			}
			symbolStack.push(tmp.first);
			stateStack.push(goTo[make_pair(stoi(stateStack.top()), symbolStack.top())]);

		}
	}

}

/*void Parser::construct()
{
	Items item;
	item.seq = seq++;
	cons(item, startSymbol);

	for (auto r : ItemSet)
	{
		cout << r.seq << endl;
		for (auto v : r.item)
		{
			cout << v.first << " -> ";
			for (auto token : v.second)
			{
				cout << token;
			}
			cout << endl;
		}
		cout << endl;
	}
	
}

string findPointNext(Candidate candidate)
{
	auto iter = find(candidate.begin(), candidate.end(), ".");
	iter++;
	if (iter == candidate.end())
		return "end";
	return *iter;
}

Candidate movePoint(Candidate candidate)
{
	Candidate newCandidate;
	for (auto iter=candidate.begin();iter!=candidate.end();iter++)
	{
		if (*iter != ".")
			newCandidate.push_back(*iter);
		else
		{
			newCandidate.push_back(*(++iter));
			newCandidate.push_back(".");
		}
	}
	return newCandidate;
}

void Parser::cons(Items it,Nonterminal N)
{
	for (auto pro : num2pro)
	{
		auto left = pro.first;
		auto right = pro.second;
		if (right.first == N)
		{
			vector<Nonterminal> newNonterminalStart;
			if (isNonterminal(right.second.front()) && right.second.front() != N)
				newNonterminalStart.push_back(right.second.front());
			right.second.push_front(".");
			auto iter = find(it.item.begin(), it.item.end(), right);
			if(iter==it.item.end())
				it.item.push_back(right);
			for (auto nonterminal : newNonterminalStart)
				cons(it, nonterminal);
		}
	}
	ItemSet.push_back(it);

	Items item;
	string pointNext = findPointNext(it.item[0].second);
	string last = pointNext;
	if (pointNext != "end")
	{
		Candidate newCandidate = movePoint(it.item[0].second);
		item.seq = seq++;
		item.item.push_back(make_pair(it.item[0].first, newCandidate));
		//cons(item, pointNext);
	}

	for (auto r : it.item)
	{
		if (r == it.item[0])
			continue;
		string pointNext = findPointNext(r.second);
		if (pointNext == last)
		{
			Candidate newCandidate = movePoint(r.second);
			item.item.push_back(make_pair(r.first, newCandidate));
		}
		else
		{
			for (auto r : item.item)
			{
				string s = findPointNext(r.second);
				if (s != "end")
				{
					cons(item, s);
				}
			}

			for (auto r : ItemSet)
			{
				cout << r.seq << endl;
				for (auto v : r.item)
				{
					cout << v.first << " -> ";
					for (auto token : v.second)
					{
						cout << token;
					}
					cout << endl;
				}
				cout << endl;
			}

			ItemSet.push_back(item);
			last = pointNext;
			item.seq=seq++;
			item.item.clear();
			Candidate newCandidate = movePoint(r.second);
			item.item.push_back(make_pair(r.first, newCandidate));
			//cons(item, pointNext);

		}

	}

	
	
}*/
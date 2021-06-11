#include"Parser_LL.h"
#include"../arg.h"

#define GRAMMER_FILE "./Parser_LL/grammer.txt"

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

inline bool Parser::isTerminal(string s)
{
	if(find(terminals.begin(), terminals.end(), s)==terminals.end())
		return false;
	return true;
}

inline bool Parser::isNonterminal(string s)
{
	if (find(nonterminals.begin(), nonterminals.end(), s) == nonterminals.end())
		return false;
	return true;
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
		if(tmp.find_first_not_of(' ') != -1)		//子串如果不是只由空格组成的串
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
		Nonterminal a = s.substr(start,pos);		//两者之间组成产生式的左边
		pos = s.substr(start).find("->");			
		string s1 = s.substr(start).substr(pos+2);	//找到产生式的右边
		input = stringstream(s1);	
		while (getline(input, tmp, '|'))			//以'|'作为分隔符，将多个产生式分开
		{
			trim(tmp);
			Candidate candidate = split(tmp, ' ');
			productions[a].push_back(candidate);
		}
	}

	if(productions.size()==0)
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
			cout << setw(NONTERMINAL_WIDTH)<<production.first << "-> ";
			for (auto oneToken : candidate)
			{
				cout << (oneToken == "epsilon" ? "ε" : oneToken) << ' ';
			}
			cout << endl;
		}
	}
	cout << "\n*********************************************************************************\n\n";
}

void Parser::eliminateLeftRecursion()
{
	unordered_map<Nonterminal, vector<Candidate>>newProductions;		//新的产生式集
	for (auto production : productions)		//对每个非终结符的所有候选式
	{
		string oldNonterminal = production.first;		//原终结符
		string newNonterminal = oldNonterminal + "'";	//新终结符
		vector<Candidate>newCandidateSet;	//新非终结符的候选式集合
		vector<Candidate>oldCandidateSet;	//原非终结符的候选式集合

		//判断是否有左递归
		bool hasLeftRecursion = false;		
		for (auto candidate : production.second)	
		{
			if (candidate.front() == oldNonterminal)
				hasLeftRecursion = true;
		}

		for (auto candidate : production.second)	//候选式
		{
			if (hasLeftRecursion)
			{
				if (candidate.front() == oldNonterminal)		//左递归
				{
					candidate.pop_front();	//去掉首元素
					candidate.push_back(newNonterminal);	//加上新的非终结符
					newCandidateSet.push_back(candidate);
					if (nonterminals[nonterminals.size()-1]!= newNonterminal)
						nonterminals.push_back(newNonterminal);
				}
				else
				{
					candidate.push_back(newNonterminal);
					oldCandidateSet.push_back(candidate);
				}
				newProductions[oldNonterminal] = oldCandidateSet;
			}
			else
			{
				newProductions[oldNonterminal] = productions[oldNonterminal];
			}
		}
		if (hasLeftRecursion)		//添加上ε
		{
			Candidate newCandidate;
			newCandidate.push_back("epsilon");
			newCandidateSet.push_back(newCandidate);
			newProductions[newNonterminal] = newCandidateSet;
		}
	}
	productions = newProductions;
}

void Parser::eliminateLeftCommonToken()
{
	for (auto production : productions)			//依次处理每个非终结符
	{
		if(isNonterminal(production.first))
			eliminateLeftCommonTokenOfN(production);
	}
	for (auto production : productions)			//新增非终结符
	{
		if (!isNonterminal(production.first))
			nonterminals.push_back(production.first);
	}
}

inline string Parser::candidate2String(Candidate c)
{
	string s="";
	for (auto token : c)
	{
		s += token;
	}
	return s;
}

void Parser::eliminateLeftCommonTokenOfN(pair<Nonterminal,vector<Candidate>> production)
{
	static int cnt = 1;
	map<string, vector<Candidate>>tmp;
	for (auto candidate : production.second)
	{
		string s = candidate.front();
		tmp[s].push_back(candidate);
	}
	map<string, vector<Candidate>> newTmp;
	for (auto r : tmp)
	{
		if (r.second.size() != 1)
			newTmp.insert(r);
	}
	tmp = newTmp;
	Nonterminal newNonterminal= production.first;
	for (auto token : tmp)			//token.first是终结符，token.second是vector<Candidate>
	{
		if (newNonterminal.size() > 2 && newNonterminal[newNonterminal.size() - 2] == '_')
			newNonterminal[newNonterminal.size() - 1] = '0' + (cnt++);
		else 
			newNonterminal = newNonterminal + "_"+to_string(cnt++);
		unordered_map<Nonterminal, vector<Candidate>>newProductions;
		string s;
		for (auto candidate : token.second)
		{
			Candidate newCandidate = candidate;
			s = newCandidate.front();
			newCandidate.pop_front();
			if (newCandidate.empty())
				newCandidate.push_back("epsilon");
			newProductions[newNonterminal].push_back(newCandidate);
		}
		productions[newNonterminal] = newProductions[newNonterminal];
		eliminateLeftCommonTokenOfN(make_pair(newNonterminal,productions[newNonterminal]));

		Candidate c;
		c.push_back(s);
		c.push_back(newNonterminal);
		productions[production.first].push_back(c);
		
		for (auto r : tmp)
		{
			for (auto candidate : r.second)
			{
				auto iter = remove(productions[production.first].begin(), productions[production.first].end(), candidate);
				productions[production.first].erase(iter, productions[production.first].end());
			}
		}
	}
}

void Parser::constructFirst()
{
	map<Nonterminal, bool>finished;		//记录某个非终结符的First集是否构造完毕

	for (auto nonteminal : nonterminals)	//初始化
		finished[nonteminal] = false;
	for (auto prodution : productions)
		firstSet[prodution.first].clear();

	for (auto prodution : productions)		//依次构造每个非终结符的FIRST集
		if(!finished[prodution.first])
			constructFirstOfN(prodution.first,&finished);
}

void Parser::constructFirstOfN(Nonterminal N,map<Nonterminal,bool> *finished)
{
	//已经完成非终结符N的构造
	if ((*finished)[N] == true)
		return;
	bool allEpsilon = true;
	for (auto candidate : productions[N])	//非终结符N的每个候选式
	{
		for (auto oneToken : candidate)
		{
			if (oneToken == "epsilon"||isTerminal(oneToken))	//oneToken是终结符或epsilon
			{
				firstSet[N].insert(oneToken);
				break;
			}
			else if (isNonterminal(oneToken))	//oneToken是非终结符
			{
				constructFirstOfN(oneToken,finished);		//先构造oneToken的FIRST集
				if (find(firstSet[oneToken].begin(), firstSet[oneToken].end(), "epsilon")
					!= firstSet[oneToken].end())	//epsilon存在于oneToken的FIRST集
				{
					unordered_set<string> tmp = firstSet[oneToken];
					tmp.erase("epsilon");
					for (auto r : tmp)
						firstSet[N].insert(r);
				}
				else
				{
					for(auto r : firstSet[oneToken])
						firstSet[N].insert(r);
					break;
				}
			}
		}
		for (auto oneToken : candidate)
		{
			if (find(firstSet[oneToken].begin(), firstSet[oneToken].end(), "epsilon")
				== firstSet[oneToken].end())		//epsilon不存在于oneToken的FIRST集
			{
				allEpsilon = false;
				break;
			}
		}
		if (allEpsilon == true)
		{
			firstSet[N].insert("epsilon");
		}
	}
	(*finished)[N] = true;
}

void Parser::printFirstSet()
{
	cout << "\n*********************************************************************************\n\n";
	cout.setf(std::ios::left);
	cout << "FIRST集:" << endl;
	for (auto nonterminal : nonterminals)
	{
		cout <<setw(NONTERMINAL_WIDTH)<< nonterminal << ": ";
		for (auto firstToken : firstSet[nonterminal])
		{
			cout << (firstToken=="epsilon"?"ε":firstToken) << ' ';
		}
		cout << endl;
	}
	cout << "\n*********************************************************************************\n\n";
}

void Parser::constructFollow()
{
	map<Nonterminal, bool>finished;			//标记非终结符的follow集是否构造完毕
	for (auto nonterminal : nonterminals)	//初始化
		finished[nonterminal] = false;
	for (auto nonterminal : nonterminals)
		followSet[nonterminal].clear();
	followSet[startSymbol].insert("$");		//将'$'加入到起始符的follow集中
	for (auto nonterminal : nonterminals)	//依次构造尚未构造完的非终结符的follow集
		if (!finished[nonterminal])
			constructFollowOfN(nonterminal, &finished,terminals[0]);
}

void Parser::constructFollowOfN(Nonterminal N,map<Nonterminal, bool>* finished,Nonterminal last)
{
	if ((*finished)[N] == true)							//如果已经构造完毕，则退出
		return;
	for (auto production : productions)					//遍历所有非终结符的产生式
	{
		for (auto candidate : production.second)		//遍历某个非终结符的候选式
		{
			for (auto iter = candidate.begin(); iter != candidate.end(); iter++)		//遍历候选式的每个符号
			{
				if (*iter == N)			//当前符号是所要构造的非终结符
				{
					auto nextIter = iter+1;				//记录下一个符号
					if (nextIter == candidate.end())	//没有下一个符号
					{
						//将产生式左边非终结符的follow集加入到当前所要构造的follow集中
						if (production.first != N)		
						{
							if(last != production.first)
								constructFollowOfN(production.first, finished,N);
							for (auto r : followSet[production.first])
							{
								if (r != "epsilon")		//epsilon不加入follow集
									followSet[*iter].insert(r);
							}
						}
					}
					else if (isTerminal(*nextIter))		//下一个符号是终结符
					{
						followSet[*iter].insert(*nextIter);		//插入下一个终结符到当前非终结符的follow集中
					}
					else if (isNonterminal(*nextIter))		//下一个符号是非终结符
					{
						//由于后面的符号可能推空，所以要遍历后面的每个符号
						auto curIter = nextIter;
						while (curIter!=candidate.end())
						{
							if (isNonterminal(*curIter))
							{
								for (auto r : firstSet[*curIter])
								{
									if (r != "epsilon")
										followSet[*iter].insert(r);
								}
							}
							else if (isTerminal(*curIter))
							{
								followSet[*iter].insert(*curIter);
							}
							if (count(firstSet[*curIter].begin(),
								firstSet[*curIter].end(), "epsilon"))		//当前能推空
							{
								curIter += 1;
								if (curIter == candidate.end())
								{
									if (last != production.first)
										constructFollowOfN(production.first, finished,N);
									for (auto r : followSet[production.first])
									{
										if (r != "epsilon")
											followSet[*iter].insert(r);
									}
								}
							}
							else break;
						}
					}
				}
			}
		}
	}
	(*finished)[N] == true;
}

void Parser::printFollowSet()
{
	cout << "\n*********************************************************************************\n\n";
	cout.setf(std::ios::left);
	cout << "FOLLOW集:" << endl;
	for (auto nonterminal : nonterminals)
	{
		cout <<setw(NONTERMINAL_WIDTH)<< nonterminal << ": ";
		for (auto firstToken : followSet[nonterminal])
		{
			cout << firstToken << ' ';
		}
		cout << endl;
	}
	cout << "\n*********************************************************************************\n\n";
}

unordered_set<string> Parser::getFirstOfCandidate(Candidate candidate)
{
	unordered_set<string> candidateFirst;	//候选式的first集
	for (auto token : candidate)
	{
		if (token == "epsilon" || isTerminal(token))		//是终结符
		{
			candidateFirst.insert(token);
			break;
		}
		else if (isNonterminal(token))
		{
			bool flag = false;		//标记token的first集中是否含空
			for (auto r : firstSet[token])
			{
				if (r == "epsilon")
					flag = true;
				else
					candidateFirst.insert(r);
			}
			if (!flag)		//不含空，不用分析下一个token了，退出循环
				break;
		}
	}
	return candidateFirst;
}

void Parser::constructTable()
{
	vector<Terminal>column = terminals;
	column.push_back("$");
	
	unordered_set<string> tmp;
	for (auto production : productions)
	{
		for (auto candidate : production.second)
		{
			tmp = getFirstOfCandidate(candidate);
			for (auto token : tmp)		//token是first集元素
			{
				if (token == "epsilon")
				{
					//将production.first的FOLLOW集加入	
					for (auto r : followSet[production.first])
					{
						pair<string, string>T(production.first, r);
						Candidate tmp;
						tmp.clear();
						tmp.push_back("epsilon");
						if (!table[T].empty())
							isLL1 = false;
						else table[T] = tmp;
					}
				}
				else
				{
					pair<string, string>T(production.first, token);
					if (!table[T].empty())
						isLL1 = false;
					else table[T] = candidate;
				}
			}
		}
	}

	for (auto nonterminal : nonterminals)
	{
		for (auto terminal : followSet[nonterminal])
		{
			pair<string, string>T(nonterminal, terminal);
			Candidate tmp;
			tmp.clear();
			tmp.push_back("SYNCH");
			if(table[T].empty())
				table[T] = tmp;
		}
	}
}

void Parser::printTable()
{
	cout << "\n*********************************************************************************\n\n";
	cout.setf(std::ios::left);
	vector<Terminal>column = terminals;
	column.push_back("$");
	cout<<setw(NONTERMINAL_WIDTH)<<" ";
	for (auto terminal : column)
		cout << setw(PRODUCTION_WIDTH) << terminal;
	cout << endl;
	for (auto nonterminal : nonterminals)
	{
		cout << setw(NONTERMINAL_WIDTH) << nonterminal;
		for (auto terminal : column)
		{
			pair<string, string>T(nonterminal, terminal);
			Candidate candidate = table[T];
			string s="";
			if(candidate.size()!=0&&candidate.front()!="SYNCH")
				s+= nonterminal+"->";
			for (auto token : candidate)
				if (token == "epsilon")
					s += "ε";
				else
					s += token;
			cout << setw(PRODUCTION_WIDTH) << s;
		}
		cout << endl;
	}
	cout << "\n*********************************************************************************\n\n";
}

void Parser::getInputString(deque<Token> inputString)
{
	this->inputString.clear();
	this->inputString = inputString;
}

inline void Parser::printStack()
{
	cout.setf(std::ios::left);
	stack<string>tmp = tokenStack;
	string s="";
	while (!tmp.empty())
	{
		s = tmp.top() + s;
		tmp.pop();
	}
	cout << setw(STACK_WIDTH)<<s;
}

inline void Parser::printInputString()
{
	string s="";
	for (auto token : inputString)
	{
		s+=token.str;
	}
	cout << setw(INPUT_STRING_WIDTH) << s;
}

void Parser::analysis()
{
	bool hasError = false;				//记录分析过程是否有错误
	Token t;
	t.str = "$";
	inputString.push_back(t);							//向输入串末尾添加'$'
	while (!tokenStack.empty())	tokenStack.pop();		//初始化栈
	tokenStack.push("$");
	tokenStack.push(startSymbol);

	cout.setf(std::ios::left);
	int cnt = 0;
	cout << setw(SEQUENCE_WIDTH) << ++cnt;
	printStack();
	printInputString();
	string output="";
	while (inputString.front().str != "$" || tokenStack.top() != "$")
	{
		output = "";
		if (tokenStack.top() == "num")			//栈顶符号为num
		{
			if (inputString.front().tokenType == NUMERIC_CONSTANTS)
			{
				inputString.pop_front();
				tokenStack.pop();
				output = "match";
				cout << output << endl;
			}
			else	//出错，弹出栈顶符号
			{
				string s = tokenStack.top();
				tokenStack.pop();
				output = "error: pop " + s;
				cout << output << endl;
				hasError = true;
			}
		}
		else if (tokenStack.top() == "id")		//栈顶符号为标识符
		{
			if (inputString.front().tokenType == IDENTIFIER)
			{
				inputString.pop_front();
				tokenStack.pop();
				output = "match";
				cout << output << endl;
			}
			else	//出错，弹出栈顶符号
			{
				string s = tokenStack.top();
				tokenStack.pop();
				output = "error: pop " + s;
				cout << output << endl;
				hasError = true;
			}
		}
		else if (inputString.front().str == tokenStack.top())	//终结符相匹配
		{
			inputString.pop_front();
			tokenStack.pop();
			output = "match";
			cout << output << endl;
		}
		else if (isTerminal(tokenStack.top()))
		{
			string s = tokenStack.top();
			tokenStack.pop();
			output = "error: pop " + s;
			cout << output << endl;
			hasError = true;
		}
		else
		{
			pair<string, string>T(tokenStack.top(), inputString.front().str);
			if (inputString.front().tokenType == IDENTIFIER)
				T = make_pair(tokenStack.top(), "id");
			if (inputString.front().tokenType == NUMERIC_CONSTANTS)
				T = make_pair(tokenStack.top(), "num");
			if (isTerminal(inputString.front().str))
				T = make_pair(tokenStack.top(), inputString.front().str);
			Candidate candidate = table[T];
			if (candidate.size() == 0)			//空
			{
				output = "error: skip " + inputString.front().str;
				inputString.pop_front();
				cout << output << endl;
				hasError = true;
			}
			else
			{
				if (candidate.front() == "SYNCH")	//同步信号
				{
					string s = tokenStack.top();
					tokenStack.pop();
					output = "synch: pop " + s;
					cout << output << endl;
					hasError = true;
				}
				else
				{
					string output = tokenStack.top() + "->";
					for (auto token : candidate)
					{
						if (token == "epsilon")
							token = "ε";
						output += token;
					}
					cout << output << endl;
					tokenStack.pop();
					for (auto iter = candidate.rbegin(); iter != candidate.rend(); iter++)
					{
						if (*iter != "epsilon" && *iter != "SYNCH")
							tokenStack.push(*iter);
					}
				}
			}
		}
		cout << setw(SEQUENCE_WIDTH) << ++cnt;
		printStack();
		printInputString();
	}

	

	if (tokenStack.top() == "$" && inputString.front().str == "$")
	{
		if (hasError)
			cout << "分析完毕，输入串不是该文法的句子\n";
		else
			cout << "接受\n";
	}
	else cout << "分析失败\n";

}

#include"Parser_LL.h"
#include"../arg.h"

#define GRAMMER_FILE "./Parser_LL/grammer.txt"

inline void trim(string& s)			//ȥ��һ���ַ�����β�Ŀո�
{
	if (!s.empty())
	{
		s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
	}
}

inline Candidate split(string s, char c)		//���ַ���s���ַ�c�ָ�õ����Ӵ�����һ��string���˫�˶���
{
	Candidate candidate;						
	string tmp;									//�����ݴ�ָ����ַ���
	stringstream input(s);						//���ַ���s��ʼ���ַ�����
	while (getline(input, tmp, c))			
		if (tmp.find_first_not_of(' ') != -1)	//tmpֻ�ɿո񹹳�ʱ��������candidate
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
	if (!fin.is_open())			//���ļ�ʧ��
	{
		cout << "���ļ�" << GRAMMER_FILE << "ʧ��\n�����ļ�����·���Ƿ���ȷ��\n";
		exit(1);
	}

	string s;
	string tmp;
	getline(fin, s);		//������1��
	getline(fin, s);		//��ȡ��2�з��ս��
	if (s == "")
		isEmpty = true;
	stringstream input(s);	//���ս�����ַ�����s��
	while (getline(input, tmp, ' '))	//�Կո���Ϊ�ֽ������s�ֳɶ���Ӵ���ÿ���Ӵ�����һ�����ս��
		if(tmp.find_first_not_of(' ') != -1)		//�Ӵ��������ֻ�ɿո���ɵĴ�
			nonterminals.push_back(tmp);
	
	getline(fin, s);		//������3��
	getline(fin, s);		//������4��
	getline(fin, s);		//��ȡ��5���ս��
	if (s == "")
		isEmpty = true;
	input = stringstream(s);
	while (getline(input, tmp, ' '))
		if (tmp.find_first_not_of(' ') != -1)
			terminals.push_back(tmp);

	getline(fin, s);		//������6��
	getline(fin, s);		//������7��
	getline(fin, s);		//��ȡ��8����ʼ��
	trim(s);
	if (s == "")
		isEmpty = true;
	startSymbol = s;

	getline(fin, s);		//������9��
	getline(fin, s);		//������10��
	while (getline(fin, s))	//��ȡ11���Ժ�Ĳ���ʽ
	{
		if (s == "")	//�����˿���
			continue;
		auto start = s.find_first_not_of(' ');		//�ҵ���һ����Ϊ�ո���ַ����Ӹ��ַ���ʼ����
		auto pos = s.substr(start).find(' ');		//�ҵ���һ����Ϊ�ո��ַ����һ��Ϊ�ո���ַ�
		Nonterminal a = s.substr(start,pos);		//����֮����ɲ���ʽ�����
		pos = s.substr(start).find("->");			
		string s1 = s.substr(start).substr(pos+2);	//�ҵ�����ʽ���ұ�
		input = stringstream(s1);	
		while (getline(input, tmp, '|'))			//��'|'��Ϊ�ָ��������������ʽ�ֿ�
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
	cout << "���ս��:" << endl;
	for (auto nonterminal : nonterminals)
		cout << nonterminal << ' ';
	cout << endl << endl;

	cout << "�ս��:" << endl;
	for (auto terminal : terminals)
		cout << terminal << '\t';
	cout << endl << endl;

	cout << "��ʼ��:" << endl;
	cout << startSymbol << endl << endl;

	cout << "����ʽ:" << endl;
	for (auto production : productions)
	{
		for (auto candidate : production.second)
		{
			cout << setw(NONTERMINAL_WIDTH)<<production.first << "-> ";
			for (auto oneToken : candidate)
			{
				cout << (oneToken == "epsilon" ? "��" : oneToken) << ' ';
			}
			cout << endl;
		}
	}
	cout << "\n*********************************************************************************\n\n";
}

void Parser::eliminateLeftRecursion()
{
	unordered_map<Nonterminal, vector<Candidate>>newProductions;		//�µĲ���ʽ��
	for (auto production : productions)		//��ÿ�����ս�������к�ѡʽ
	{
		string oldNonterminal = production.first;		//ԭ�ս��
		string newNonterminal = oldNonterminal + "'";	//���ս��
		vector<Candidate>newCandidateSet;	//�·��ս���ĺ�ѡʽ����
		vector<Candidate>oldCandidateSet;	//ԭ���ս���ĺ�ѡʽ����

		//�ж��Ƿ�����ݹ�
		bool hasLeftRecursion = false;		
		for (auto candidate : production.second)	
		{
			if (candidate.front() == oldNonterminal)
				hasLeftRecursion = true;
		}

		for (auto candidate : production.second)	//��ѡʽ
		{
			if (hasLeftRecursion)
			{
				if (candidate.front() == oldNonterminal)		//��ݹ�
				{
					candidate.pop_front();	//ȥ����Ԫ��
					candidate.push_back(newNonterminal);	//�����µķ��ս��
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
		if (hasLeftRecursion)		//����Ϧ�
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
	for (auto production : productions)			//���δ���ÿ�����ս��
	{
		if(isNonterminal(production.first))
			eliminateLeftCommonTokenOfN(production);
	}
	for (auto production : productions)			//�������ս��
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
	for (auto token : tmp)			//token.first���ս����token.second��vector<Candidate>
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
	map<Nonterminal, bool>finished;		//��¼ĳ�����ս����First���Ƿ������

	for (auto nonteminal : nonterminals)	//��ʼ��
		finished[nonteminal] = false;
	for (auto prodution : productions)
		firstSet[prodution.first].clear();

	for (auto prodution : productions)		//���ι���ÿ�����ս����FIRST��
		if(!finished[prodution.first])
			constructFirstOfN(prodution.first,&finished);
}

void Parser::constructFirstOfN(Nonterminal N,map<Nonterminal,bool> *finished)
{
	//�Ѿ���ɷ��ս��N�Ĺ���
	if ((*finished)[N] == true)
		return;
	bool allEpsilon = true;
	for (auto candidate : productions[N])	//���ս��N��ÿ����ѡʽ
	{
		for (auto oneToken : candidate)
		{
			if (oneToken == "epsilon"||isTerminal(oneToken))	//oneToken���ս����epsilon
			{
				firstSet[N].insert(oneToken);
				break;
			}
			else if (isNonterminal(oneToken))	//oneToken�Ƿ��ս��
			{
				constructFirstOfN(oneToken,finished);		//�ȹ���oneToken��FIRST��
				if (find(firstSet[oneToken].begin(), firstSet[oneToken].end(), "epsilon")
					!= firstSet[oneToken].end())	//epsilon������oneToken��FIRST��
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
				== firstSet[oneToken].end())		//epsilon��������oneToken��FIRST��
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
	cout << "FIRST��:" << endl;
	for (auto nonterminal : nonterminals)
	{
		cout <<setw(NONTERMINAL_WIDTH)<< nonterminal << ": ";
		for (auto firstToken : firstSet[nonterminal])
		{
			cout << (firstToken=="epsilon"?"��":firstToken) << ' ';
		}
		cout << endl;
	}
	cout << "\n*********************************************************************************\n\n";
}

void Parser::constructFollow()
{
	map<Nonterminal, bool>finished;			//��Ƿ��ս����follow���Ƿ������
	for (auto nonterminal : nonterminals)	//��ʼ��
		finished[nonterminal] = false;
	for (auto nonterminal : nonterminals)
		followSet[nonterminal].clear();
	followSet[startSymbol].insert("$");		//��'$'���뵽��ʼ����follow����
	for (auto nonterminal : nonterminals)	//���ι�����δ������ķ��ս����follow��
		if (!finished[nonterminal])
			constructFollowOfN(nonterminal, &finished,terminals[0]);
}

void Parser::constructFollowOfN(Nonterminal N,map<Nonterminal, bool>* finished,Nonterminal last)
{
	if ((*finished)[N] == true)							//����Ѿ�������ϣ����˳�
		return;
	for (auto production : productions)					//�������з��ս���Ĳ���ʽ
	{
		for (auto candidate : production.second)		//����ĳ�����ս���ĺ�ѡʽ
		{
			for (auto iter = candidate.begin(); iter != candidate.end(); iter++)		//������ѡʽ��ÿ������
			{
				if (*iter == N)			//��ǰ��������Ҫ����ķ��ս��
				{
					auto nextIter = iter+1;				//��¼��һ������
					if (nextIter == candidate.end())	//û����һ������
					{
						//������ʽ��߷��ս����follow�����뵽��ǰ��Ҫ�����follow����
						if (production.first != N)		
						{
							if(last != production.first)
								constructFollowOfN(production.first, finished,N);
							for (auto r : followSet[production.first])
							{
								if (r != "epsilon")		//epsilon������follow��
									followSet[*iter].insert(r);
							}
						}
					}
					else if (isTerminal(*nextIter))		//��һ���������ս��
					{
						followSet[*iter].insert(*nextIter);		//������һ���ս������ǰ���ս����follow����
					}
					else if (isNonterminal(*nextIter))		//��һ�������Ƿ��ս��
					{
						//���ں���ķ��ſ����ƿգ�����Ҫ���������ÿ������
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
								firstSet[*curIter].end(), "epsilon"))		//��ǰ���ƿ�
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
	cout << "FOLLOW��:" << endl;
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
	unordered_set<string> candidateFirst;	//��ѡʽ��first��
	for (auto token : candidate)
	{
		if (token == "epsilon" || isTerminal(token))		//���ս��
		{
			candidateFirst.insert(token);
			break;
		}
		else if (isNonterminal(token))
		{
			bool flag = false;		//���token��first�����Ƿ񺬿�
			for (auto r : firstSet[token])
			{
				if (r == "epsilon")
					flag = true;
				else
					candidateFirst.insert(r);
			}
			if (!flag)		//�����գ����÷�����һ��token�ˣ��˳�ѭ��
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
			for (auto token : tmp)		//token��first��Ԫ��
			{
				if (token == "epsilon")
				{
					//��production.first��FOLLOW������	
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
					s += "��";
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
	bool hasError = false;				//��¼���������Ƿ��д���
	Token t;
	t.str = "$";
	inputString.push_back(t);							//�����봮ĩβ���'$'
	while (!tokenStack.empty())	tokenStack.pop();		//��ʼ��ջ
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
		if (tokenStack.top() == "num")			//ջ������Ϊnum
		{
			if (inputString.front().tokenType == NUMERIC_CONSTANTS)
			{
				inputString.pop_front();
				tokenStack.pop();
				output = "match";
				cout << output << endl;
			}
			else	//��������ջ������
			{
				string s = tokenStack.top();
				tokenStack.pop();
				output = "error: pop " + s;
				cout << output << endl;
				hasError = true;
			}
		}
		else if (tokenStack.top() == "id")		//ջ������Ϊ��ʶ��
		{
			if (inputString.front().tokenType == IDENTIFIER)
			{
				inputString.pop_front();
				tokenStack.pop();
				output = "match";
				cout << output << endl;
			}
			else	//��������ջ������
			{
				string s = tokenStack.top();
				tokenStack.pop();
				output = "error: pop " + s;
				cout << output << endl;
				hasError = true;
			}
		}
		else if (inputString.front().str == tokenStack.top())	//�ս����ƥ��
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
			if (candidate.size() == 0)			//��
			{
				output = "error: skip " + inputString.front().str;
				inputString.pop_front();
				cout << output << endl;
				hasError = true;
			}
			else
			{
				if (candidate.front() == "SYNCH")	//ͬ���ź�
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
							token = "��";
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
			cout << "������ϣ����봮���Ǹ��ķ��ľ���\n";
		else
			cout << "����\n";
	}
	else cout << "����ʧ��\n";

}

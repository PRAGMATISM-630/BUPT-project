#include"Lexer/Lexer.h"
#include"Parser_LL/Parser_LL.h"

int main()
{
	Lexer lexer;
	lexer.scan();		//词法分析器扫描程序
	deque<Token>inputString = lexer.getInputString();	//对输入串进行词法分析得到输入流

	Parser parser;
	parser.getGrammer();					//读取文法
	if (parser.getIsEmpty())				//该文法为空文法
	{
		cout << "该文法为空文法" << endl;
		return 0;
	}

	parser.eliminateLeftRecursion();		//消左递归
	parser.eliminateLeftCommonToken();		//消公共公因子
	parser.printGrammer();					//输出等价处理后的文法

	parser.constructFirst();				//构造FIRST集
	parser.constructFollow();				//构造FOLLOW集
	parser.printFirstSet();					//输出FIRST集
	parser.printFollowSet();				//输出FOLLOW集

	parser.constructTable();				//构造预测分析表
	bool isLL1 = parser.getIsLL1();			//判断是否为LL(1)文法

	if (isLL1)								//是LL(1)文法
	{
		parser.printTable();				//打印预测分析表
		parser.getInputString(inputString);	//获取输入串
		parser.analysis();					//进行分析
	}
	else
		cout << "该文法不是LL(1)文法" << endl;

	return 0;
}
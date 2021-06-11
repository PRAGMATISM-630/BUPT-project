#include"Parser_LR.h"
#include"Lexer.h"

int main()
{
	Lexer lexer;
	lexer.scan();		//词法分析器扫描程序
	deque<Token>inputString = lexer.getInputString();	//对输入串进行词法分析得到输入流

	Parser parser;
	parser.getGrammer();
	parser.extendGrammer();
	//parser.printGrammer();
	//parser.construct();
	parser.constructTable();
	parser.printTable();
	parser.analyze(inputString);
}
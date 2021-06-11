#include"Parser_LR.h"
#include"Lexer.h"

int main()
{
	Lexer lexer;
	lexer.scan();		//�ʷ�������ɨ�����
	deque<Token>inputString = lexer.getInputString();	//�����봮���дʷ������õ�������

	Parser parser;
	parser.getGrammer();
	parser.extendGrammer();
	//parser.printGrammer();
	//parser.construct();
	parser.constructTable();
	parser.printTable();
	parser.analyze(inputString);
}
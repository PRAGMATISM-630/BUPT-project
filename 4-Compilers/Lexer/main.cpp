#include<iostream>
#include"Lexer.h"

int main()
{
	Lexer lexer;
	lexer.scan();
	lexer.printInfo();
	lexer.printTokenStream();
	lexer.printErrorStream();
	lexer.printSymbolTable();
}



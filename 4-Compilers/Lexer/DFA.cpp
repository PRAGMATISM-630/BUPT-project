#include"DFA.h"

inline void DFA::setArg(int s,bool p,TokenType t)
{
	state = s;
	putbackFlag = p;
	tokenType = t;
}

bool DFA::transition(char ch,bool &eol)
{
	eol = false;	//标记行尾
	switch (state)
	{
	case 0://初始状态
		if (isalpha(ch) || ch == '_')	//字母或下划线
		{
			setArg(1, false, IDENTIFIER);
			return false;
		}
		if (ch == '+')
		{
			setArg(2, false, UNKNOWN);
			return false;
		}
		if (ch == '-')
		{
			setArg(3, false, UNKNOWN);
			return false;
		}
		if (ch == '*')
		{
			setArg(4, false, UNKNOWN);
			return false;
		}
		if (ch == '/')
		{
			setArg(5, false, UNKNOWN);
			return false;
		}
		if (ch == '%')
		{
			setArg(9, false, UNKNOWN);
			return false;
		}
		if (ch == '=')
		{
			setArg(10, false, UNKNOWN);
			return false;
		}
		if (ch == '&')
		{
			setArg(11, false, UNKNOWN);
			return false;
		}
		if (ch == '|')
		{
			setArg(12, false, UNKNOWN);
			return false;
		}
		if (ch == '^')
		{
			setArg(13, false, UNKNOWN);
			return false;
		}
		if (ch == '<')
		{
			setArg(14, false, UNKNOWN);
			return false;
		}
		if (ch == '>')
		{
			setArg(16, false, UNKNOWN);
			return false;
		}
		if (ch == '!')
		{
			setArg(18, false, UNKNOWN);
			return false;
		}
		if (ch == '~')
		{
			setArg(0, false, BIT_NOT);
			return true;
		}
		if (ch == '.')
		{
			setArg(0, false, DOT);
			return true;
		}
		if (ch == '(')
		{
			setArg(0, false, L_PARENTHESIS);
			return true;
		}
		if (ch == ')')
		{
			setArg(0, false, R_PARENTHESIS);
			return true;
		}
		if (ch == '[')
		{
			setArg(0, false, L_BRACKET);
			return true;
		}
		if (ch == ']')
		{
			setArg(0, false, R_BRACKET);
			return true;
		}
		if (ch == '{')
		{
			setArg(0, false, L_BRACE);
			return true;
		}
		if (ch == '}')
		{
			setArg(0, false, R_BRACE);
			return true;
		}
		if (ch == ';')
		{
			setArg(0, false, SEMICOLON);
			return true;
		}
		if (ch == ':')
		{
			setArg(0, false, COLON);
			return true;
		}
		if (ch == ',')
		{
			setArg(0, false, COMMA);
			return true;
		}
		if (ch == '?')
		{
			setArg(0, false, QUESTION);
			return true;
		}
		if (isdigit(ch))	//数字
		{
			setArg(19, false, NUMERIC_CONSTANTS);
			return false;
		}
		if (ch == '#')		//预处理命令
		{
			setArg(25, false, PREPROCESSOR);
			return false;
		}
		if (ch == '\'')		//字符常量
		{
			setArg(26, false, CHAR_CONSTANTS);
			return false;
		}
		if (ch == '\"')		//字符串字面量
		{
			setArg(29, false, STRING_LITERAL);			
			return false;
		}
		else				//非法符号处理
		{
			setArg(0, false, ILLEGAL_CHAR);
			return true;
		}


	case 1:	//字母或下划线
		if (isalnum(ch) || ch == '_')
		{
			setArg(1, false, IDENTIFIER);
			return false;
		}
		else
		{
			setArg(0, true, IDENTIFIER);
			return true;		//识别出标识符
		}

	case 2:	// +
		if (ch == '=')	// +=
		{
			setArg(0, false, ADD_ASSIGN);
			return true;
		}
		else if (ch == '+')	// ++
		{
			setArg(0, false, INC);
			return true;
		}
		else
		{
			setArg(0, true, ADD);
			return true;
		}

	case 3:	// -
		if (ch == '=')	// -=
		{
			setArg(0, false, SUB_ASSIGN);
			return true;
		}
		else if (ch == '-')		// --
		{
			setArg(0, false, DEC);
			return true;
		}
		else if (ch == '>')		// ->
		{
			setArg(0, false, ARROW);
			return true;
		}
		else
		{
			setArg(0, true, SUB);
			return true;
		}

	case 4:	// *
		if (ch == '=')		// *=
		{
			setArg(0, false, MUL_ASSIGN);
			return true;
		}
		else
		{
			setArg(0, true, MUL);
			return true;
		}

	case 5:	//	/
		if (ch == '=')			//	/=
		{
			setArg(0, false, DIV_ASSIGN);
			return true;
		}
		else if (ch == '/')		//行注释
		{
			setArg(6, false, LINE_COMMENT);
			return false;
		}
		else if (ch == '*')		//块注释
		{
			setArg(7, false, BLOCK_COMMENT);
			return false;
		}
		else
		{
			setArg(0, true, DIV);
			return true;
		}

	case 6:
		if (ch == '\n')
		{
			setArg(0, false, LINE_COMMENT);
			return true;
		}
		else
		{
			setArg(6, false, LINE_COMMENT);
			return false;
		}

	case 7:
		if (ch == '*')
		{
			setArg(8, false, BLOCK_COMMENT);
			return false;
		}
		else
		{
			if (ch == '\n')
				eol = true;
			setArg(7, false, BLOCK_COMMENT);
			return false;
		}

	case 8:
		if (ch == '*')
		{
			setArg(8, false, BLOCK_COMMENT);
			return false;
		}
		else if (ch == '/')
		{
			setArg(0, false, BLOCK_COMMENT);
			return true;
		}
		else
		{
			if (ch == '\n')
				eol = true;
			setArg(7, false, BLOCK_COMMENT);
			return false;
		}

	case 9:	// %
		if (ch == '=')
		{
			setArg(0, false, MOD_ASSIGN);
			return true;
		}
		else
		{
			setArg(0, true, MOD);
			return true;
		}

	case 10:	// =
		if (ch == '=')
		{
			setArg(0, false, EQUAL);
			return true;
		}
		else
		{
			setArg(0, true, ASSIGN);
			return true;
		}

	case 11:	// &
		if (ch == '=')	// &=
		{
			setArg(0, false, BIT_AND_ASSIGN);
			return true;
		}
		else if (ch == '&')	// &&
		{
			setArg(0, false, AND);
			return true;
		}
		else
		{
			setArg(0, true, BIT_AND);
			return true;
		}

	case 12:	// |
		if (ch == '=')	// |=
		{
			setArg(0, false, BIT_OR_ASSIGN);
			return true;
		}
		else if (ch == '|')	// ||
		{
			setArg(0, false, OR);
			return true;
		}
		else
		{
			setArg(0, true, BIT_OR);
			return true;
		}

	case 13:	// ^
		if (ch == '=')	// ^=
		{
			setArg(0, false, BIT_XOR_ASSIGN);
			return true;
		}
		else
		{
			setArg(0, true, BIT_XOR);
			return true;
		}

	case 14:	// <
		if (ch == '<')	// <<
		{
			setArg(15, false, UNKNOWN);
			return false;
		}
		else if (ch == '=')	// <=
		{
			setArg(0, false, LESS_EQUAL);
			return true;
		}
		else
		{
			setArg(0, true, LESS);
			return true;
		}

	case 15:	// <<
		if (ch == '=')	// <<=
		{
			setArg(0, false, SHL_ASSIGN);
			return true;
		}
		else
		{
			setArg(0, true, SHL);
			return true;
		}

	case 16:	// >
		if (ch == '>')	// >>
		{
			setArg(17, false, UNKNOWN);
			return false;
		}
		else if (ch == '=')	// >=
		{
			setArg(0, false, GREATER_EQUAL);
			return true;
		}
		else
		{
			setArg(0, true, GREATER);
			return true;
		}

	case 17:	// >>
		if (ch == '=')	// >>=
		{
			setArg(0, false, SHR_ASSIGN);
			return true;
		}
		else
		{
			setArg(0, true, SHR);
			return true;
		}

	case 18:	// !
		if (ch == '=')	// !=
		{
			setArg(0, false, NOT_EQUAL);
			return true;
		}
		else
		{
			setArg(0, true, NOT);
			return true;
		}

	case 19:
		if (isdigit(ch))
		{
			setArg(19, false, NUMERIC_CONSTANTS);
			return false;
		}
		else if (ch == '.')
		{
			setArg(20, false, NUMERIC_CONSTANTS);
			return false;
		}
		else if (ch == 'E' || ch == 'e')
		{
			setArg(22, false, NUMERIC_CONSTANTS);
			return false;
		}
		else
		{
			setArg(0, true, NUMERIC_CONSTANTS);
			return true;
		}

	case 20:
		if (isdigit(ch))
		{
			setArg(21, false, NUMERIC_CONSTANTS);
			return false;
		}
		else if (ch == '\n')
		{
			eol = true;		//到达行尾，数字不完整
			setArg(0, true, NUMERIC_ERROR);
			return true;
		}
		else
		{
			setArg(0, true, NUMERIC_ERROR);
			return true;
		}

	case 21:
		if (isdigit(ch))
		{
			setArg(21, false, NUMERIC_CONSTANTS);
			return false;
		}
		else if (ch == 'E' || ch == 'e')
		{
			setArg(22, false, NUMERIC_CONSTANTS);
			return false;
		}
		else
		{
			setArg(0, true, NUMERIC_CONSTANTS);
			return true;
		}

	case 22:
		if (isdigit(ch))
		{
			setArg(24, false, NUMERIC_CONSTANTS);
			return false;
		}
		else if (ch == '+' || ch == '-')
		{
			setArg(23, false, NUMERIC_CONSTANTS);
			return false;
		}
		else if (ch == '\n')
		{
			eol = true;		//到达行尾，数字不完整
			setArg(0, true, NUMERIC_ERROR);
			return true;
		}
		else
		{
			setArg(0, true, NUMERIC_ERROR);
			return true;
		}

	case 23:
		if (isdigit(ch))
		{
			setArg(24, false, NUMERIC_CONSTANTS);
			return false;
		}
		else if (ch == '\n')
		{
			eol = true;		//到达行尾，数字不完整
			setArg(0, true, NUMERIC_ERROR);
			return true;
		}
		else
		{
			setArg(0, true, NUMERIC_ERROR);
			return true;
		}

	case 24:
		if (isdigit(ch))
		{
			setArg(24, false, NUMERIC_CONSTANTS);
			return false;
		}
		else
		{
			setArg(0, true, NUMERIC_CONSTANTS);
			return true;
		}

	case 25:
		if (ch == '\n')
		{
			setArg(0, false, PREPROCESSOR);
			return true;
		}
		else
		{
			setArg(25, false, PREPROCESSOR);
			return false;
		}


	case 26:
		if (ch == '\\')
		{
			setArg(27, false, CHAR_CONSTANTS);
			return false;
		}
		else if (ch == '\'')
		{
			setArg(0, false, CHAR_CONSTANTS);
			return true;
		}
		else if (ch == '\n')
		{
			eol = true;
			setArg(0,false, CHAR_ERROR);
			return true;
		}
		else
		{
			setArg(28, false, CHAR_CONSTANTS);
			return false;
		}

	case 27:
		if (ch == 'a' || ch == 'b' || ch == 'f' || ch == 'n' || ch == 'r'
			|| ch == 't' || ch == 'v' || ch == '\'' || ch == '\"'
			|| ch == '\\' || ch == '0')
		{
			setArg(28, false, CHAR_CONSTANTS);
			return false;
		}
		else
		{
			if(ch=='\n')
				eol = true;		//到达行尾，缺失右引号
			setArg(0, true, CHAR_ERROR);
			return true;
		}


	case 28:
		if (ch == '\'')
		{
			setArg(0, false, CHAR_CONSTANTS);
			return true;
		}
		else
		{
			if (ch == '\n')
				eol = true;		//到达行尾，缺失右引号
			setArg(0, true, CHAR_ERROR);
			return true;
		}

	case 29:
		if (ch == '\"')
		{
			setArg(0, false, STRING_LITERAL);
			return true;
		}
		else if (ch == '\\')
		{
			setArg(30, false, STRING_LITERAL);
			return false;
		}
		else if (ch == '\n')
		{
			eol = true;		//到达行尾，缺失右引号
			setArg(0, false, STRING_ERROR);
			return true;
		}
		else
		{
			setArg(29, false, STRING_LITERAL);
			return false;
		}

	case 30:
		if (ch == '\n')
		{
			eol = true;		//到达行尾，缺失右引号
			setArg(0, false, STRING_ERROR);
			return true;
		}
		else
		{
			setArg(29, false, STRING_LITERAL);
			return false;
		}

	}
}
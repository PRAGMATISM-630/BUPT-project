#include"Lexer/Lexer.h"
#include"Parser_LL/Parser_LL.h"

int main()
{
	Lexer lexer;
	lexer.scan();		//�ʷ�������ɨ�����
	deque<Token>inputString = lexer.getInputString();	//�����봮���дʷ������õ�������

	Parser parser;
	parser.getGrammer();					//��ȡ�ķ�
	if (parser.getIsEmpty())				//���ķ�Ϊ���ķ�
	{
		cout << "���ķ�Ϊ���ķ�" << endl;
		return 0;
	}

	parser.eliminateLeftRecursion();		//����ݹ�
	parser.eliminateLeftCommonToken();		//������������
	parser.printGrammer();					//����ȼ۴������ķ�

	parser.constructFirst();				//����FIRST��
	parser.constructFollow();				//����FOLLOW��
	parser.printFirstSet();					//���FIRST��
	parser.printFollowSet();				//���FOLLOW��

	parser.constructTable();				//����Ԥ�������
	bool isLL1 = parser.getIsLL1();			//�ж��Ƿ�ΪLL(1)�ķ�

	if (isLL1)								//��LL(1)�ķ�
	{
		parser.printTable();				//��ӡԤ�������
		parser.getInputString(inputString);	//��ȡ���봮
		parser.analysis();					//���з���
	}
	else
		cout << "���ķ�����LL(1)�ķ�" << endl;

	return 0;
}
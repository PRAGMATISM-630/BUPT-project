#include"head.h"
using std::cin;
using std::cout;
using std::endl;

const int lines = 4;
const int rows = 5;

int main()
{
	//������������ A1 �� A2 �� A3
	Matrix A1(lines, rows);
	Matrix A2(lines, rows);
	Matrix A3(lines, rows);

	//��ʼ�� A1 �� A2
	cout << "���������A1:" << endl;
	cin >> A1;
	cout << "���������A2:" << endl;
	cin >> A2;

	//���㲢���A3 = A1 ��A2��A3 = A1 ��A2
	A3 = A1 + A2;
	cout << "\nA1+A2=\n" << A3;
	A3 = A1 - A2;
	cout << "\nA1-A2=\n" << A3;

	//�� new ��̬��������������Ķ��� pA1 �� pA1 �� pA3
	Matrix* pA1 = new Matrix(lines, rows);
	Matrix* pA2 = new Matrix(lines, rows);
	Matrix* pA3 = new Matrix(lines, rows);

	//��ʼ��pA1,pA2
	cout << "���������pA1:" << endl;
	cin >> *pA1;
	cout << "���������pA2:" << endl;
	cin >> *pA2;

	//���㲢��� pA3=pA1 �� pA2,pA3=pA1 �� pA2
	*pA3 = *pA1 + *pA2;
	cout << "\n*pA1+*pA2=\n" << *pA3;
	*pA3 = *pA1 - *pA2;
	cout << "\n*pA1-*pA2=\n" << *pA3;


	//�ͷ� pA1 ��pA2 ��pA3
	delete pA1;
	delete pA2;
	delete pA3;

	return 0;
}
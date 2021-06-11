#include"head.h"
using std::cin;
using std::cout;
using std::endl;

const int lines = 4;
const int rows = 5;

int main()
{
	//定义三个矩阵： A1 、 A2 、 A3
	Matrix A1(lines, rows);
	Matrix A2(lines, rows);
	Matrix A3(lines, rows);

	//初始化 A1 、 A2
	cout << "请输入矩阵A1:" << endl;
	cin >> A1;
	cout << "请输入矩阵A2:" << endl;
	cin >> A2;

	//计算并输出A3 = A1 加A2，A3 = A1 减A2
	A3 = A1 + A2;
	cout << "\nA1+A2=\n" << A3;
	A3 = A1 - A2;
	cout << "\nA1-A2=\n" << A3;

	//用 new 动态创建三个矩阵类的对象： pA1 、 pA1 、 pA3
	Matrix* pA1 = new Matrix(lines, rows);
	Matrix* pA2 = new Matrix(lines, rows);
	Matrix* pA3 = new Matrix(lines, rows);

	//初始化pA1,pA2
	cout << "请输入矩阵pA1:" << endl;
	cin >> *pA1;
	cout << "请输入矩阵pA2:" << endl;
	cin >> *pA2;

	//计算并输出 pA3=pA1 加 pA2,pA3=pA1 减 pA2
	*pA3 = *pA1 + *pA2;
	cout << "\n*pA1+*pA2=\n" << *pA3;
	*pA3 = *pA1 - *pA2;
	cout << "\n*pA1-*pA2=\n" << *pA3;


	//释放 pA1 、pA2 、pA3
	delete pA1;
	delete pA2;
	delete pA3;

	return 0;
}
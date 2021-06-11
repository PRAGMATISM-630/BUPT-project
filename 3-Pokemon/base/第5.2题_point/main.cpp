#include"head.h"

using namespace std;

int main()
{
	//使用默认构造函数，P1=(0,0)
	cout << "使用默认构造函数，P1=(0,0)\n";
	Point P1;
	cout << "P1= " << P1 << endl;
	cout << "++P1= " << ++P1 << endl;
	cout << "P1++=" << P1++ << endl;
	cout << "P1= " << P1 << endl << endl;

	cout << "请输入两个整数，代表点P2的横纵坐标" << endl;
	int x, y;
	cin >> x >> y;
	Point P2(x, y);
	cout << "P2= " << P2 << endl;
	cout << "--P2= " << --P2 << endl;
	cout << "P2--=" << P2-- << endl;
	cout << "P2= " << P2 << endl;

	cout << "使用拷贝构造函数，使得P3=P1" << endl;
	Point P3 = P1;
	cout << "P3= " << P3 << endl << endl;

}


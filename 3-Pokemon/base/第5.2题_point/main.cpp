#include"head.h"

using namespace std;

int main()
{
	//ʹ��Ĭ�Ϲ��캯����P1=(0,0)
	cout << "ʹ��Ĭ�Ϲ��캯����P1=(0,0)\n";
	Point P1;
	cout << "P1= " << P1 << endl;
	cout << "++P1= " << ++P1 << endl;
	cout << "P1++=" << P1++ << endl;
	cout << "P1= " << P1 << endl << endl;

	cout << "���������������������P2�ĺ�������" << endl;
	int x, y;
	cin >> x >> y;
	Point P2(x, y);
	cout << "P2= " << P2 << endl;
	cout << "--P2= " << --P2 << endl;
	cout << "P2--=" << P2-- << endl;
	cout << "P2= " << P2 << endl;

	cout << "ʹ�ÿ������캯����ʹ��P3=P1" << endl;
	Point P3 = P1;
	cout << "P3= " << P3 << endl << endl;

}


#include<iostream>
#include"shape.h"

using namespace std;

int main()
{
	double area = 0;

	Rectangle rect(4, 5);	
	area = rect.Get_area_Rect();
	cout << "��Ϊ4����Ϊ5�ľ������Ϊ: " << area << endl << endl;

	Circle cir(2);
	area = cir.Get_area_Cir();
	cout << "�뾶Ϊ2��Բ�����Ϊ: " << area << endl << endl;

	Square squa(6);
	area = squa.Get_area_Squa();
	cout << "�߳�Ϊ6�������ε����Ϊ: " << area << endl << endl;
}


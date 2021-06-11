#include<iostream>
#include"shape.h"

using namespace std;

int main()
{
	double area = 0;

	Rectangle rect(4, 5);	
	area = rect.Get_area_Rect();
	cout << "宽为4，高为5的矩形面积为: " << area << endl << endl;

	Circle cir(2);
	area = cir.Get_area_Cir();
	cout << "半径为2的圆形面积为: " << area << endl << endl;

	Square squa(6);
	area = squa.Get_area_Squa();
	cout << "边长为6的正方形的面积为: " << area << endl << endl;
}


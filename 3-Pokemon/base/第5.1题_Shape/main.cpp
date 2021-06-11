#include<iostream>
#include"shape.h"

using namespace std;

int main()
{
	Shape* ptr = nullptr;
	double area = 0;

	cout << "请输入两个正整数，分别为矩形的宽和高" << endl;
	int width, height;
	cin >> width >> height;
	Rectangle rect(width, height);
	ptr = &rect;
	area = ptr->Get_area();
	cout << "宽为"<<width<<"，高为"<<height<<"的矩形面积为: " << area << endl << endl;

	cout << "请输入一个正整数，表示圆的半径" << endl;
	int radius;
	cin >> radius;
	Circle cir(radius);
	ptr = &cir;
	area = ptr->Get_area();
	cout << "半径为"<<radius<<"的圆形面积为: " << area << endl << endl;

	cout<< "请输入一个正整数，表示正方形的边长" << endl;
	cin >> width;
	Square squa(width);
	ptr = &squa;
	area = ptr->Get_area();
	cout << "边长为"<<width<<"的正方形的面积为: " << area << endl << endl;

	Rectangle rect2(squa);
	ptr = &rect2;
	area = ptr->Get_area();
	cout << "以矩形的面积计算方法(宽*高），边长为"<<width<<"的正方形的面积为: " << area << endl << endl;

	//以正方形类为例查看关于复制构造函数的调用，其它类由于过程类似故省略
	Square squa2(squa);
	ptr = &squa;
	area = ptr->Get_area();
	cout << "边长为" << width << "的正方形的面积为: " << area << endl << endl;
}

/*
该程序的输出结果如下：

基类构造函数										->先调用基类构造函数
矩形类构造函数									->再调用派生类构造函数
宽为4，高为5的矩形面积为: 20

基类构造函数
圆形类构造函数
半径为2的圆形面积为: 12.56

基类构造函数
矩形类构造函数
正方形类构造函数
边长为6的正方形的面积为: 36

基类构造函数										->这里使用派生类对象初始化基类对象
矩形类复制构造函数								->调用了派生类复制构造函数
以长方形的面积计算方法（宽*高），边长为6的正方形的面积为: 36

基类构造函数
矩形类复制构造函数
正方形类复制构造函数
边长为6的正方形的面积为: 36

正方形类析构函数									->析构函数的调用顺序与构造函数、复制构造函数恰好相反
矩形类析构函数									->即先构造的后析构，后构造的先析构
基类析构函数
矩形类析构函数
基类析构函数
正方形类析构函数
矩形类析构函数
基类析构函数
圆形类析构函数
基类析构函数
矩形类析构函数
基类析构函数




*/

#include<iostream>
#include"head.h"
using namespace std;

Circle::Circle(const Point &P, double r = 0) :center(P), radius(r)
{
	cout << "Circle构造函数" << endl;
}

Circle::~Circle()
{
	cout << "Circle析构函数" << endl;
}

void Circle::Intersect(const Circle& C)const
{
	double dis = center.Getdistance(C.center);		//圆心间距

	cout << endl;
	if (dis<radius + C.radius
		&& dis>(radius > C.radius ? (radius - C.radius) : (C.radius - radius)))
		cout << "两圆相交" << endl;
	else cout << "两圆不相交" << endl;
	cout << endl;
	
}
#include<iostream>
#include"head.h"
using namespace std;

Point::Point()
{
	x = 0;
	y = 0;
	cout << "Point���캯��" << endl;
}

Point::Point(double x = 0, double y = 0)
{
	this->x = x;
	this->y = y;
	cout << "Point���캯��" << endl;
}

Point::~Point()
{
	cout << "Point��������" << endl;
}

Point::Point(const Point& P)
{
	x = P.x;
	y = P.y;
	cout << "Point�������캯��" << endl;
}

double Point::Getdistance(const Point& P)const
{
	return sqrt((x - P.x) * (x - P.x) + (y - P.y) * (y - P.y));
}
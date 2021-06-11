#include<iostream>
#include"head.h"
using namespace std;

Circle::Circle(const Point &P, double r = 0) :center(P), radius(r)
{
	cout << "Circle���캯��" << endl;
}

Circle::~Circle()
{
	cout << "Circle��������" << endl;
}

void Circle::Intersect(const Circle& C)const
{
	double dis = center.Getdistance(C.center);		//Բ�ļ��

	cout << endl;
	if (dis<radius + C.radius
		&& dis>(radius > C.radius ? (radius - C.radius) : (C.radius - radius)))
		cout << "��Բ�ཻ" << endl;
	else cout << "��Բ���ཻ" << endl;
	cout << endl;
	
}
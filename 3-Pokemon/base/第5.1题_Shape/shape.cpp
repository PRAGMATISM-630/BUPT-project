#include<iostream>
#include"shape.h"

using namespace std;

/*��״��*/
Shape::Shape()
{
	cout << "���๹�캯��" << endl;
}

Shape::~Shape()
{
	cout << "������������" << endl;
}

Shape::Shape(const Shape& S)
{
	cout << "���ิ�ƹ��캯��" << endl;
}

/*������*/
Rectangle::Rectangle(double w, double h) :width(w), height(h)
{
	cout << "�����๹�캯��" << endl;
}

Rectangle::~Rectangle()
{
	cout << "��������������" << endl;
}

Rectangle::Rectangle(const Rectangle& R)
{
	width = R.width;
	height = R.height;
	cout << "�����ิ�ƹ��캯��" << endl;
}

double Rectangle::Get_area()
{
	return width * height;
}


/*Բ����*/
Circle::Circle(double r) :radius(r)
{
	cout << "Բ���๹�캯��" << endl;
}

Circle::~Circle()
{
	cout << "Բ������������" << endl;
}

Circle::Circle(const Circle& C)
{
	radius = C.radius;
	cout << "Բ���ิ�ƹ��캯��" << endl;
}

double Circle::Get_area()
{
	return 3.14 * radius * radius;
}


/*��������*/
Square::Square(double w) :Rectangle(w,w),width(w)
{
	cout << "�������๹�캯��" << endl;
}

Square::Square(const Square& S):Rectangle(S)
{
	width = S.width;
	cout << "�������ิ�ƹ��캯��" << endl;
}

Square::~Square()
{
	cout << "����������������" << endl;
}

double Square::Get_area()
{
	return width * width;
}

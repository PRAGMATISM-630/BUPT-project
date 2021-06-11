#include<iostream>
#include"shape.h"

using namespace std;

/*形状类*/
Shape::Shape()
{
	cout << "基类构造函数" << endl;
}

Shape::~Shape()
{
	cout << "基类析构函数" << endl;
}

Shape::Shape(const Shape& S)
{
	cout << "基类复制构造函数" << endl;
}

void Shape::Get_area()
{
	cout << "计算面积" << endl;
}

/*矩形类*/
Rectangle::Rectangle(double w, double h) :width(w), height(h)
{
	cout << "矩形类构造函数" << endl;
}

Rectangle::~Rectangle()
{
	cout << "矩形类析构函数" << endl;
}

Rectangle::Rectangle(const Rectangle& R)
{
	width = R.width;
	height = R.height;
	cout << "矩形类复制构造函数" << endl;
}

double Rectangle::Get_area_Rect()
{
	return width * height;
}


/*圆形类*/
Circle::Circle(double r) :radius(r)
{
	cout << "圆形类构造函数" << endl;
}

Circle::~Circle()
{
	cout << "圆形类析构函数" << endl;
}

Circle::Circle(const Circle& C)
{
	radius = C.radius;
	cout << "圆形类复制构造函数" << endl;
}

double Circle::Get_area_Cir()
{
	return 3.14 * radius * radius;
}


/*正方形类*/
Square::Square(double w) :Rectangle(w, w), width(w)
{
	cout << "正方形类构造函数" << endl;
}

Square::Square(const Square& S) : Rectangle(S)
{
	width = S.width;
	cout << "正方形类复制构造函数" << endl;
}

Square::~Square()
{
	cout << "正方形类析构函数" << endl;
}

double Square::Get_area_Squa()
{
	return width * width;
}

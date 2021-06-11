//???
#pragma once

/*��״��*/
class Shape
{
public:
	Shape();
	~Shape();
	Shape(const Shape& S);
	void Get_area();
};



/*������*/
class Rectangle :public Shape
{
public:
	Rectangle(double w, double h);
	~Rectangle();
	Rectangle(const Rectangle& R);
	double Get_area_Rect();
private:
	double width;
	double height;
};


/*Բ����*/
class Circle :public Shape
{
public:
	Circle(double r);
	~Circle();
	Circle(const Circle& C);
	double Get_area_Cir();
private:
	double radius;
};


/*��������*/
class Square :public Rectangle
{
public:
	Square(double w);
	~Square();
	Square(const Square& S);
	double Get_area_Squa();
private:
	double width;
};
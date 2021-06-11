//???
#pragma once

/*形状类*/
class Shape
{
public:
	Shape();
	~Shape();
	Shape(const Shape& S);
	void Get_area();
};



/*矩形类*/
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


/*圆形类*/
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


/*正方形类*/
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
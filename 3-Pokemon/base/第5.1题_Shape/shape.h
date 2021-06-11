#pragma once

/*形状类*/
class Shape										//抽象类
{
public:
	Shape();
	~Shape();
	Shape(const Shape& S);
	virtual double Get_area() = 0;				//虚函数
};


/*矩形类*/
class Rectangle :public Shape
{
public:
	Rectangle(double w, double h);
	~Rectangle();
	Rectangle(const Rectangle& R);
	virtual double Get_area()override;
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
	virtual double Get_area()override;
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
	virtual double Get_area()override final;
private:
	double width;
};
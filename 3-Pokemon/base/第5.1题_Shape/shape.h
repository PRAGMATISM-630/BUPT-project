#pragma once

/*��״��*/
class Shape										//������
{
public:
	Shape();
	~Shape();
	Shape(const Shape& S);
	virtual double Get_area() = 0;				//�麯��
};


/*������*/
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


/*Բ����*/
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


/*��������*/
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
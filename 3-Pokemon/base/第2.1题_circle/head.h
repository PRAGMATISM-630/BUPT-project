#pragma once

class Point
{
public:
	Point();								//默认构造函数
	Point(double x, double y);				//构造函数
	Point(const Point& P);					//拷贝构造函数
	~Point();								//析构函数
	double Getdistance(const Point& P)const;//计算距离

private:
	double x;
	double y;
};


class Circle
{
public:
	Circle(const Point &c, double r);		 //构造函数
	~Circle();								 //析构函数
	void Intersect(const Circle& C)const;	 //判断是否相交

private:
	Point center;
	double radius;
};
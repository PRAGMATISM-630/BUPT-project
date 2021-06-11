#pragma once
#include<iostream>

class Point
{
public:
	Point() :x(0), y(0) {};			//默认构造函数
	Point(int x, int y);			//构造函数
	Point(const Point&);			//拷贝构造函数
	~Point() {};					//析构函数，什么都不做
	Point operator=(const Point&);	//赋值重载

	friend std::ostream& operator<<(std::ostream&, const Point&);	//重载<<

	Point& operator++();			//前置自增
	Point& operator--();			//前置自减
	const Point operator++(int);	//后置自增
	const Point operator--(int);	//后置自减

private:
	int x;
	int y;
};
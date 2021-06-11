#pragma once

class Point
{
public:
	Point();								//Ĭ�Ϲ��캯��
	Point(double x, double y);				//���캯��
	Point(const Point& P);					//�������캯��
	~Point();								//��������
	double Getdistance(const Point& P)const;//�������

private:
	double x;
	double y;
};


class Circle
{
public:
	Circle(const Point &c, double r);		 //���캯��
	~Circle();								 //��������
	void Intersect(const Circle& C)const;	 //�ж��Ƿ��ཻ

private:
	Point center;
	double radius;
};
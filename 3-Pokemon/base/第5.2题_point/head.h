#pragma once
#include<iostream>

class Point
{
public:
	Point() :x(0), y(0) {};			//Ĭ�Ϲ��캯��
	Point(int x, int y);			//���캯��
	Point(const Point&);			//�������캯��
	~Point() {};					//����������ʲô������
	Point operator=(const Point&);	//��ֵ����

	friend std::ostream& operator<<(std::ostream&, const Point&);	//����<<

	Point& operator++();			//ǰ������
	Point& operator--();			//ǰ���Լ�
	const Point operator++(int);	//��������
	const Point operator--(int);	//�����Լ�

private:
	int x;
	int y;
};
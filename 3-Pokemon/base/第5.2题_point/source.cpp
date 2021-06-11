#include"head.h"

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point::Point(const Point& P)
{
	x = P.x;
	y = P.y;
}

Point Point::operator=(const Point& P)
{
	if (this == &P)
		return *this;
	Point tmp(P);
	return tmp;
}

std::ostream& operator<<(std::ostream& os, const Point& P)
{
	os << "(" << P.x << "," << P.y << ")\n";
	return os;
}


Point& Point::operator++()
{
	x++;
	y++;
	return *this;
}

Point& Point::operator--()
{
	x--;
	y--;
	return *this;
}

const Point Point::operator++(int)
{
	Point tmp(*this);
	x++;
	y++;
	return tmp;
}

const Point Point::operator--(int)
{
	Point tmp(*this);
	x--;
	y--;
	return tmp;
}

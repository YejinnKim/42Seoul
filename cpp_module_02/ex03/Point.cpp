#include "Point.hpp"

Point::Point() : x(0), y(0)
{

}

Point::Point(float x, float y) : x(x), y(y)
{

}

Point::Point(const Point &point) : x(point.getX()), y(point.getY())
{
	
}

Point& Point::operator = (const Point &point)
{
	if (this != &point)
	{
		const_cast<Fixed&>(x) = point.getX();
		const_cast<Fixed&>(y) = point.getY();
	}
	return *this;
}

Point::~Point()
{
	
}

Fixed	Point::getX() const
{
	return x;
}

Fixed	Point::getY() const
{
	return y;
}

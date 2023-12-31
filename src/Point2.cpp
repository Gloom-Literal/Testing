///////////////////////////////////////////
// Headers
///////////////////////////////////////////
#include "Point2.hpp"


///////////////////////////////////////////
Point2::Point2() :
x(0),
y(0)
{
}


///////////////////////////////////////////
Point2::Point2(double x, double y) :
x(x),
y(y)
{
}


///////////////////////////////////////////
bool Point2::operator<(const Point2& right) const
{
	return x < right.x - EPS || std::abs(x - right.x) < EPS && y < right.y - EPS;
}


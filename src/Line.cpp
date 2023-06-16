///////////////////////////////////////////
// Headers
///////////////////////////////////////////
#include "Line.hpp"


///////////////////////////////////////////
Line::Line() :
a(0),
b(0),
c(0)
{
}


///////////////////////////////////////////
Line::Line(const Point2& p, const Point2& q) :
	a(p.y - q.y),
	b(q.x - p.x),
	c(-a * p.x - b * p.y)
{
	norm();
}


///////////////////////////////////////////
double Line::dist(const Point2& p) const
{
	return (a * p.x + b * p.y + c);
}


///////////////////////////////////////////
void Line::setPoints(const Point2& p, const Point2& q)
{
	a = (p.y - q.y);
	b = (q.x - p.x);
	c = (-a * p.x - b * p.y);
	norm();
}


///////////////////////////////////////////
void Line::norm()
{
	double z = sqrt(a * a + b * b);
	if (abs(z) > EPS)
	{
		a /= z;
		b /= z;
		c /= z;
	}
}
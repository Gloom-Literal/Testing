///////////////////////////////////////////
// Headers
///////////////////////////////////////////
#include "Shape.hpp"


namespace
{
///////////////////////////////////////////
double det(double a, double b, double c, double d)
{
	return (a * d - b * c);
}


///////////////////////////////////////////
bool betw(double l, double r, double x)
{
	return std::min(l, r) <= x + EPS && x <= std::max(l, r) + EPS;
}


///////////////////////////////////////////
bool intersect_1d(double a, double b, double c, double d)
{
	if (a > b)
		std::swap(a, b);
	if (c > d) 
		std::swap(c, d);
	return (std::max(a, c) <= std::min(b, d) + EPS);
}


///////////////////////////////////////////
bool intersect(Point2 a, Point2 b, Point2 c, Point2 d, Point2& start, Point2& end)
{
	if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y))
		return false;
	
	Line m(a, b);
	Line n(c, d);
	
	double zn{ det(m.a, m.b, n.a, n.b) };
	
	if (abs(zn) < EPS)
	{
		if (abs(m.dist(c)) > EPS || abs(n.dist(a)) > EPS)
			return false;
		if (b < a)
			std::swap(a, b);
		if (d < c)
			std::swap(c, d);
		
		start = std::max(a, c);
		end   = std::min(b, d);
		
		return true;
	}
	else
	{
		start.x = end.x = -det(m.c, m.b, n.c, n.b) / zn;
		start.y = end.y = -det(m.a, m.c, n.a, n.c) / zn;
		
		return betw(a.x, b.x, start.x)
			&& betw(a.y, b.y, start.y)
			&& betw(c.x, d.x, start.x)
			&& betw(c.y, d.y, start.y);
	}
}

} // namespace

///////////////////////////////////////////
Shape::Shape() :
	m_vertices()
{
}


///////////////////////////////////////////
Shape::Shape(const std::vector<Point2>& vertices) :
	m_vertices(vertices)
{
}


///////////////////////////////////////////
std::size_t Shape::getVertexCount() const
{
	return m_vertices.size();
}


////////////////////////////////////////////////////////////
const Point2& Shape::at(std::size_t index) const
{
    return m_vertices.at(index);
}


////////////////////////////////////////////////////////////
Point2& Shape::at(std::size_t index)
{
    return m_vertices.at(index);
}


////////////////////////////////////////////////////////////
void Shape::add(const Point2& point)
{
    m_vertices.emplace_back(point);
}


///////////////////////////////////////////
std::set<Point2> Shape::checkCollision(const Shape& shape) const
{
	std::set<Point2> result;

    for (std::size_t i{ 0 }; i < getVertexCount(); ++i)
    {
        for (std::size_t j{ 0 }; j < shape.getVertexCount(); ++j)
        {
			Point2 a;
			Point2 b;
			if (intersect(at(i), at((i + 1 == getVertexCount() ? 0 : i + 1)),
				shape.at(j), shape.at((j + 1 == shape.getVertexCount() ? 0 : j + 1)), a, b))
			{
				result.insert(a);
				result.insert(b);
			}
        }
    }
	
	return result;
}
///////////////////////////////////////////
// Headers
///////////////////////////////////////////
#include "Ray.hpp"
#include <iostream>

///////////////////////////////////////////
Ray::Ray() :
m_distance(0),
m_angle(0),
m_line()
{
}


///////////////////////////////////////////
Ray::Ray(const Point2& start, const Point2& end) :
m_distance(std::hypot(start.x - end.x, start.y - end.y)),
m_angle(0),
m_line(start, end)
{
	add(start);
	add(end);
	m_angle = std::atan2(end.x - start.x, end.y - start.y);
}


///////////////////////////////////////////
void Ray::setDistance(double distance)
{
	m_distance = distance;
	// ax + by + c = 0
	// by = -ax - c
	// y = (-ax - c) / b
	at(1).x = m_distance * std::sin(m_angle);
	//std::cout << "NEW X: " << at(1).x << std::endl;
	at(1).y = (-m_line.a * at(1).x - m_line.c) / m_line.b;
	//std::cout << "NEW Y: " << at(1).y << std::endl;

	//std::cout << "New dis: " << std::sqrt((at(1).x - at(0).x) * (at(1).x - at(0).x) + (at(1).y - at(0).y) * (at(1).y - at(0).y)) << std::endl;
}


///////////////////////////////////////////
double Ray::getDistance() const
{
	return m_distance;
}

#include "Point2.hpp"
#include "Shape.hpp"
#include "Shapes/Ray.hpp"
#include "Shapes/Segment.hpp"

#include <thread>
#include <cmath>
#include <iostream>
#include <vector>

void checkSegmentAndQuad(const Segment& segment, const Shape& shape);
void checkStrangeAndQuad(const Shape& segment, const Shape& shape);
void checkRayAndQuad(Ray& ray, const Shape& shape);

int main()
{
	std::vector<Point2> quadPoints = { Point2(-3.1, -3.1), Point2(-3.1,  3.1),
									   Point2(3.1,  3.1), Point2(3.1, -3.1) };

	std::vector<Point2> strangePoints = { Point2(-4.0, -3.7), Point2(-3.1,  3.1),
									      Point2( 2.0,  4.1), Point2( 3.1, -2.1),
										  Point2( 3.0, -3.0), };

	// Shapes
	Segment segment(Point2(-6.1, -1.0), Point2(9.0, 0.0));
	Shape	quad(quadPoints);
	Shape	strange(strangePoints);
	Ray		ray(Point2(-4.0, 0.0), Point2(-3.5, 0.1));

	// Tests
	checkSegmentAndQuad(segment, strange);
	checkRayAndQuad(ray, quad);
	checkStrangeAndQuad(strange, quad);
	// Simple threads
	//std::thread thSegQ(checkSegmentAndQuad, segment, quad);
	//std::thread thStrQ(checkStrangeAndQuad, strange, quad);
	//thSegQ.join();
	//thStrQ.join();

	return 0;
}


void checkSegmentAndQuad(const Segment& segment, const Shape& shape)
{
	std::cout << "CHECK SEGMENT AND STRANGE SHAPE" << std::endl;

	unsigned int count{ 0 };
	auto result{ segment.checkCollision(shape) };
	if (result.size() > 0)
	{
		std::cout << "All point of collision:" << std::endl;
		for (const auto& p : result)
		{
			++count;
			std::cout << "[point " << count << "] (" << p.x << ", " << p.y << ");" << std::endl;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "No points of collision!" << std::endl << std::endl;
}


void checkRayAndQuad(Ray& ray, const Shape& shape)
{
	std::cout << "CHECK RAY AND QUAD" << std::endl;
	
	for (std::size_t i{ 0 }; i < 3; ++i)
	{
		unsigned int count{ 0 };
		std::cout << "Ray Test#" << i + 1 << std::endl;
		std::cout << "Distance of ray = " << ray.getDistance() << ";" << std::endl;
		auto result{ ray.checkCollision(shape) };
		if (result.size() > 0)
		{
			std::cout << "All point of collision:" << std::endl;
			for (const auto& p : result)
			{
				++count;
				std::cout << "[point " << count << "] (" << p.x << ", " << p.y << ");" << std::endl;
			}
			std::cout << std::endl;
		}
		else
			std::cout << "No points of collision!" << std::endl << std::endl;

		ray.setDistance(3.0 * static_cast<double>(i + 1));
	}
}


void checkStrangeAndQuad(const Shape& strange, const Shape& shape)
{
	std::cout << "CHECK STRANGE SHAPE AND QUAD" << std::endl;

	unsigned int count{ 0 };
	auto result{ strange.checkCollision(shape) };
	if (result.size() > 0)
	{
		std::cout << "All point of collision:" << std::endl;
		for (const auto& p : result)
		{
			++count;
			std::cout << "[point " << count << "] (" << p.x << ", " << p.y << ");" << std::endl;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "No points of collision!" << std::endl << std::endl;
}
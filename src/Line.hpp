#ifndef LINE_INCLUDE
#define LINE_INCLUDE

///////////////////////////////////////////
// Headers
///////////////////////////////////////////
#include "Point2.hpp"

///////////////////////////////////////////
/// \brief Util struct for working with line
///
///////////////////////////////////////////
struct Line
{
	///////////////////////////////////////////
	/// \brief Default constructor
	///
	///////////////////////////////////////////
	Line();

	///////////////////////////////////////////
	/// \brief Constructor
	///
	/// Calculates the equation of a straight line at two given points.
	/// 
	///////////////////////////////////////////
	Line(const Point2& p, const Point2& q);

	///////////////////////////////////////////
	void norm();

	///////////////////////////////////////////
	void setPoints(const Point2& p, const Point2& q);

	///////////////////////////////////////////
	double dist(const Point2& p) const;

	///////////////////////////////////////////
	// Member data
	///////////////////////////////////////////
	double a;
	double b; 
	double c;
};
#endif // LINE_INCLUDE


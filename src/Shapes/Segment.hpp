#ifndef SEGMENT_INCLUDE
#define SEGMENT_INCLUDE

///////////////////////////////////////////
// Headers
///////////////////////////////////////////
#include "../Shape.hpp"

class Segment final : public Shape
{
public:
	///////////////////////////////////////////
	/// \brief Default constructor
	/// 
	///////////////////////////////////////////
	Segment();

	///////////////////////////////////////////
	/// \brief Constructor
	///
	/// \param start Start point
	/// \param end	 End point
	///
	///////////////////////////////////////////
	Segment(const Point2& start, const Point2& end);
};

#endif // SEGMENT_INCLUDE


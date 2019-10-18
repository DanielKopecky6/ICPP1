#include "MovingObject.h"

#define MINIMUM_ANGLE 0
#define MAXIMUM_ANGLE (2*(std::atan(1)*4))
#include <cmath>
#include <stdexcept>

MovingObject::MovingObject(int aId) : Object (id)
{
	id = aId;
}

void MovingObject::SetAngle(double aAngle)
{
	if (aAngle > MINIMUM_ANGLE && aAngle < MAXIMUM_ANGLE) {
		angle = aAngle;
	}else{
	throw std::invalid_argument("Bad value for angle");
	}
}

double MovingObject::getAngle() const
{
	return angle;
}

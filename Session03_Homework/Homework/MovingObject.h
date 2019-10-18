#pragma once
#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H
#include "Object.h"

struct MovingObject : Object {
private:
	double angle;
public:
	MovingObject(int aId);
	void SetAngle(double angle);
	double getAngle() const;



};




#endif // !MOVING_OBJECT_H

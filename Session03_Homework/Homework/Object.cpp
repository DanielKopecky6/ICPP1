#include "Object.h"


void Object::SetX(double aX)
{
	x = aX;
}

double Object::GetX() const
{
	return x;
}

void Object::SetY(double aY)
{
	y = aY;
}

double Object::GetY() const
{
	return y;
}

int Object::GetId() const
{
	return id;
}

Object::Object(int aId)
{
	id = aId;
}


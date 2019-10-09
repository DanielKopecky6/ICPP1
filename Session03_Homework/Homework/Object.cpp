#include "Object.h"


void Object::SetX(double aX)
{
	x = aX;
}

double Object::GetX()
{
	return x;
}

void Object::SetY(double aY)
{
	y = aY;
}

double Object::GetY()
{
	return y;
}

int Object::GetI()
{
	return id;
}

Object::Object(int aId)
{
	id = aId;
}


#pragma once
#ifndef GAME_H
#define GAME_H
#include "Monster.h"
#include "StaticObject.h"

struct Game {
private:
	int numberOfMaxEntries;
	int numberOfObjects;

public:
	Game(int numberOfMaxEntries);
	Object ** objectsField;
	void InsertObject(Object* aObject);
	int* FindStaticObject(double xMin, double xMax, double yMin, double yMax);
	MovingObject** FindMovingObjectInArea(double x, double y, double r);
	MovingObject** FindMovingObjectInArea(double x, double y, double r, double umin, double umax);
};



#endif // !GAME_H

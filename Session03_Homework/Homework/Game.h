#pragma once
#ifndef GAME_H
#define GAME_H
#include "Monster.h"
#include "StaticObject.h"

struct Game {
private:
	

public:
	Game();
	Object ** objectsField;
	void insertObject(Object* aObject);
	int* findStaticObject(double xMin, double xMax, double yMin, double yMax);
	MovingObject** FindMovingObjectInArea(double x, double y, double r);
	MovingObject** FindMovingObjectInArea(double x, double y, double r, double umin, double umax);
};



#endif // !GAME_H

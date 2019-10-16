#include "Game.h"
#include<iostream>

int ObjectsSize = 10;
int NumberOfObjects = 0;
typedef Object* ObjectPtr;
ObjectPtr * objectsField = new ObjectPtr[NumberOfObjects];
//
//Object* objekt = *Game::objectsField;
//objects = new Object[];

Game::Game()
{
	objectsField = new Object*[ObjectsSize];
}

void Game::insertObject(Object * aObject)
{
		if(NumberOfObjects < ObjectsSize){
		objectsField[NumberOfObjects++] = aObject;
		}
	
}

int * Game::findStaticObject(double xMin, double xMax, double yMin, double yMax)
{
	int * idInArea;
	idInArea = new int[NumberOfObjects];
	int numberOfId = 0;
	for (int i = 0; i < NumberOfObjects; i++)
	{
		Object objekt = *objectsField[i];
		if (objekt.GetX() > xMin && objekt.GetX() < xMax && objekt.GetY() > yMin && objekt.GetY() < yMax) {
			
			idInArea[numberOfId++] = objekt.GetId();

			std::cout << "jsmetu" << idInArea << std::endl;
			
		}
		
	}
	return idInArea;
}

MovingObject ** Game::FindMovingObjectInArea(double x, double y, double r)
{
	MovingObject ** MovingObjects;
	MovingObjects = new MovingObject*[ObjectsSize];
	int MovingObjectsCount = 0;
	for (int i = 0; i < NumberOfObjects; i++)

	{
		Object objekt = *objectsField[i];
		
		if ((objekt.GetX() - x) * (objekt.GetX() -x) + (objekt.GetY() - y) * (objekt.GetY() - y) <= r*r) {

			MovingObjects[MovingObjectsCount++] = (MovingObject*)&objekt;

		}

		return MovingObjects;


	}


	
	objectsField[0] = MovingObjects[0];
}

MovingObject ** Game::FindMovingObjectInArea(double x, double y, double r, double umin, double umax)
{
	// ze zadani jsem nepochopil co ma predstavovat uhel natoceni, nebo jak podle nej vyhledavat.
	return nullptr;
}

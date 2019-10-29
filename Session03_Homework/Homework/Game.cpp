#include "Game.h"
#include<iostream>



Game::Game(int aNumberOfMaxEntries)
{
	objectsField = new Object*[aNumberOfMaxEntries];
	numberOfMaxEntries = aNumberOfMaxEntries;
	numberOfObjects = 0;
}

Game::~Game()
{
	for (int i = 0; i < Game::numberOfObjects; i++)
	{
		delete Game::objectsField[i];
	}
	delete[] Game::objectsField;

}

void Game::InsertObject(Object * aObject)
{
		if(numberOfObjects < numberOfMaxEntries){
		objectsField[numberOfObjects++] = aObject;
		}
		else {

throw std::out_of_range("Maximum number of objects for this Game already inserted.");

		}
	
}

int * Game::FindStaticObject(double xMin, double xMax, double yMin, double yMax)
{
	
	int numberOfIds = 0;
	for (int i = 0; i < numberOfObjects; i++)
	{
		StaticObject* staticObject = dynamic_cast<StaticObject*>(objectsField[i]);
		if (staticObject != nullptr){
		if (staticObject->GetX() > xMin && staticObject->GetX() < xMax && staticObject->GetY() > yMin && staticObject->GetY() < yMax) {
			numberOfIds++;	
			}
		}
	}
		if (numberOfIds == 0) {
			return nullptr;
		}
		int * idInArea;
		idInArea = new int[numberOfIds];
		int idsFound = 0;
		for (int i = 0; i < numberOfObjects; i++)
		{	
			StaticObject* staticObject = dynamic_cast<StaticObject*>(objectsField[i]);
			if (staticObject != nullptr) {
				if (staticObject->GetX() > xMin && staticObject->GetX() < xMax && staticObject->GetY() > yMin && staticObject->GetY() < yMax) {
					idInArea[idsFound++] = objectsField[i]->GetId();
				}
			}
		}
	
	return idInArea;
}

MovingObject ** Game::FindMovingObjectInArea(double x, double y, double r)
{
	
	int numberOfMovingObjects = 0;
	for (int i = 0; i < numberOfObjects; i++)

	{
		MovingObject* movingObject = dynamic_cast<MovingObject*>(objectsField[i]);
		if (movingObject != nullptr)
		{
		if ((movingObject->GetX() - x) * (movingObject->GetX() -x) + (movingObject->GetY() - y) * (movingObject->GetY() - y) <= r*r) {
			numberOfMovingObjects++;
			

		}
		}
	}
		if (numberOfMovingObjects == 0) {
			return nullptr;
		}
		MovingObject ** MovingObjects;
		MovingObjects = new MovingObject*[numberOfMovingObjects];
		int idsFound = 0;

		for (int i = 0; i < numberOfObjects; i++)
		{
			MovingObject* movingObject = dynamic_cast<MovingObject*>(objectsField[i]);
			if (movingObject != nullptr)
			{
				if ((movingObject->GetX() - x) * (movingObject->GetX() - x) + (movingObject->GetY() - y) * (movingObject->GetY() - y) <= r * r) {
					MovingObjects[idsFound++] = movingObject;
				}
			}
		}
		return MovingObjects;
}

MovingObject ** Game::FindMovingObjectInArea(double x, double y, double r, double umin, double umax)
{

	int numberOfMovingObjects = 0;
	for (int i = 0; i < numberOfObjects; i++)

	{
		MovingObject* movingObject = dynamic_cast<MovingObject*>(objectsField[i]);
		if (movingObject != nullptr)
		{
			if ((movingObject->GetX() - x) * (movingObject->GetX() - x) + (movingObject->GetY() - y) * (movingObject->GetY() - y) <= r * r) {
				numberOfMovingObjects++;
			}

		}

	}
	if (numberOfMovingObjects == 0) {
		return nullptr;
	}
	MovingObject ** MovingObjects;
	MovingObjects = new MovingObject*[numberOfMovingObjects];
	int idsFound = 0;

	for (int i = 0; i < numberOfObjects; i++)
	{
		MovingObject* movingObject = dynamic_cast<MovingObject*>(objectsField[i]);
		if (movingObject != nullptr)
		{
			if (((movingObject->GetX() - x) * (movingObject->GetX() - x) + (movingObject->GetY() - y) * (movingObject->GetY() - y) <= r * r) && (movingObject->getAngle()) >= umin && movingObject->getAngle() <= umax) {
				MovingObjects[idsFound++] = movingObject;
			}
		}
	}
	return MovingObjects;
}








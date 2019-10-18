#include "Game.h"
#include <iostream>

int main() {
	Game game{20};
	Object object(1);
	StaticObject Static1(2, ObstructionType::BigPlant);
	MovingObject Moving1(3);
	MovingObject Moving2(4);

	Static1.SetX(90.0);
	Static1.SetY(10.0);
	
	Moving1.SetX(10.0);
	Moving1.SetY(10.0);

	Moving2.SetX(50.0);
	Moving2.SetY(50.0);
	Moving2.SetAngle(3.14);

	game.InsertObject(&object);
	game.InsertObject(&Static1);
	game.InsertObject(&Moving1);
	game.InsertObject(&Moving2);

	std::cout << "Static object: " << *(game.FindStaticObject(0.0, 100.0, 0.0, 100.0)) << std::endl;

	std::cout << "Moving object in radius: " << (game.FindMovingObjectInArea(0.0, 0.0, 40.0)) << std::endl;

	std::cout << "Moving objects with angle: " << (game.FindMovingObjectInArea(0.0, 0.0, 40.0, 0.0 , 3.14)) << std::endl;
	

	Object* staticTest = new StaticObject{ 1, ObstructionType::SmallPlant };
	StaticObject* so = dynamic_cast<StaticObject*>(staticTest);
	if (so != nullptr)
		std::cout << "objekt je StatickyObjekt(nebo jeho potomek) " << so->GetObstructionType();


	std::cin.get();
	return 0;

}
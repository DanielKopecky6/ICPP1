#include "Game.h"
#include <iostream>

int main() {
	Game hra{};
	Object object(1);
	StaticObject StaticObject(3, StaticObject::ObstructionType::BigPlant);
	StaticObject.SetX(10.0);
	StaticObject.SetY(10.0);
	hra.insertObject(&object);
	hra.insertObject(&StaticObject);

	hra.findStaticObject(0.0,100.0,0.0,100.0);
	hra.FindMovingObjectInArea(0.0, 0.0, 20.0);




//	Object* objekt = new StaticObject{ 5, StaticObject::ObstructionType::Rock };
//	StaticObject* so = dynamic_cast<StaticObject*>(objekt);
//
//std::cout << so->id << std::endl;
//	if (so != nullptr)
//		std::cout << "objekt je StatickyObjekt(nebo jeho potomek)" << so->GetObstructionType();
//
//
	std::cin.get();
	return 0;

	
}
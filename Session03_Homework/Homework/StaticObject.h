#pragma once
#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H

#include "Object.h"


struct StaticObject : Object {
	typedef enum {
		Rock, SmallPlant, BigPlant
	}ObstructionType;

private:
	ObstructionType obstruction;
public:
	ObstructionType GetObstructionType(); 
	StaticObject(int aId, ObstructionType aObstructionType);
		

	
};

#endif // !STATIC_OBJECT_H

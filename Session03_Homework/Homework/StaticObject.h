#pragma once
#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H

#include "Object.h"
typedef enum {
	Rock, SmallPlant, BigPlant
}ObstructionType;

struct StaticObject : Object {


private:
	ObstructionType obstruction;
public:
	ObstructionType GetObstructionType() const; 
	StaticObject(int aId, ObstructionType aObstructionType);
		

	
};

#endif // !STATIC_OBJECT_H

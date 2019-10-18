#include "StaticObject.h"

ObstructionType StaticObject::GetObstructionType() const
{
	return obstruction;
}

StaticObject::StaticObject(int aId, ObstructionType aObstructionType) : Object(aId)
{
	id = aId;
	obstruction = aObstructionType;
}

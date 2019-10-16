#include "StaticObject.h"

StaticObject::ObstructionType StaticObject::GetObstructionType()
{
	return obstruction;
}

StaticObject::StaticObject(int aId, ObstructionType aObstructionType) : Object(aId)
{
	id = aId;
	obstruction = aObstructionType;
}

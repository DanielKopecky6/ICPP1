#include "StaticObject.h"

StaticObject::ObstructionType StaticObject::GetObstructionType()
{
	return obstruction;
}

StaticObject::StaticObject(int aId, ObstructionType aObstructionType)
{
	Object::id = aId;
	obstruction = aObstructionType;
}

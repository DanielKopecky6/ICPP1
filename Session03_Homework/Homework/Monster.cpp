#include "Monster.h"
#pragma once

void Monster::SetHp(int aHp) const
{
	aHp = hp;
}

void Monster::SetMaxHp(int aMaxHp) const
{
	aMaxHp = hp;
}

int Monster::getHp()
{
	return hp;
}

int Monster::getMaxHp()
{
	return maxHp;
}

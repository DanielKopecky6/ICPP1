#include "Monster.h"
#pragma once

void Monster::SetHp(int aHp)
{
	aHp = hp;
}

void Monster::SetMaxHp(int aMaxHp)
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

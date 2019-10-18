#ifndef MONSTER_H
#define MONSTER_H
#include "MovingObject.h"

struct Monster : MovingObject
{
private:
	int hp;
	int maxHp;
public:
	void SetHp(int aHp) const;
	void SetMaxHp(int aMaxHp) const;
	int getHp();
	int getMaxHp();

};

#endif // !MONSTER_H

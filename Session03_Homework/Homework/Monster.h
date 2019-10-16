#ifndef MONSTER_H
#define MONSTER_H
#include "MovingObject.h"

struct Monster : MovingObject
{
private:
	int hp;
	int maxHp;
public:
	void SetHp(int aHp);
	void SetMaxHp(int aMaxHp);
	int getHp();
	int getMaxHp();

};

#endif // !MONSTER_H

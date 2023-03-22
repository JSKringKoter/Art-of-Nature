#include "TotalHead.h"
//1-1 精英敌人：草原精英法师
BOSS GrassUpgradeMaster()
{
	int health = 0;
	int damage = 0;
	int defence = 0;

	makeRand(30, 20, 5, 5, 15, 5, health, damage, defence);

	
	srand((unsigned)time(0));
	int skill = rand() % 2 + 1;

	BOSS enemyReturn(health, damage, defence, "草原精英法师", skill);
	return enemyReturn;
}
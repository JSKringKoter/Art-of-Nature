#include "TotalHead.h"
//1-1BOSS����ԭ����
BOSS GrassBOSS()
{
	int health = 0;
	int damage = 0;
	int defence = 0;

	makeRand(150, 20, 20, 10, 0, 0, health, damage, defence);

	srand((unsigned)time(0));
	int skill = rand() % 5 + 1;

	BOSS enemyReturn(health, damage, defence, "��ԭ����", skill);
	return enemyReturn;
}
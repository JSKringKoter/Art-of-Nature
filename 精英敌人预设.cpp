#include "TotalHead.h"
//1-1 ��Ӣ���ˣ���ԭ��Ӣ��ʦ
BOSS GrassUpgradeMaster()
{
	int health = 0;
	int damage = 0;
	int defence = 0;

	makeRand(30, 20, 5, 5, 15, 5, health, damage, defence);

	
	srand((unsigned)time(0));
	int skill = rand() % 2 + 1;

	BOSS enemyReturn(health, damage, defence, "��ԭ��Ӣ��ʦ", skill);
	return enemyReturn;
}
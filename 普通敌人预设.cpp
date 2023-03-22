#include "TotalHead.h"

/*
¹Ø¿¨1-1
²ÝÔ­ÔÓ±ø
²ÝÔ­·¨Ê¦
²ÝÔ­¶Ü±ø
*/
Enemy GrassCommonSoldier()
{
	int health = 0;
	int damage = 0;
	int defence = 0;

	makeRand(30, 20, 5, 5, 15, 5, health, damage, defence);

	Enemy enemyReturn(health, damage, defence, "²ÝÔ­ÔÓ±ø");
	return enemyReturn;
}

Enemy GrassUpgradeSoldier()
{
	int health = 0;
	int damage = 0;
	int defence = 0;

	makeRand(60, 20, 10, 5, 20, 10, health, damage, defence);

	Enemy enemyReturn(health, damage, defence, "²ÝÔ­´ó±ø");
	return enemyReturn;
}

Enemy GrassMaster()
{
	int health = 0;
	int damage = 0;
	int defence = 0;

	makeRand(40, 10, 20, 10, 5, 5, health, damage, defence);

	Enemy enemyReturn(health, damage, defence, "²ÝÔ­·¨Ê¦");
	return enemyReturn;
}

Enemy GrassDefener()
{
	int health = 0;
	int damage = 0;
	int defence = 0;

	makeRand(70, 30, 5, 5, 30, 10, health, damage, defence);

	Enemy enemyReturn(health, damage, defence, "²ÝÔ­¶Ü±ø");
	return enemyReturn;
}

/*
¹Ø¿¨1-2 
º®±ùÔÓ±ø
º®±ù·¨Ê¦
º®±ù¶Ü±ø
º®±ù¶·Ê¿
*/
Enemy IceCommonSoldier()
{
	int health = 0;
	int damage = 0;
	int defence = 0;

	makeRand(40, 20, 10, 5, 15, 10, health, damage, defence);
	Enemy enemyReturn(health, damage, defence, "º®±ùÊ¿±ø");
	return enemyReturn;
}

Enemy IceMaster()
{
	int health = 0;
	int damage = 0;
	int defence = 0;

	makeRand(40, 10, 20, 10, 5, 5, health, damage, defence);
	Enemy enemyReturn(health, damage, defence, "º®±ù·¨Ê¦");
	return enemyReturn;
}

Enemy IceDefence()
{
	int health = 0;
	int damage = 0;
	int defence = 0;

	makeRand(70, 30, 5, 5, 30, 10, health, damage, defence);
	Enemy enemyReturn(health, damage, defence, "º®±ù¶Ü±ø");
	return enemyReturn;
}

Enemy IceHighAttacker()
{
	int health = 0;
	int damage = 0;
	int defence = 0;

	makeRand(20, 10, 30, 10, 5, 5, health, damage, defence);
	Enemy enemyReturn(health, damage, defence, "º®±ù¶·Ê¿");
	return enemyReturn;
}
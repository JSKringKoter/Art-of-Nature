#include "TotalHead.h"

/*
�ؿ�1-1
��ԭ�ӱ�
��ԭ��ʦ
��ԭ�ܱ�
*/
Enemy GrassCommonSoldier()
{
	int health = 0;
	int damage = 0;
	int defence = 0;

	makeRand(30, 20, 5, 5, 15, 5, health, damage, defence);

	Enemy enemyReturn(health, damage, defence, "��ԭ�ӱ�");
	return enemyReturn;
}

Enemy GrassUpgradeSoldier()
{
	int health = 0;
	int damage = 0;
	int defence = 0;

	makeRand(60, 20, 10, 5, 20, 10, health, damage, defence);

	Enemy enemyReturn(health, damage, defence, "��ԭ���");
	return enemyReturn;
}

Enemy GrassMaster()
{
	int health = 0;
	int damage = 0;
	int defence = 0;

	makeRand(40, 10, 20, 10, 5, 5, health, damage, defence);

	Enemy enemyReturn(health, damage, defence, "��ԭ��ʦ");
	return enemyReturn;
}

Enemy GrassDefener()
{
	int health = 0;
	int damage = 0;
	int defence = 0;

	makeRand(70, 30, 5, 5, 30, 10, health, damage, defence);

	Enemy enemyReturn(health, damage, defence, "��ԭ�ܱ�");
	return enemyReturn;
}

/*
�ؿ�1-2 
�����ӱ�
������ʦ
�����ܱ�
������ʿ
*/
Enemy IceCommonSoldier()
{
	int health = 0;
	int damage = 0;
	int defence = 0;

	makeRand(40, 20, 10, 5, 15, 10, health, damage, defence);
	Enemy enemyReturn(health, damage, defence, "����ʿ��");
	return enemyReturn;
}

Enemy IceMaster()
{
	int health = 0;
	int damage = 0;
	int defence = 0;

	makeRand(40, 10, 20, 10, 5, 5, health, damage, defence);
	Enemy enemyReturn(health, damage, defence, "������ʦ");
	return enemyReturn;
}

Enemy IceDefence()
{
	int health = 0;
	int damage = 0;
	int defence = 0;

	makeRand(70, 30, 5, 5, 30, 10, health, damage, defence);
	Enemy enemyReturn(health, damage, defence, "�����ܱ�");
	return enemyReturn;
}

Enemy IceHighAttacker()
{
	int health = 0;
	int damage = 0;
	int defence = 0;

	makeRand(20, 10, 30, 10, 5, 5, health, damage, defence);
	Enemy enemyReturn(health, damage, defence, "������ʿ");
	return enemyReturn;
}
#pragma once
#ifndef ENEMY
#define ENEMY

class Player;

class Enemy
{
public:
	
	string enemyName;

	int enemyMaxHealth;
	int enemyHealth;

	int enemyDamage;
	int enemyAddDamage;

	int enemyDefence;

	int enemyHowToActive;

	bool ableToActive;

	Buff buff;

	Enemy();
	Enemy(int enemy_health, int enemy_damage, int enemy_defence, string enemy_name);
	~Enemy();

	virtual void showEnemyMenu();

	void enemyBeingHeal(int healNumber);
	int enemyBeingHurt(int hurtNumber);
	void enemyAttack(Player& player, int attackDamage = -1);

	void BuffEffect();
	void isBuffOver();
	void defineHowToActive(int case1 = 25, int case2 = 50, int case3 = 75, int case4 = 101);

	void enemyActive(Player& player);
};

#endif // !ENEMY

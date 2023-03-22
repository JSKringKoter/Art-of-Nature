#pragma once
#ifndef Player_h
#define Player_h


class Enemy;

class Player
{
public:
	string playerName;

	int playerHealth;
	int playerMaxHealth;

	int playerDamage;
	int playerAddDamage;
	int playerDefence;

	int playerMaxEnergy;
	int playerEnergy;

	bool ableToActive;


	int crystal;
	Backpack backPack;
	Buff buff;
	Core playerCore;

//���캯����
	Player();
	Player(int player_health, int player_damage, int player_defence, int player_energy, string player_name);
	~Player();

	void playerShowMenu();

	int playerBeingHurt(int hurtNumber);
	void playerBeingHeal(int healNumber);
	void playerAddEnergy(int addNumber);

	void playerAttack(Enemy& enemy, int attackDamage = -1);
	//BUFF
	void BuffEffect();
	void isBuffOver();

	//���ļ���
	int playerUseCore(Enemy& eneny);

	//ʹ����Ʒ
	int playerUseItem(Enemy& enemy);

	int PlayerActive(Enemy& enemy);
};

#endif // !Player_h


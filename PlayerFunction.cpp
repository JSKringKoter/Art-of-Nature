#include "TotalHead.h"

Player::Player(int player_health, int player_damage, int player_defence, int player_energy, string player_name) :
	backPack(), buff(), playerCore()
{
	playerHealth = playerMaxHealth = player_health;
	playerDamage = player_damage;
	playerAddDamage = 0;
	playerDefence = player_defence;
	playerEnergy = playerMaxEnergy = player_energy;
	playerName = player_name;


	ableToActive = true;

	crystal = 0;
}

Player::Player() : backPack(), buff(), playerCore()
{
	playerHealth = playerMaxHealth = 0;
	playerDamage = 0;
	playerAddDamage = 0;
	playerDefence = 0;
	playerEnergy = playerMaxEnergy = 0;
	playerName = "player_name";

	ableToActive = true;

	crystal = 0;
}


Player::~Player() {}


void Player::playerBeingHeal(int healNumber)
{
	int record = playerHealth;
	playerHealth += healNumber;
	if (playerHealth > playerMaxHealth) {
		cout << "生命值已满。\n";
		playerHealth = playerMaxHealth;
	}
	else
	    cout << "\n治疗了" << - (record - playerHealth) << "点生命值。\n";

	postpone();
}

int Player::playerBeingHurt(int hurtNumber)
{
	if (hurtNumber <= playerDefence) {
		playerDefence -= hurtNumber;
		return 0;
	}
	else {
		playerHealth -= hurtNumber - playerDefence;
		playerDefence = 0;
		return 1;
	}
}

void Player::playerAddEnergy(int addNumber)
{
	playerEnergy += addNumber;
	if (playerEnergy > playerMaxEnergy)
		playerEnergy = playerMaxEnergy;
}



//玩家进行攻击
void Player::playerAttack(Enemy& enemy, int attackDamage)
{

	int playerFinalDamage = 0;

	if (attackDamage == -1) {
		playerFinalDamage = playerDamage + playerAddDamage;
	}
	else {
		playerFinalDamage = attackDamage;
	}

	postpone();

	if (playerFinalDamage <= 0) {
		cout << "攻击未造成伤害。" << endl;
		postpone();
		return;
	}
	
	int enemyDefenceRecord = enemy.enemyDefence;
	int enemyHealthRecord = enemy.enemyHealth;
	int attackResultRecord = enemy.enemyBeingHurt(playerFinalDamage);

	if (attackResultRecord == 0) {
		cout << "攻击未造成伤害，对护甲造成" << enemyDefenceRecord - enemy.enemyDefence << "点损伤。\n";
		postpone();
	}
	else if (attackResultRecord == 1) {
		cout << "对护甲造成" << enemyDefenceRecord - enemy.enemyDefence << "点损伤。";
		cout << "造成" << enemyHealthRecord - enemy.enemyHealth << "点伤害。\n";
		postpone();
	}
	else if (attackResultRecord == 2) {
		cout << "造成" << enemyHealthRecord - enemy.enemyHealth << "点伤害。\n";
		postpone();
	}

	if (enemy.enemyHealth > 0)
		cout << "敌方生命剩余" << enemy.enemyHealth << endl;
	else
		cout << "敌方死亡。" << endl;

	postpone();
}





void Player::playerShowMenu()
{
	    print_();
		int healthLeftCompareMax = (double)playerHealth / playerMaxHealth * 10;
		if (healthLeftCompareMax > 10)
			healthLeftCompareMax = 10;
		cout << endl;
		cout << "你：" << playerName << endl;
		//显示生命值
		cout << "生命 " << playerHealth;
		cout << "   \t|";
		for (int i = 0; i < healthLeftCompareMax; i++) cout << "▲";
		for (int i = 0; i < 20 - 2 * healthLeftCompareMax; i++) cout << " ";
		cout << "";
		cout << " MAX " << playerMaxHealth;
		cout << endl;

		//显示护甲值
		int showDefence = playerDefence / 10;
		cout << "护甲 " << playerDefence;
		cout << "    \t|";
		if (showDefence > 10)
			showDefence = 10;
		for (int i = 0; i < showDefence; i++) cout << "▼";
		cout << endl;

		//显示攻击力
		int showAttack = playerDamage / 10;
		cout << "攻击 " << playerDamage;
		if (buff.BuffID == 3) {
			cout << "+" << (int)(playerDamage * 0.1 * buff.Level);
		}
		if (buff.BuffID == 4) {
			cout << "-" << buff.Level * 5;
		}
		cout << "    \t|";
		if (showAttack > 10)
			showAttack = 10;
		for (int i = 0; i < showAttack; i++) cout << "◆";
		cout << endl;

		//显示能量
		int EnergyLeftCompareMax = (double)playerEnergy / playerMaxEnergy * 10;
		if (EnergyLeftCompareMax > 10)
			EnergyLeftCompareMax = 10;
		cout << "能量 " << playerEnergy;
		cout << "   \t|";
		for (int i = 0; i < EnergyLeftCompareMax; i++) cout << "○";
		for (int i = 0; i < 20 - 2 * EnergyLeftCompareMax; i++) cout << " ";
		cout << "";
		cout << " MAX " << playerMaxEnergy;
		cout << endl;

		//显示拥有水晶
		cout << "水晶★  " << crystal << endl;

		if (buff.isHasBuff == true) {
			cout << endl;
			cout << "效果：" << buff.BuffName << buff.Level;
			cout << "  剩余 " << buff.Rend + 1 << " 回合" << endl;
		}

		print_();
		cout << endl;
}
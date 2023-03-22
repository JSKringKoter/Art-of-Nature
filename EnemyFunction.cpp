#include "TotalHead.h"

Enemy::Enemy() : buff()
{
	enemyHealth = enemyMaxHealth = 0;
	enemyDamage = 0;
	enemyDefence = 0;
	enemyName = "enemy_name";
	enemyAddDamage = 0;
	enemyHowToActive = 0;

	ableToActive = true;
}

Enemy::Enemy(int enemy_health, int enemy_damage, int enemy_defence, string enemy_name) :
	buff()
{
	enemyHealth = enemyMaxHealth = enemy_health;
	enemyDamage = enemy_damage;
	enemyDefence = enemy_defence;
	enemyName = enemy_name;
	enemyAddDamage = 0;
	enemyHowToActive = 0;

	ableToActive = true;
}
Enemy::~Enemy() {}

void Enemy::enemyBeingHeal(int healNumber)
{
	enemyHealth += healNumber;
	if (enemyHealth > enemyMaxHealth)
		enemyHealth = enemyMaxHealth;
}
int Enemy::enemyBeingHurt(int hurtNumber)
{
	if (hurtNumber <= enemyDefence) {
		enemyDefence -= hurtNumber;
		return 0;
	}
	else if (enemyDefence > 0) {
		enemyHealth -= hurtNumber - enemyDefence;
		enemyDefence = 0;
		return 1;
	}
	else if (enemyDefence <= 0) {
		enemyHealth -= hurtNumber;
		enemyDefence = 0;
		return 2;
	}

}

void Enemy::enemyAttack(Player& player, int attackDamage)
{

	int enemyFinalDamage = 0;

	if (attackDamage == -1) {
		enemyFinalDamage = enemyDamage + enemyAddDamage;
	}
	else {
		enemyFinalDamage = attackDamage;
	}

	if (enemyFinalDamage <= 0) {
		cout << "对你的攻击未造成伤害。" << endl;
		postpone();
		return;
	}

	int playerDefenceRecord = player.playerDefence;
	int playerHealthRecord = player.playerHealth;
	int attackResultRecord = player.playerBeingHurt(enemyFinalDamage);

	if (attackResultRecord == 0) {
		cout << "对你的攻击未造成伤害，对护甲造成" << playerDefenceRecord - player.playerDefence << "点损伤。\n";
		postpone();
		return;
	}
	else if (attackResultRecord == 1) {
		cout << "对护甲造成" << playerDefenceRecord - player.playerDefence << "点损伤。";
		cout << "对你造成" << playerHealthRecord - player.playerHealth << "点伤害。\n";
		postpone();
		return;
	}
	else if (attackResultRecord == 2) {
		cout << "对你造成" << playerHealthRecord - player.playerHealth << "点伤害。\n";
		postpone();
		return;
	}

}


void Enemy::showEnemyMenu()
{
	print_();
	int healthLeftCompareMax = (double)enemyHealth / enemyMaxHealth * 10;
	if (healthLeftCompareMax > 10)
		healthLeftCompareMax = 10;
	cout << endl;
	cout << "敌方：" << enemyName << endl;
	//显示生命值
	cout << "生命 " << enemyHealth;
	cout << "   \t|";
	for (int i = 0; i < healthLeftCompareMax; i++) cout << "▲";
	for (int i = 0; i < 20 - 2 * healthLeftCompareMax; i++) cout << " ";
	cout << "";
	cout << " MAX " << enemyMaxHealth;
	cout << endl;

	//显示护甲值
	int showDefence = enemyDefence / 10;
	cout << "护甲 " << enemyDefence;
	cout << "    \t|";
	if (showDefence > 10)
		showDefence = 10;
	for (int i = 0; i < showDefence; i++) cout << "▼";
	cout << endl;

	//显示攻击力
	int showAttack = enemyDamage / 10;
	cout << "攻击 " << enemyDamage;
	if (buff.BuffID == 3) {
		cout << "+" << buff.Level * 10;
	}
	if (buff.BuffID == 4) {
		cout << "-" << buff.Level * 5;
	}
	cout << "    \t|";
	if (showAttack > 10)
		showAttack = 10;
	for (int i = 0; i < showAttack; i++) cout << "◆";
	cout << endl;

	cout << endl << "|";
	switch (enemyHowToActive) {
	case 0:
		cout << "敌人下一回合无法行动\n";
		break;
	case 1:
		cout << "敌人下一回合将进行攻击\n";
		break;
	case 2:
		cout << "敌人下一回合将进行格挡\n";
		break;
	case 3:
		cout << "敌人下一回合将进行治疗\n";
		break;
	case 4:
		cout << "敌人下一回合将使用技能\n";
		break;
	}
	print_();
	cout << endl;
}
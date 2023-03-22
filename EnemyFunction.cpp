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
		cout << "����Ĺ���δ����˺���" << endl;
		postpone();
		return;
	}

	int playerDefenceRecord = player.playerDefence;
	int playerHealthRecord = player.playerHealth;
	int attackResultRecord = player.playerBeingHurt(enemyFinalDamage);

	if (attackResultRecord == 0) {
		cout << "����Ĺ���δ����˺����Ի������" << playerDefenceRecord - player.playerDefence << "�����ˡ�\n";
		postpone();
		return;
	}
	else if (attackResultRecord == 1) {
		cout << "�Ի������" << playerDefenceRecord - player.playerDefence << "�����ˡ�";
		cout << "�������" << playerHealthRecord - player.playerHealth << "���˺���\n";
		postpone();
		return;
	}
	else if (attackResultRecord == 2) {
		cout << "�������" << playerHealthRecord - player.playerHealth << "���˺���\n";
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
	cout << "�з���" << enemyName << endl;
	//��ʾ����ֵ
	cout << "���� " << enemyHealth;
	cout << "   \t|";
	for (int i = 0; i < healthLeftCompareMax; i++) cout << "��";
	for (int i = 0; i < 20 - 2 * healthLeftCompareMax; i++) cout << " ";
	cout << "";
	cout << " MAX " << enemyMaxHealth;
	cout << endl;

	//��ʾ����ֵ
	int showDefence = enemyDefence / 10;
	cout << "���� " << enemyDefence;
	cout << "    \t|";
	if (showDefence > 10)
		showDefence = 10;
	for (int i = 0; i < showDefence; i++) cout << "��";
	cout << endl;

	//��ʾ������
	int showAttack = enemyDamage / 10;
	cout << "���� " << enemyDamage;
	if (buff.BuffID == 3) {
		cout << "+" << buff.Level * 10;
	}
	if (buff.BuffID == 4) {
		cout << "-" << buff.Level * 5;
	}
	cout << "    \t|";
	if (showAttack > 10)
		showAttack = 10;
	for (int i = 0; i < showAttack; i++) cout << "��";
	cout << endl;

	cout << endl << "|";
	switch (enemyHowToActive) {
	case 0:
		cout << "������һ�غ��޷��ж�\n";
		break;
	case 1:
		cout << "������һ�غϽ����й���\n";
		break;
	case 2:
		cout << "������һ�غϽ����и�\n";
		break;
	case 3:
		cout << "������һ�غϽ���������\n";
		break;
	case 4:
		cout << "������һ�غϽ�ʹ�ü���\n";
		break;
	}
	print_();
	cout << endl;
}
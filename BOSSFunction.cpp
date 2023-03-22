#include "TotalHead.h"

BOSS::BOSS(int enemy_health, int enemy_damage, int enemy_defence, string enemy_name, int skillType) :
	BOSSSkill(), Enemy(enemy_health, enemy_damage, enemy_defence, enemy_name)
{
	BOSSSkill.setEnemySkillTo(skillType);
}

BOSS::BOSS() : Enemy(), BOSSSkill()
{
}

BOSS::~BOSS() {}

void BOSS::showEnemyMenu()
{
	print_();
	int healthLeftCompareMax = (double)enemyHealth / enemyMaxHealth * 10;
	if (healthLeftCompareMax > 10)
		healthLeftCompareMax = 10;
	cout << endl;
	cout << enemyName << endl;
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

	cout << "技能：" << BOSSSkill.enemySkill.skillName << BOSSSkill.enemySkill.skillDescirbe << endl;

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
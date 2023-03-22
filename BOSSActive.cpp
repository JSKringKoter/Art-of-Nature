#include "TotalHead.h"

void BOSS::BOSSActive(Player& player)
{
	cout << "\n|敌方回合|\n";
	print_();
	postpone();

	BuffEffect();

	switch (enemyHowToActive) {
	case 0:
		cout << "\n敌人无法行动。\n";
		postpone();
		break;

	case 1:
		cout << "\n敌人进行了攻击。\n";
		postpone();
		enemyAttack(player);
		break;

	case 2:
		cout << "\n敌人进行了格挡。\n";
		postpone();
		cout << "敌人的护甲增加了" << (int)(enemyDamage * 0.8) << "点。\n";
		postpone();
		enemyDefence += (int)(enemyDamage * 0.8);
		break;

	case 3:
		cout << "\n敌人进行了治疗。";
		postpone();
		cout << "\n敌人治疗了" << (int)(enemyMaxHealth * 0.1) << "点生命值。\n";
		postpone();
		enemyBeingHeal(enemyMaxHealth * 0.1);
		break;

	case 4:
		cout << "\n敌人使用了技能：" << BOSSSkill.enemySkill.skillName << endl;
		postpone();
		BOSSUseSkill(player);
		break;
	}

	cout << "敌方回合结束。\n";
	print_();
	printEndl();
	postpone(2);
	isBuffOver();
}
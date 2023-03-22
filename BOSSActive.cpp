#include "TotalHead.h"

void BOSS::BOSSActive(Player& player)
{
	cout << "\n|�з��غ�|\n";
	print_();
	postpone();

	BuffEffect();

	switch (enemyHowToActive) {
	case 0:
		cout << "\n�����޷��ж���\n";
		postpone();
		break;

	case 1:
		cout << "\n���˽����˹�����\n";
		postpone();
		enemyAttack(player);
		break;

	case 2:
		cout << "\n���˽����˸񵲡�\n";
		postpone();
		cout << "���˵Ļ���������" << (int)(enemyDamage * 0.8) << "�㡣\n";
		postpone();
		enemyDefence += (int)(enemyDamage * 0.8);
		break;

	case 3:
		cout << "\n���˽��������ơ�";
		postpone();
		cout << "\n����������" << (int)(enemyMaxHealth * 0.1) << "������ֵ��\n";
		postpone();
		enemyBeingHeal(enemyMaxHealth * 0.1);
		break;

	case 4:
		cout << "\n����ʹ���˼��ܣ�" << BOSSSkill.enemySkill.skillName << endl;
		postpone();
		BOSSUseSkill(player);
		break;
	}

	cout << "�з��غϽ�����\n";
	print_();
	printEndl();
	postpone(2);
	isBuffOver();
}
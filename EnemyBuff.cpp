#include "TotalHead.h"

/*
Buff��Ч
0 = ��
1 = ��Ĭ
2 = �����˺�
3 = ����
4 = ����
*/
void Enemy::BuffEffect()
{

	int healthRecord = 0;

	switch (buff.BuffID) {
	case 1:
		ableToActive = false;
		enemyHowToActive = 0;
		buff.Rend--;
		break;
	case 2:
		healthRecord = enemyHealth;
		enemyBeingHurt(25 * buff.Level);
		cout << "�������˺��������ܵ���" << healthRecord - enemyHealth << "���˺�\n";
		postpone();
		buff.Level--;
		buff.Rend--;
		break;
	case 3:
		enemyAddDamage += 10 * buff.Level;
		buff.Rend--;
		break;
	case 4:
		enemyAddDamage -= 5 * buff.Level;
		buff.Rend--;
		break;
	}
}

void Enemy::isBuffOver()
{

		if (buff.Rend <= 0 && buff.isHasBuff == true) {

			cout << "���� " << buff.BuffName << " Ч����ʧЧ" << endl;
			postpone();

			buff.BuffName = "None";
			buff.BuffID = 0;
			buff.Level = 0;
			buff.Rend = 0;

			buff.isHasBuff = false;
			enemyAddDamage = 0;

			return;
		}


}
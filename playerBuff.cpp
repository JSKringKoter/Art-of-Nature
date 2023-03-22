#include "TotalHead.h"

/*
Buff��Ч
0 = ��
1 = ��Ĭ
2 = �����˺�
3 = ����
4 = ����
5 = ����
*/
void Player::BuffEffect()
{

	int playerHealthRecord = 0;

	switch (buff.BuffID) {
	case 1:
		ableToActive = false;
		buff.Rend--;

		cout << "\n�㱻��Ĭ�ˣ��޷��ж���    ��Ĭʣ��غϣ�" << buff.Rend + 1 << endl;
		postpone();
		break;
	case 2:
		playerHealthRecord = playerHealth;
		playerBeingHurt(25 * buff.Level);
		cout << "�ܵ������˺�Ч��������ֵ��ʧ" << playerHealthRecord - playerHealth << endl;

		buff.Level--;
		buff.Rend--;
		break;
	case 3:
		playerAddDamage = playerDamage * 0.1 * buff.Level;
		buff.Rend--;
		break;
	case 4:
		playerAddDamage = 5 * buff.Level;
		buff.Rend--;
		break;
	}
}

void Player::isBuffOver()
{

	if (buff.Rend <= 0 && buff.isHasBuff == true) {

		cout << buff.BuffName << " Ч����ʧЧ" << endl;

		buff.BuffName = "None";
		buff.BuffID = 0;
		buff.Level = 0;
		buff.Rend = 0;

		buff.isHasBuff = false;
		playerAddDamage = 0;

		return;
	}

}
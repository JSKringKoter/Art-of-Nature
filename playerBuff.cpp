#include "TotalHead.h"

/*
Buff生效
0 = 无
1 = 沉默
2 = 持续伤害
3 = 力量
4 = 虚弱
5 = 反伤
*/
void Player::BuffEffect()
{

	int playerHealthRecord = 0;

	switch (buff.BuffID) {
	case 1:
		ableToActive = false;
		buff.Rend--;

		cout << "\n你被沉默了，无法行动。    沉默剩余回合：" << buff.Rend + 1 << endl;
		postpone();
		break;
	case 2:
		playerHealthRecord = playerHealth;
		playerBeingHurt(25 * buff.Level);
		cout << "受到持续伤害效果，生命值损失" << playerHealthRecord - playerHealth << endl;

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

		cout << buff.BuffName << " 效果已失效" << endl;

		buff.BuffName = "None";
		buff.BuffID = 0;
		buff.Level = 0;
		buff.Rend = 0;

		buff.isHasBuff = false;
		playerAddDamage = 0;

		return;
	}

}
#include "TotalHead.h"

/*
Buff生效
0 = 无
1 = 沉默
2 = 持续伤害
3 = 力量
4 = 虚弱
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
		cout << "【持续伤害】敌人受到了" << healthRecord - enemyHealth << "点伤害\n";
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

			cout << "敌人 " << buff.BuffName << " 效果已失效" << endl;
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
#include "TotalHead.h"

//若要去除第四种情况（技能），将case3 = 101且不传递case4
void Enemy::defineHowToActive(int case1, int case2, int case3, int case4)
{

	if (buff.BuffID == 1 && buff.Rend - 1 > 0) {
		enemyHowToActive = 0;
	}

	srand((unsigned)time(0));

	FLAG:
	int define = rand() % 101;

	/*
1 = 攻击
2 = 格挡
3 = 治疗
*/
	if (1 <= define && define < case1)
		enemyHowToActive = 1;
	else if (case1 <= define && define < case2)
		enemyHowToActive = 2;
	else if (case2 <= define && define < case3)
		enemyHowToActive = 3;
	else if (case3 <= define && define <= case4)
		enemyHowToActive = 4;


	//一些限制条件
	//生命值满，不进行治疗
	if (enemyHealth == enemyMaxHealth && enemyHowToActive == 3)
		goto FLAG;
	//生命值大于70%，不使用技能
	if (enemyHealth >= enemyMaxHealth * 0.7 && enemyHowToActive == 4)
		goto FLAG;
}

/*
1 = 攻击
2 = 格挡
3 = 治疗
*/
void Enemy::enemyActive(Player& player)
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
		cout << "\n敌人进行了治疗";
		postpone();
		cout << "\n敌人治疗了" << (int)(enemyMaxHealth * 0.1) << "点生命值。\n";
		postpone();
		enemyBeingHeal(enemyMaxHealth * 0.1);
		break;

	}

	cout << "敌方回合结束。\n";
	print_();
	printEndl();
	postpone(2);
	isBuffOver();
}
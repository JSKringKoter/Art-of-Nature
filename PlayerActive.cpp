#include "TotalHead.h"

int Player::PlayerActive(Enemy& enemy)
{

	if (playerHealth <= 0) {
		cout << "你在与" << enemy.enemyName << "的战斗中死亡。" << endl;
		return 0;
	}


	BuffEffect();

	if (ableToActive == false) {
		ableToActive = true;

		isBuffOver();
		return 10;
	}

	cout << "\n|你的回合|\n";
	postpone();
	enemy.showEnemyMenu();
	postpone(1);
	cout << "|                  战斗中                  |\n";
	postpone(1);
	playerShowMenu();
	int howToActive;

	FLAG:
	cout << "|1：攻击  " << "|2：打开背包  " << "|3：核心列表\n";

	howToActive = 0;

	countInChoice(howToActive);
	while (howToActive < 1 || howToActive > 3) {
		cout << "\n无效的选项，重新选择：";
		countInChoice(howToActive);
	}

	//普通攻击
	if (howToActive == 1) {
		playerAttack(enemy);
	}

	//使用道具
	else if (howToActive == 2) {
		if (!playerUseItem(enemy)) {
			goto FLAG;
		}
		if (enemy.enemyHealth <= 0) {
			goto FLAG2;
		}
		goto FLAG;
	}

	//使用核心技能
	else if (howToActive == 3) {
		if (!playerUseCore(enemy)) {
			goto FLAG;
		}
		if (enemy.enemyHealth <= 0) {
			goto FLAG2;
		}
	}

	cout << "\n你的回合结束了。" << endl;
	isBuffOver();

	FLAG2:
	if (enemy.enemyHealth <= 0) {
		postpone();
		cout << "\n你战胜了敌人。" << endl;
		postpone();

		cout << "获得了" << (int)(enemy.enemyMaxHealth * 0.2) << "水晶。\n";
		crystal += (int)(enemy.enemyMaxHealth * 0.2);
		playerBeingHeal(playerMaxHealth / 5);

		print_();
		printEndl();

		ableToActive = true;
		playerEnergy = playerMaxEnergy;
		return 2;
	}

	postpone();
	cout << "能量恢复" << playerMaxEnergy / 8 << "点。\n";
	playerAddEnergy(playerMaxEnergy / 8);
	ableToActive = true;

	print_();
	printEndl();
	postpone(2);
	return 1;
}
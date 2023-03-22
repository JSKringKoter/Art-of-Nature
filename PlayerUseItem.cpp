#include "TotalHead.h"


/*
0 = 空
1 = 生命药剂
2 = 能量药剂
3 = 力量药剂
4 = 防御药剂
5 = 高爆炸药（120伤害）
6 = 寒冰之矛（30伤害，沉默一回合）
7 = 熔岩烧瓶（50伤害，20减攻一回合）
*/
int Player::playerUseItem(Enemy& enemy)
{
	backPack.showBackpackItems();
	cout << "\n|物品前序号：使用  |6：退出" << endl;

	int choice = 0;
	countInChoice(choice);

	while (choice < 1 || choice > MAXBackpackContains + 1) {
		cout << "无效的选项，重新选择：";
		countInChoice(choice);
	}

	if (choice == MAXBackpackContains + 1) {
		print_();
		cout << endl;
		return 0;
	}
		
	int choiceID = backPack.items[choice - 1].ID;

	//格子中没有物品，再次要求选择
	while (choiceID == 0) {

		cout << "格子中没有物品，重新选择或退出：";

		countInChoice(choice);

		while (choice < 1 || choice > MAXBackpackContains + 1) {
			cout << "无效的选项，重新选择：";
			countInChoice(choice);
		}

		if (choice == MAXBackpackContains + 1) {
			print_();
			cout << endl;
			return 0;
		}

		choiceID = backPack.items[choice - 1].ID;
	}

	switch (choiceID) {
	case 1:
		playerBeingHeal(playerMaxHealth * 0.25);
		break;
	case 2:
		playerAddEnergy(playerMaxEnergy * 0.3);
		break;
	case 3:
		buff.BuffUpdate(3, 2, 1);
		BuffEffect();
		break;
	case 4:
		playerAttack(enemy, 120);
		break;
	case 5:
		playerAttack(enemy, 30);
		enemy.buff.BuffUpdate(1, 1, 1);
		break;
	case 6:
		playerAttack(enemy, 50);
		enemy.buff.BuffUpdate(4, 1, 4);
		break;
	case 7:
		playerDefence += 60;
		break;
	}

	cout << "使用了 " << backPack.items[choice - 1].itemName << endl << endl;
	postpone();
	backPack.items[choice - 1].itemNumber--;

	if (backPack.items[choice - 1].itemNumber <= 0) {
		backPack.resetItem(choice);

		for (int i = choice - 1; i < MAXBackpackContains - 1; i++) {
			backPack.items[i] = backPack.items[i + 1];
		}
	}
	
	return 1;
}
/*
0 = 空
1 = 生命药剂
2 = 能量药剂
3 = 力量药剂
4 = 高爆炸药（120伤害）
5 = 寒冰之矛（30伤害，沉默一回合）
6 = 熔岩烧瓶（50伤害，20减攻一回合）
*/
#include "TotalHead.h"

int Player::playerUseCore(Enemy& enemy)
{
	playerCore.showCoreLIst();

	//显示能量
	int EnergyLeftCompareMax = (double)playerEnergy / playerMaxEnergy * 10;
	if (EnergyLeftCompareMax > 10)
		EnergyLeftCompareMax = 10;
	cout << "能量 " << playerEnergy;
	cout << "   \t|";
	for (int i = 0; i < EnergyLeftCompareMax; i++) cout << "○";
	for (int i = 0; i < 20 - 2 * EnergyLeftCompareMax; i++) cout << " ";
	cout << "";
	cout << " MAX " << playerMaxEnergy;
	cout << endl;
	cout << "|核心前序号：使用  |4：退出\n";

	int choice = 0;
	FLAG:
	countInChoice(choice);

	if (choice < 1 || choice > 4) {
		cout << "无效的选项，重新输入：";
		goto FLAG;
	}
	else if (playerCore.cores[choice - 1].coreID == 0) {
		cout << "格子中没有核心，请重新输入：";
		goto FLAG;
	}

	if (choice == 4) {
		print_();
		cout << endl;
		return 0;
	}

	int choiceID = playerCore.cores[choice - 1].coreID;

	if (playerEnergy < playerCore.cores[choice - 1].costEnergy) {
		cout << "能量不足，无法使用核心\n\n";
		return 0;
	}

	int playerTotalDamage = playerDamage + playerAddDamage;
	int enemyTotalHurt = enemy.enemyMaxHealth - enemy.enemyHealth;
	int damageRecord = 0;

	switch (choiceID) {
	//狱炎
	case 1:
		cout << "\n试试来自地狱的怒火！\n";
		postpone();
		playerAttack(enemy, (int)playerTotalDamage * 1.4);
		if ((double)enemy.enemyHealth / (double)enemy.enemyMaxHealth > 0.7) {
			cout << "\n让怒火焚烧一切！\n";
			postpone();
			playerAttack(enemy, (int)playerTotalDamage * 1.4);
		}

		break;
	//惊鸿
	case 2:
		cout << "\n轻若鸿毛，灿若惊鸿。\n";
		postpone();
		playerAttack(enemy, (int)playerTotalDamage * 1.6);
		playerBeingHeal((int)playerMaxHealth * 0.15);

		break;
	//暮光
	case 3:
		cout << "\n“天色渐晚，行路将熄。”\n";
		postpone();
		playerAttack(enemy, (int)enemyTotalHurt * 0.3);

		break;
	//黎明
	case 4:
		cout << "\n“黎明将至。”\n";
		postpone();
		cout << "“曙光将荡涤邪恶。”\n";
		postpone();
		playerBeingHeal((int)playerMaxHealth * 0.3);
		enemy.buff.BuffUpdate(1, 1, 1);

		break;
	//空山
	case 5:
		cout << "\n“千山鸟飞绝，万径人踪灭。”\n";
		postpone();
		enemy.buff.BuffUpdate(1, 2, 1);

		break;
	//陈年
	case 6:
		cout << "\n“陈年的百宝箱！”\n";
		postpone();
		for (int i = 0; i < MAXBackpackContains; i++) {
			if (backPack.items[i].ID == 0) 
				break;
			else if (backPack.items[i].ID != 0) 
				backPack.items[i].itemNumber++;
		}

		break;

    //回音
	case 7:
		cout << "\n“回音不绝于耳，琴声依旧。”\n";
		postpone();
		damageRecord = (int)playerHealth * 0.1;
		playerBeingHurt(damageRecord);
		playerAttack(enemy, damageRecord * 1.8);
	}

	playerEnergy -= playerCore.cores[choice - 1].costEnergy;
	if (playerEnergy <= 0)
		playerEnergy = 0;

	return 1;
}
//
//核心信息
/*
locate = 格子原始位置
0 = 无
1 = 【狱炎】对目标造成140%伤害，若目标生命大于70%，再造成一次伤害。消耗40能量。
2 = 【惊鸿】对目标造成160%伤害，恢复15%生命。消耗50能量。
3 = 【暮光】对目标造成已损生命的30%伤害。消耗80能量。
4 = 【黎明】恢复30%生命，沉默目标1回合。消耗70能量。
5 = 【空山】沉默目标2回合，消耗60能量。
6 = 【陈年】背包中所有物品个数+1。消耗80能量。
*/
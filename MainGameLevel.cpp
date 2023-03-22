#include "TotalHead.h"

int main()
{

	Player player;
	int healthLevel = 0;
	int damageLevel = 0;
	int defenceLevel = 0;
	int energyLevel = 0;

FLAG114515:
	readSave(healthLevel, damageLevel, defenceLevel, energyLevel);
	int health = 100 + healthLevel * 30;
	int damage = 10 + damageLevel * 5;
	int defence = 50 + defenceLevel * 10;
	int energy = 100 + energyLevel * 10;

	int choice = printTital();
	switch (choice) {
	case 1:
		player = Player(health, damage, defence, energy, "范天工");
		break;
	case 2:
		cout << "输入生命值：";
		countInChoice(health);
		cout << "输入攻击力：";
		countInChoice(damage);
		cout << "输入护甲值：";
		countInChoice(defence);
		cout << "输入能量值：";
		countInChoice(energy);
		player = Player(health, damage, defence, energy, "范天工");
		break;
	case 3:
		makeRand(10, 200, 5, 50, 10, 100, health, damage, defence);
		player = Player(health, damage, defence, energy, "范天工");
		break;
	case 4:
		return 0;
	}

	player.crystal = 1000;

	cout << "正在生成角色……\n\n";
	postpone();

	cout << "\n\n\n|你的信息|\n";
	player.playerShowMenu();

	cout << "|1：不满意？Remake吧！\n";
	cout << "|2：准备万全，开始冒险。\n";
	int choice114514 = 0;

FLAG114514:
	countInChoice(choice114514);
	if (choice114514 != 1 && choice114514 != 2) {
		goto FLAG114514;
	}
	if (choice114514 == 1) {
		goto FLAG114515;
	}
	int levelResult1_1 =  level1_1(player);
	if (levelResult1_1 == 0)
		goto FLAG;


FLAG:

	Upgrade(player, healthLevel, damageLevel, defenceLevel, energyLevel);
	cout << "\n\n\n游戏结束。\n\n\n";

	system("pause");
	return 0;
}

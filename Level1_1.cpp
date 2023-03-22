#include "TotalHead.h"

int level1_1(Player& player)
{
	srand((unsigned)time(0));

	print_();
	cout << "\n|                |关卡1-1|                 |\n";
	cout << "|              ◆ 繁茂草原 ◆              |\n";
	print_();
	cout << endl;
	postpone(2);
	
	textFile1_1_1();

	int getItem = rand() % (itemTypeNumber + 1);
	player.backPack.addBackpack(getItem, 1);
	
	textFile1_1_0();

	int whatEnemyToFight = rand() % 3;
	Enemy enemy;
	BOSS boss;

	//草原法师，草原杂兵
	if (whatEnemyToFight == 1){
		enemy = GrassCommonSoldier();
	}
	else {
		enemy = GrassMaster();
	}

	int fightResult = fightWithEnemy(player, enemy);
	if (fightResult == 0)
		return 0;

	textFile1_1_2();

	int defineCore = rand() % 7 + 1;
	player.playerCore.addToCoreList(defineCore);

	int moveCount = 0;
	int defineWhatToMeet = 0;
	int fightwithboss = 0;

	while (moveCount <= 4) {

		defineWhatToMeet = rand() % 3;

		//决定是否与精英怪战斗
		if (moveCount > 2 || defineWhatToMeet == 0) {
			if (defineWhatToMeet == 0 || defineWhatToMeet == 1)
				boss = GrassUpgradeMaster();
			fightwithboss = 1;
		}
		//决定是否与敌人战斗
		else if (defineWhatToMeet == 0 || defineWhatToMeet == 1) {
			whatEnemyToFight = rand() % 3;
			switch (whatEnemyToFight) {
			case 0:
				enemy = GrassCommonSoldier();
				break;
			case 1:
				enemy = GrassMaster();
				break;
			case 2:
				enemy = GrassDefener();
				break;
			}
			cout << "|你继续向前走，前面出现了敌人。\n";
			postpone();



			if (fightwithboss == 1) {
				fightResult = fightWithBOSS(player, boss);
				fightwithboss = 0;
				if (fightResult == 0)
					return 0;
			}
			else {
				fightResult = fightWithEnemy(player, enemy);
				if (fightResult == 0)
					return 0;
			}
		}

		//决定是否遇到宝藏
		else if (defineWhatToMeet == 2) {
			meetTreature(player);
		}

		moveCount++;
	}

	cout << "\n\n遭遇了BOSS！\n";
	postpone();

	BOSS FinalBoss;
	FinalBoss = GrassBOSS();
	fightResult = fightWithBOSS(player, FinalBoss);
	if (fightResult == 0)
		return 0;


	textFile1_1_3();
	meetBussiness(player);

	return 1;
}
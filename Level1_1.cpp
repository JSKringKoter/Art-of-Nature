#include "TotalHead.h"

int level1_1(Player& player)
{
	srand((unsigned)time(0));

	print_();
	cout << "\n|                |�ؿ�1-1|                 |\n";
	cout << "|              �� ��ï��ԭ ��              |\n";
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

	//��ԭ��ʦ����ԭ�ӱ�
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

		//�����Ƿ��뾫Ӣ��ս��
		if (moveCount > 2 || defineWhatToMeet == 0) {
			if (defineWhatToMeet == 0 || defineWhatToMeet == 1)
				boss = GrassUpgradeMaster();
			fightwithboss = 1;
		}
		//�����Ƿ������ս��
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
			cout << "|�������ǰ�ߣ�ǰ������˵��ˡ�\n";
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

		//�����Ƿ���������
		else if (defineWhatToMeet == 2) {
			meetTreature(player);
		}

		moveCount++;
	}

	cout << "\n\n������BOSS��\n";
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
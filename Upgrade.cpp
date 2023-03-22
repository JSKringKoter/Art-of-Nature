#include "TotalHead.h"

void Upgrade(Player& player, int healthLevel, int damageLevel, int defenceLevel, int energyLevel)
{

	postpone(2);
	cout << "\n\n\n\n\n\n游戏结束，选择升级类型：" << endl;

	print_();
	cout << endl;

	//
	cout << "◆1:升级生命值    |每级增加30最大生命。| 消耗100水晶|" << endl;
	cout << "|";
	for (int i = 0; i < healthLevel; i++) {
		cout << "▲";
	}
	if (healthLevel == 10)
		cout << "\n|满级\n\n";
	else
	  cout << "\n|当前等级：" << healthLevel << "最大等级：10\n\n";
	 
	cout << "◆2:升级攻击力    |每级增加5初始攻击力。| 消耗100水晶|" << endl;
	cout << "|";
	for (int i = 0; i < damageLevel; i++) {
		cout << "◆";
	}
	if (damageLevel == 10)
		cout << "\n|满级\n\n";
	else
	    cout << "\n|当前等级：" << damageLevel << "最大等级：10\n\n";

	cout << "◆3:升级护甲值    |每级增加10初始护甲。| 消耗100水晶|" << endl;
	cout << "|";
	for (int i = 0; i < defenceLevel; i++) {
		cout << "▼";
	}
	if (defenceLevel == 10)
		cout << "\n|满级\n\n";
	else
	    cout << "\n|当前等级：" << defenceLevel << "最大等级：10\n\n";

	cout << "◆4:升级能量槽    |每级增加10最大能量。| 消耗100水晶|" << endl;
	cout << "|";
	for (int i = 0; i < energyLevel; i++) {
		cout << "○";
	}
	if (energyLevel == 10)
		cout << "\n|满级\n\n";
	else
	    cout << "\n|当前等级：" << energyLevel << "最大等级：10\n";
	//

	print_();
	cout << endl;



	int choice = 0;

	cout << "当前水晶★：" << player.crystal << endl;
FLAG1:
	postpone();
	cout << "|选择前数字+回车：升级    5：取消\n";

FLAG:
	countInChoice(choice);
	if (choice < 1 || choice > 5)
		goto FLAG;

	switch (choice) {
	case 1:
		if (healthLevel >= 10) {
			cout << "生命值已满级。\n";
			goto FLAG1;
		}
		else if (player.crystal < 100) {
			cout << "水晶不足。\n";
			goto FLAG1;
		}

		cout << "最大生命值升级！  剩余水晶：" << player.crystal - 100<< endl;
		player.crystal -= 100;
		healthLevel++;
		goto FLAG1;
		break;


	case 2:
		if (damageLevel >= 10) {
			cout << "攻击力已满级。\n";
			goto FLAG1;
		}
		else if (player.crystal < 100) {
			cout << "水晶不足。\n";
			goto FLAG1;
		}

		cout << "初始攻击力升级！  剩余水晶：" << player.crystal - 100<< endl;
		player.crystal -= 100;
		damageLevel++;
		goto FLAG1;
		break;


	case 3:
		if (defenceLevel >= 10) {
			cout << "护甲已满级。\n";
			goto FLAG1;
		}
		else if (player.crystal < 100) {
			cout << "水晶不足。\n";
			goto FLAG1;
		}

		cout << "初始护甲升级！  剩余水晶：" << player.crystal - 100<< endl;
		player.crystal -= 100;
		defenceLevel++;
		goto FLAG1;
		break;


	case 4:
		if (energyLevel >= 10) {
			cout << "能量槽已满级。\n";
			goto FLAG1;
		}
		else if (player.crystal < 100) {
			cout << "水晶不足。\n";
			goto FLAG1;
		}

		cout << "能量值升级！  剩余水晶：" << player.crystal - 100<< endl;
		player.crystal -= 100;
		energyLevel++;
		goto FLAG1;
		break;

	case 5:
		break;
	}
	writeSave(healthLevel, damageLevel, defenceLevel, energyLevel);
}
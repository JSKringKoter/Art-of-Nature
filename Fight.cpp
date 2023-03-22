#include "TotalHead.h"

int fightWithEnemy(Player& player, Enemy& enemy)
{

	cout << "|回车：开始战斗\n";
	eatLine();

	int choice = 0;
	while (1)
	{
		enemy.defineHowToActive(60, 80, 101);
		int fightResult = player.PlayerActive(enemy);

		if (fightResult == 0) { //0 = 失败
			return 0;
		}
		else if (fightResult == 2) { //2 = 胜利


			cout << "◆1:全能提升  |提升10%最大生命值，提升10%攻击力。\n";
			cout << "◆2:枪械专精提升  |提升20%攻击力。\n";
			cout << "◆3:防御专精提升  |提升10%最大生命值， 护甲值增加10%最大生命值。\n";
			cout << "请选择一项升级：";
		FLAG:
			countInChoice(choice);


			if (choice < 1 && choice > 3) {
				cout << "无效的选项，重新输入：";
				goto FLAG;
			}

			if (choice == 1) {

				cout << "\n\n全能提升！生命值提升" << (int)(player.playerMaxHealth * 0.1);
				postpone(0.8);
				cout << "  攻击力提升" << (int)(player.playerDamage * 0.1) << endl;
				player.playerMaxHealth += (int)(player.playerMaxHealth * 0.1);
				player.playerHealth += (int)(player.playerMaxHealth * 0.1);

				player.playerDamage += (int)(player.playerDamage * 0.1);
			}
			else if (choice == 2) {

				cout << "\n\n枪械专精提升！攻击力提升" << (int)(player.playerDamage * 0.2) << endl;
				player.playerDamage += (int)(player.playerDamage * 0.2);
			}
			else if (choice == 3) {

				cout << "\n\n防御专精提升！生命值提升" << (int)(player.playerMaxHealth * 0.1);
				postpone(0.8);

				player.playerHealth += (int)(player.playerMaxHealth * 0.1);
				player.playerMaxHealth += (int)(player.playerMaxHealth * 0.1);
				player.playerDefence += (int)(player.playerMaxHealth * 0.1);

				cout << "  护甲值提升" << (int)(player.playerMaxHealth * 0.1) << endl << endl;
			}
			postpone(2);
			return 2;
		}
		enemy.enemyActive(player);
	}
}




int fightWithBOSS(Player& player, BOSS& enemy)
{
	cout << "|回车：开始战斗\n";
	eatLine();

	int choice = 0;
	while (1)
	{
		enemy.defineHowToActive(30, 60, 80);
		int fightResult = player.PlayerActive(enemy);

		if (fightResult == 0) { //0 = 失败
			return 0;
		}
		else if (fightResult == 2) { //2 = 胜利

			cout << "◆1:全能大提升  |提升20%最大生命值，提升15%攻击力。\n";
			cout << "◆2:能量提升  |提升20%最大能量。\n";
			cout << "◆3:金金金金钱钱钱钱！ |水晶数量增加300。\n";
			cout << "请选择一项升级：";

		FLAG:
			countInChoice(choice);


			if (choice < 1 && choice > 3) {
				cout << "无效的选项，重新输入：";
				goto FLAG;
			}

			if (choice == 1) {

				cout << "\n\n全能提升！生命值提升" << (int)(player.playerMaxHealth * 0.2);
				postpone(0.8);
				cout << "  攻击力提升" << (int)(player.playerDamage * 0.15) << endl;
				player.playerHealth += (int)(player.playerMaxHealth * 0.2);
				player.playerMaxHealth += (int)(player.playerMaxHealth * 0.2);

				player.playerDamage += (int)(player.playerDamage * 0.15);
			}
			else if (choice == 2) {

				cout << "\n\n能量提升！能量值提升" << (int)(player.playerMaxEnergy * 0.2) << endl;
				player.playerEnergy += (int)(player.playerMaxEnergy * 0.2);
				player.playerMaxEnergy += (int)(player.playerMaxEnergy * 0.2);
			}
			else if (choice == 3) {

				cout << "\n\n你变得富有了，获得了300水晶。\n";
				player.crystal += 300;
			}
			postpone(2);
			return 2;
		}

		enemy.BOSSActive(player);

	}
}
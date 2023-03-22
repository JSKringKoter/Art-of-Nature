#include "TotalHead.h"

int fightWithEnemy(Player& player, Enemy& enemy)
{

	cout << "|�س�����ʼս��\n";
	eatLine();

	int choice = 0;
	while (1)
	{
		enemy.defineHowToActive(60, 80, 101);
		int fightResult = player.PlayerActive(enemy);

		if (fightResult == 0) { //0 = ʧ��
			return 0;
		}
		else if (fightResult == 2) { //2 = ʤ��


			cout << "��1:ȫ������  |����10%�������ֵ������10%��������\n";
			cout << "��2:ǹеר������  |����20%��������\n";
			cout << "��3:����ר������  |����10%�������ֵ�� ����ֵ����10%�������ֵ��\n";
			cout << "��ѡ��һ��������";
		FLAG:
			countInChoice(choice);


			if (choice < 1 && choice > 3) {
				cout << "��Ч��ѡ��������룺";
				goto FLAG;
			}

			if (choice == 1) {

				cout << "\n\nȫ������������ֵ����" << (int)(player.playerMaxHealth * 0.1);
				postpone(0.8);
				cout << "  ����������" << (int)(player.playerDamage * 0.1) << endl;
				player.playerMaxHealth += (int)(player.playerMaxHealth * 0.1);
				player.playerHealth += (int)(player.playerMaxHealth * 0.1);

				player.playerDamage += (int)(player.playerDamage * 0.1);
			}
			else if (choice == 2) {

				cout << "\n\nǹеר������������������" << (int)(player.playerDamage * 0.2) << endl;
				player.playerDamage += (int)(player.playerDamage * 0.2);
			}
			else if (choice == 3) {

				cout << "\n\n����ר������������ֵ����" << (int)(player.playerMaxHealth * 0.1);
				postpone(0.8);

				player.playerHealth += (int)(player.playerMaxHealth * 0.1);
				player.playerMaxHealth += (int)(player.playerMaxHealth * 0.1);
				player.playerDefence += (int)(player.playerMaxHealth * 0.1);

				cout << "  ����ֵ����" << (int)(player.playerMaxHealth * 0.1) << endl << endl;
			}
			postpone(2);
			return 2;
		}
		enemy.enemyActive(player);
	}
}




int fightWithBOSS(Player& player, BOSS& enemy)
{
	cout << "|�س�����ʼս��\n";
	eatLine();

	int choice = 0;
	while (1)
	{
		enemy.defineHowToActive(30, 60, 80);
		int fightResult = player.PlayerActive(enemy);

		if (fightResult == 0) { //0 = ʧ��
			return 0;
		}
		else if (fightResult == 2) { //2 = ʤ��

			cout << "��1:ȫ�ܴ�����  |����20%�������ֵ������15%��������\n";
			cout << "��2:��������  |����20%���������\n";
			cout << "��3:�����ǮǮǮǮ�� |ˮ����������300��\n";
			cout << "��ѡ��һ��������";

		FLAG:
			countInChoice(choice);


			if (choice < 1 && choice > 3) {
				cout << "��Ч��ѡ��������룺";
				goto FLAG;
			}

			if (choice == 1) {

				cout << "\n\nȫ������������ֵ����" << (int)(player.playerMaxHealth * 0.2);
				postpone(0.8);
				cout << "  ����������" << (int)(player.playerDamage * 0.15) << endl;
				player.playerHealth += (int)(player.playerMaxHealth * 0.2);
				player.playerMaxHealth += (int)(player.playerMaxHealth * 0.2);

				player.playerDamage += (int)(player.playerDamage * 0.15);
			}
			else if (choice == 2) {

				cout << "\n\n��������������ֵ����" << (int)(player.playerMaxEnergy * 0.2) << endl;
				player.playerEnergy += (int)(player.playerMaxEnergy * 0.2);
				player.playerMaxEnergy += (int)(player.playerMaxEnergy * 0.2);
			}
			else if (choice == 3) {

				cout << "\n\n���ø����ˣ������300ˮ����\n";
				player.crystal += 300;
			}
			postpone(2);
			return 2;
		}

		enemy.BOSSActive(player);

	}
}
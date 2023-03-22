#include "TotalHead.h"

int Player::PlayerActive(Enemy& enemy)
{

	if (playerHealth <= 0) {
		cout << "������" << enemy.enemyName << "��ս����������" << endl;
		return 0;
	}


	BuffEffect();

	if (ableToActive == false) {
		ableToActive = true;

		isBuffOver();
		return 10;
	}

	cout << "\n|��Ļغ�|\n";
	postpone();
	enemy.showEnemyMenu();
	postpone(1);
	cout << "|                  ս����                  |\n";
	postpone(1);
	playerShowMenu();
	int howToActive;

	FLAG:
	cout << "|1������  " << "|2���򿪱���  " << "|3�������б�\n";

	howToActive = 0;

	countInChoice(howToActive);
	while (howToActive < 1 || howToActive > 3) {
		cout << "\n��Ч��ѡ�����ѡ��";
		countInChoice(howToActive);
	}

	//��ͨ����
	if (howToActive == 1) {
		playerAttack(enemy);
	}

	//ʹ�õ���
	else if (howToActive == 2) {
		if (!playerUseItem(enemy)) {
			goto FLAG;
		}
		if (enemy.enemyHealth <= 0) {
			goto FLAG2;
		}
		goto FLAG;
	}

	//ʹ�ú��ļ���
	else if (howToActive == 3) {
		if (!playerUseCore(enemy)) {
			goto FLAG;
		}
		if (enemy.enemyHealth <= 0) {
			goto FLAG2;
		}
	}

	cout << "\n��ĻغϽ����ˡ�" << endl;
	isBuffOver();

	FLAG2:
	if (enemy.enemyHealth <= 0) {
		postpone();
		cout << "\n��սʤ�˵��ˡ�" << endl;
		postpone();

		cout << "�����" << (int)(enemy.enemyMaxHealth * 0.2) << "ˮ����\n";
		crystal += (int)(enemy.enemyMaxHealth * 0.2);
		playerBeingHeal(playerMaxHealth / 5);

		print_();
		printEndl();

		ableToActive = true;
		playerEnergy = playerMaxEnergy;
		return 2;
	}

	postpone();
	cout << "�����ָ�" << playerMaxEnergy / 8 << "�㡣\n";
	playerAddEnergy(playerMaxEnergy / 8);
	ableToActive = true;

	print_();
	printEndl();
	postpone(2);
	return 1;
}
#include "TotalHead.h"


/*
0 = ��
1 = ����ҩ��
2 = ����ҩ��
3 = ����ҩ��
4 = ����ҩ��
5 = �߱�ըҩ��120�˺���
6 = ����֮ì��30�˺�����Ĭһ�غϣ�
7 = ������ƿ��50�˺���20����һ�غϣ�
*/
int Player::playerUseItem(Enemy& enemy)
{
	backPack.showBackpackItems();
	cout << "\n|��Ʒǰ��ţ�ʹ��  |6���˳�" << endl;

	int choice = 0;
	countInChoice(choice);

	while (choice < 1 || choice > MAXBackpackContains + 1) {
		cout << "��Ч��ѡ�����ѡ��";
		countInChoice(choice);
	}

	if (choice == MAXBackpackContains + 1) {
		print_();
		cout << endl;
		return 0;
	}
		
	int choiceID = backPack.items[choice - 1].ID;

	//������û����Ʒ���ٴ�Ҫ��ѡ��
	while (choiceID == 0) {

		cout << "������û����Ʒ������ѡ����˳���";

		countInChoice(choice);

		while (choice < 1 || choice > MAXBackpackContains + 1) {
			cout << "��Ч��ѡ�����ѡ��";
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

	cout << "ʹ���� " << backPack.items[choice - 1].itemName << endl << endl;
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
0 = ��
1 = ����ҩ��
2 = ����ҩ��
3 = ����ҩ��
4 = �߱�ըҩ��120�˺���
5 = ����֮ì��30�˺�����Ĭһ�غϣ�
6 = ������ƿ��50�˺���20����һ�غϣ�
*/
#include "TotalHead.h"

int Player::playerUseCore(Enemy& enemy)
{
	playerCore.showCoreLIst();

	//��ʾ����
	int EnergyLeftCompareMax = (double)playerEnergy / playerMaxEnergy * 10;
	if (EnergyLeftCompareMax > 10)
		EnergyLeftCompareMax = 10;
	cout << "���� " << playerEnergy;
	cout << "   \t|";
	for (int i = 0; i < EnergyLeftCompareMax; i++) cout << "��";
	for (int i = 0; i < 20 - 2 * EnergyLeftCompareMax; i++) cout << " ";
	cout << "";
	cout << " MAX " << playerMaxEnergy;
	cout << endl;
	cout << "|����ǰ��ţ�ʹ��  |4���˳�\n";

	int choice = 0;
	FLAG:
	countInChoice(choice);

	if (choice < 1 || choice > 4) {
		cout << "��Ч��ѡ��������룺";
		goto FLAG;
	}
	else if (playerCore.cores[choice - 1].coreID == 0) {
		cout << "������û�к��ģ����������룺";
		goto FLAG;
	}

	if (choice == 4) {
		print_();
		cout << endl;
		return 0;
	}

	int choiceID = playerCore.cores[choice - 1].coreID;

	if (playerEnergy < playerCore.cores[choice - 1].costEnergy) {
		cout << "�������㣬�޷�ʹ�ú���\n\n";
		return 0;
	}

	int playerTotalDamage = playerDamage + playerAddDamage;
	int enemyTotalHurt = enemy.enemyMaxHealth - enemy.enemyHealth;
	int damageRecord = 0;

	switch (choiceID) {
	//����
	case 1:
		cout << "\n�������Ե�����ŭ��\n";
		postpone();
		playerAttack(enemy, (int)playerTotalDamage * 1.4);
		if ((double)enemy.enemyHealth / (double)enemy.enemyMaxHealth > 0.7) {
			cout << "\n��ŭ�����һ�У�\n";
			postpone();
			playerAttack(enemy, (int)playerTotalDamage * 1.4);
		}

		break;
	//����
	case 2:
		cout << "\n������ë���������衣\n";
		postpone();
		playerAttack(enemy, (int)playerTotalDamage * 1.6);
		playerBeingHeal((int)playerMaxHealth * 0.15);

		break;
	//ĺ��
	case 3:
		cout << "\n����ɫ������·��Ϩ����\n";
		postpone();
		playerAttack(enemy, (int)enemyTotalHurt * 0.3);

		break;
	//����
	case 4:
		cout << "\n��������������\n";
		postpone();
		cout << "����⽫����а�񡣡�\n";
		postpone();
		playerBeingHeal((int)playerMaxHealth * 0.3);
		enemy.buff.BuffUpdate(1, 1, 1);

		break;
	//��ɽ
	case 5:
		cout << "\n��ǧɽ��ɾ����������𡣡�\n";
		postpone();
		enemy.buff.BuffUpdate(1, 2, 1);

		break;
	//����
	case 6:
		cout << "\n������İٱ��䣡��\n";
		postpone();
		for (int i = 0; i < MAXBackpackContains; i++) {
			if (backPack.items[i].ID == 0) 
				break;
			else if (backPack.items[i].ID != 0) 
				backPack.items[i].itemNumber++;
		}

		break;

    //����
	case 7:
		cout << "\n�����������ڶ����������ɡ���\n";
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
//������Ϣ
/*
locate = ����ԭʼλ��
0 = ��
1 = �����ס���Ŀ�����140%�˺�����Ŀ����������70%�������һ���˺�������40������
2 = �����衿��Ŀ�����160%�˺����ָ�15%����������50������
3 = ��ĺ�⡿��Ŀ���������������30%�˺�������80������
4 = ���������ָ�30%��������ĬĿ��1�غϡ�����70������
5 = ����ɽ����ĬĿ��2�غϣ�����60������
6 = �����꡿������������Ʒ����+1������80������
*/
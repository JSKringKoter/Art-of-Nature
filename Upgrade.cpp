#include "TotalHead.h"

void Upgrade(Player& player, int healthLevel, int damageLevel, int defenceLevel, int energyLevel)
{

	postpone(2);
	cout << "\n\n\n\n\n\n��Ϸ������ѡ���������ͣ�" << endl;

	print_();
	cout << endl;

	//
	cout << "��1:��������ֵ    |ÿ������30���������| ����100ˮ��|" << endl;
	cout << "|";
	for (int i = 0; i < healthLevel; i++) {
		cout << "��";
	}
	if (healthLevel == 10)
		cout << "\n|����\n\n";
	else
	  cout << "\n|��ǰ�ȼ���" << healthLevel << "���ȼ���10\n\n";
	 
	cout << "��2:����������    |ÿ������5��ʼ��������| ����100ˮ��|" << endl;
	cout << "|";
	for (int i = 0; i < damageLevel; i++) {
		cout << "��";
	}
	if (damageLevel == 10)
		cout << "\n|����\n\n";
	else
	    cout << "\n|��ǰ�ȼ���" << damageLevel << "���ȼ���10\n\n";

	cout << "��3:��������ֵ    |ÿ������10��ʼ���ס�| ����100ˮ��|" << endl;
	cout << "|";
	for (int i = 0; i < defenceLevel; i++) {
		cout << "��";
	}
	if (defenceLevel == 10)
		cout << "\n|����\n\n";
	else
	    cout << "\n|��ǰ�ȼ���" << defenceLevel << "���ȼ���10\n\n";

	cout << "��4:����������    |ÿ������10���������| ����100ˮ��|" << endl;
	cout << "|";
	for (int i = 0; i < energyLevel; i++) {
		cout << "��";
	}
	if (energyLevel == 10)
		cout << "\n|����\n\n";
	else
	    cout << "\n|��ǰ�ȼ���" << energyLevel << "���ȼ���10\n";
	//

	print_();
	cout << endl;



	int choice = 0;

	cout << "��ǰˮ���" << player.crystal << endl;
FLAG1:
	postpone();
	cout << "|ѡ��ǰ����+�س�������    5��ȡ��\n";

FLAG:
	countInChoice(choice);
	if (choice < 1 || choice > 5)
		goto FLAG;

	switch (choice) {
	case 1:
		if (healthLevel >= 10) {
			cout << "����ֵ��������\n";
			goto FLAG1;
		}
		else if (player.crystal < 100) {
			cout << "ˮ�����㡣\n";
			goto FLAG1;
		}

		cout << "�������ֵ������  ʣ��ˮ����" << player.crystal - 100<< endl;
		player.crystal -= 100;
		healthLevel++;
		goto FLAG1;
		break;


	case 2:
		if (damageLevel >= 10) {
			cout << "��������������\n";
			goto FLAG1;
		}
		else if (player.crystal < 100) {
			cout << "ˮ�����㡣\n";
			goto FLAG1;
		}

		cout << "��ʼ������������  ʣ��ˮ����" << player.crystal - 100<< endl;
		player.crystal -= 100;
		damageLevel++;
		goto FLAG1;
		break;


	case 3:
		if (defenceLevel >= 10) {
			cout << "������������\n";
			goto FLAG1;
		}
		else if (player.crystal < 100) {
			cout << "ˮ�����㡣\n";
			goto FLAG1;
		}

		cout << "��ʼ����������  ʣ��ˮ����" << player.crystal - 100<< endl;
		player.crystal -= 100;
		defenceLevel++;
		goto FLAG1;
		break;


	case 4:
		if (energyLevel >= 10) {
			cout << "��������������\n";
			goto FLAG1;
		}
		else if (player.crystal < 100) {
			cout << "ˮ�����㡣\n";
			goto FLAG1;
		}

		cout << "����ֵ������  ʣ��ˮ����" << player.crystal - 100<< endl;
		player.crystal -= 100;
		energyLevel++;
		goto FLAG1;
		break;

	case 5:
		break;
	}
	writeSave(healthLevel, damageLevel, defenceLevel, energyLevel);
}
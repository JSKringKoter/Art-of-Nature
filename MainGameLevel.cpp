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
		player = Player(health, damage, defence, energy, "���칤");
		break;
	case 2:
		cout << "��������ֵ��";
		countInChoice(health);
		cout << "���빥������";
		countInChoice(damage);
		cout << "���뻤��ֵ��";
		countInChoice(defence);
		cout << "��������ֵ��";
		countInChoice(energy);
		player = Player(health, damage, defence, energy, "���칤");
		break;
	case 3:
		makeRand(10, 200, 5, 50, 10, 100, health, damage, defence);
		player = Player(health, damage, defence, energy, "���칤");
		break;
	case 4:
		return 0;
	}

	player.crystal = 1000;

	cout << "�������ɽ�ɫ����\n\n";
	postpone();

	cout << "\n\n\n|�����Ϣ|\n";
	player.playerShowMenu();

	cout << "|1�������⣿Remake�ɣ�\n";
	cout << "|2��׼����ȫ����ʼð�ա�\n";
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
	cout << "\n\n\n��Ϸ������\n\n\n";

	system("pause");
	return 0;
}

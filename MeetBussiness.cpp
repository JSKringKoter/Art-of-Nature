#include "TotalHead.h"

int meetBussiness(Player& player)
{

	cout << "��������������\n\n";
	postpone();
	Bussiness bussiness;
	bussiness.makeRandBussinessItem();
	bussiness.showBussinessItem();

	int choice = 0;
	int fightresult = 0;
	cout << "|ӵ��ˮ����" << player.crystal << endl;
	cout << "|1������     |2������ð��    |3������ǹ��\n";

FLAG:
	countInChoice(choice);
	if (choice < 1 || choice > 3)
		goto FLAG;

	if (choice == 1) {
		bussiness.buy(player);
	}
	else if (choice == 2) {
		cout << "|�������Ʒ������Ŀ�ζ�������߰ɡ�\n";
		postpone();
		return 1;
	}
	else if (choice == 3) {
		fightresult = bussiness.fightWithBussiness(player);
		if (fightresult == 0)
			return 0;
		else if (fightresult == 2)
			return 2;
	}
}
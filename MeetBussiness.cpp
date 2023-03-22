#include "TotalHead.h"

int meetBussiness(Player& player)
{

	cout << "◆你遇见了商人\n\n";
	postpone();
	Bussiness bussiness;
	bussiness.makeRandBussinessItem();
	bussiness.showBussinessItem();

	int choice = 0;
	int fightresult = 0;
	cout << "|拥有水晶★" << player.crystal << endl;
	cout << "|1：购买     |2：返回冒险    |3：（拔枪）\n";

FLAG:
	countInChoice(choice);
	if (choice < 1 || choice > 3)
		goto FLAG;

	if (choice == 1) {
		bussiness.buy(player);
	}
	else if (choice == 2) {
		cout << "|这里的商品不合你的口味，还是走吧。\n";
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
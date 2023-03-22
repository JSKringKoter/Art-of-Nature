#include "TotalHead.h"

Bussiness::Bussiness() :
	goods(), core()
{
	goods.setItemTo(1, 1, 2);
	goods.setItemTo(2, 2, 1);
	
	itemcount = new int[5];
	price = new int[5];
	corePrice = 0;
}

Bussiness::~Bussiness()
{}

void Bussiness::setBussinessItem(int locate, int itemID, int count)
{

}


//为商人随机添加货物
void Bussiness::makeRandBussinessItem(int mutiply)
{
	srand(time(0));

	int itemID[5];
	int specialDeal = 0;
	
	itemID[0] = 1, itemcount[0] = 3, price[0] = rand() % 10 + 20;  //商人第一个物品为医疗包
	itemID[1] = 2, itemcount[1] = 2, price[1] = rand() % 10 + 20;  //第二个为能量药剂

	for (int i = 2; i < 5; i++) {
		itemID[i] = rand() % (itemTypeNumber - 2) + 2;
		itemcount[i] = rand() % 2 + 1;
		
		specialDeal = rand() % 10 + 1;
		if (specialDeal < 6)
			price[i] = rand() % 15 + 10;
		else
		    price[i] = rand() % 30 + 30;

	}

	for (int i = 2; i < 5; i++) {
		goods.setItemTo(i + 1, itemID[i], itemcount[i]);
	}

	int coreType = rand() % 7 + 1;
	core.setCoreTo(1, coreType);
	corePrice = rand() % 30 + 100;
}

void Bussiness::showBussinessItem()
{

	cout << "|有节操的商人|" << endl;
	print_();
	cout << endl << "|在售物品：\n";

	for (int i = 0; i < 5; i++) {
		cout << "◆" << i + 1 << ":" << goods.items[i].itemName << " \t*" << itemcount[i];
		if (i >= 2 && price[i] < 30 && price[i] > 1)
			cout << "      ◆节操商人的特别优惠！！◆";

		cout << "\n单价：" << price[i] << "★  |" << goods.items[i].itemDescribe << endl << endl;
	}

	cout << endl;
	cout << "|在售核心：\n";
	cout << "◆" << "6:" << core.cores[0].coreName << endl;
	cout << "售价：" << corePrice << "★  |" << core.cores[0].coreDescribe << endl;

	print_();
	cout << endl;

	
}

int Bussiness::fightWithBussiness(Player& player)
{
	cout << "\n|???\n";
	postpone();
	cout << "|叫你拔枪你还真他妈拔枪啊！\n";
	postpone();

	int totalHealth = 0;
	for (int i = 0; i < 5; i++) {
		totalHealth += price[i] * 2;
	}
	totalHealth += corePrice * 2;

	int totaldamage = totalHealth / 10;

	Enemy bussiness(totalHealth, totaldamage, 0, "有节操的商人");

	printEndl();
	int result = fightWithEnemy(player, bussiness);
	if (result == 0) {
		cout << "|你干嘛拔枪啊……哎呦……\n";
		postpone();
		cout << "|你看，死了啦，都是你害的。\n\n";
		postpone();

		return 0;
	}
	else if (result == 2) {
		cout << "|你获得了商人的所有物品。以及他的水晶。\n";
		postpone();
		cout << "获得水晶★" << totalHealth / 3 << endl;
		postpone();

		for (int i = 0; i < 5; i++) {
			printEndl();
			print_();
			player.backPack.addBackpack(goods.items[i].ID, itemcount[i]);
		}

		printEndl();
		print_();
		player.playerCore.addToCoreList(core.cores[0].coreID);
		return 2;
	}
}

void Bussiness::buy(Player& player)
{
	int choice = 0;
	int seeGoods = 0;

FLAG:
	if (seeGoods > 0) {
		printEndl();
		showBussinessItem();
	}
FLAG1:
	cout << "|拥有水晶★" << player.crystal << endl;
	cout << "|道具前数字：购买     |7：返回\n";

	countInChoice(choice);
	while (choice < 0 || choice > 7) {
		cout << "无效的选项，重新选择：";
		countInChoice(choice);
	}
	
	int locate = choice - 1;
	//购买道具
	if (choice < 6 && 0 < choice) {

		if (price[locate] == 0) {
			cout << "你要买的道具已经售罄。\n\n";
			postpone(1.5);
			goto FLAG1;
		}
		else if (player.crystal < price[locate]) {
			cout << "水晶不足。\n\n";
			postpone(1.5);
			goto FLAG1;
		}
		else 
		{
			//购买商品，当物品数量为零时重置。
			player.crystal -= price[locate];
			cout << goods.items[locate].itemName << "购买成功。\n";

			cout << endl;
			postpone(2);
			player.backPack.addBackpack(goods.items[locate].ID, 1);
			itemcount[locate]--;

			if (itemcount[locate] == 0) {
				goods.items[locate].ID = 0;
				goods.items[locate].itemName = "售罄";
				price[locate] = 0;

				int defineDescribe = 0;
				defineDescribe = rand() % 3 + 1;
				if (defineDescribe == 1)
					goods.items[locate].itemDescribe = "富佬V50给孩子买个疯狂星期四。";
				else if (defineDescribe == 2)
					goods.items[locate].itemDescribe = "我拿什么和你比，你吃疯狂星期四，都不用看星期几。";
				else if (defineDescribe == 3)
					goods.items[locate].itemDescribe = "V作者5毛钱给Rainimator小姐买个KFC。";
			}

			seeGoods++;
			
			goto FLAG;
			
		}
	}
	else if (choice == 6) {
		if (corePrice == 0) {
			cout << "你要买的核心已经售罄。\n\n";
			postpone(1.5);
			goto FLAG1;
		}
		else if (player.crystal < corePrice) {
			cout << "水晶不足。\n\n";
			postpone(1.5);
			goto FLAG1;
		}
		else {
			player.crystal -= corePrice;
			cout << core.cores[0].coreName << "购买成功。\n";

			postpone(2);
			player.playerCore.addToCoreList(core.cores[0].coreID);


			core.cores[0].coreID = 0;
			core.cores[0].coreName = "售罄";
			core.cores[0].coreDescribe = "范天工你就是个几把！";
			corePrice = 0;

			seeGoods++;
			goto FLAG;
		}
	}
	else if (choice == 7) {
		return;
	}
	
}
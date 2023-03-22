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


//Ϊ���������ӻ���
void Bussiness::makeRandBussinessItem(int mutiply)
{
	srand(time(0));

	int itemID[5];
	int specialDeal = 0;
	
	itemID[0] = 1, itemcount[0] = 3, price[0] = rand() % 10 + 20;  //���˵�һ����ƷΪҽ�ư�
	itemID[1] = 2, itemcount[1] = 2, price[1] = rand() % 10 + 20;  //�ڶ���Ϊ����ҩ��

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

	cout << "|�нڲٵ�����|" << endl;
	print_();
	cout << endl << "|������Ʒ��\n";

	for (int i = 0; i < 5; i++) {
		cout << "��" << i + 1 << ":" << goods.items[i].itemName << " \t*" << itemcount[i];
		if (i >= 2 && price[i] < 30 && price[i] > 1)
			cout << "      ���ڲ����˵��ر��Żݣ�����";

		cout << "\n���ۣ�" << price[i] << "��  |" << goods.items[i].itemDescribe << endl << endl;
	}

	cout << endl;
	cout << "|���ۺ��ģ�\n";
	cout << "��" << "6:" << core.cores[0].coreName << endl;
	cout << "�ۼۣ�" << corePrice << "��  |" << core.cores[0].coreDescribe << endl;

	print_();
	cout << endl;

	
}

int Bussiness::fightWithBussiness(Player& player)
{
	cout << "\n|???\n";
	postpone();
	cout << "|�����ǹ�㻹�������ǹ����\n";
	postpone();

	int totalHealth = 0;
	for (int i = 0; i < 5; i++) {
		totalHealth += price[i] * 2;
	}
	totalHealth += corePrice * 2;

	int totaldamage = totalHealth / 10;

	Enemy bussiness(totalHealth, totaldamage, 0, "�нڲٵ�����");

	printEndl();
	int result = fightWithEnemy(player, bussiness);
	if (result == 0) {
		cout << "|������ǹ���������ϡ���\n";
		postpone();
		cout << "|�㿴���������������㺦�ġ�\n\n";
		postpone();

		return 0;
	}
	else if (result == 2) {
		cout << "|���������˵�������Ʒ���Լ�����ˮ����\n";
		postpone();
		cout << "���ˮ����" << totalHealth / 3 << endl;
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
	cout << "|ӵ��ˮ����" << player.crystal << endl;
	cout << "|����ǰ���֣�����     |7������\n";

	countInChoice(choice);
	while (choice < 0 || choice > 7) {
		cout << "��Ч��ѡ�����ѡ��";
		countInChoice(choice);
	}
	
	int locate = choice - 1;
	//�������
	if (choice < 6 && 0 < choice) {

		if (price[locate] == 0) {
			cout << "��Ҫ��ĵ����Ѿ�������\n\n";
			postpone(1.5);
			goto FLAG1;
		}
		else if (player.crystal < price[locate]) {
			cout << "ˮ�����㡣\n\n";
			postpone(1.5);
			goto FLAG1;
		}
		else 
		{
			//������Ʒ������Ʒ����Ϊ��ʱ���á�
			player.crystal -= price[locate];
			cout << goods.items[locate].itemName << "����ɹ���\n";

			cout << endl;
			postpone(2);
			player.backPack.addBackpack(goods.items[locate].ID, 1);
			itemcount[locate]--;

			if (itemcount[locate] == 0) {
				goods.items[locate].ID = 0;
				goods.items[locate].itemName = "����";
				price[locate] = 0;

				int defineDescribe = 0;
				defineDescribe = rand() % 3 + 1;
				if (defineDescribe == 1)
					goods.items[locate].itemDescribe = "����V50�����������������ġ�";
				else if (defineDescribe == 2)
					goods.items[locate].itemDescribe = "����ʲô����ȣ���Է�������ģ������ÿ����ڼ���";
				else if (defineDescribe == 3)
					goods.items[locate].itemDescribe = "V����5ëǮ��RainimatorС�����KFC��";
			}

			seeGoods++;
			
			goto FLAG;
			
		}
	}
	else if (choice == 6) {
		if (corePrice == 0) {
			cout << "��Ҫ��ĺ����Ѿ�������\n\n";
			postpone(1.5);
			goto FLAG1;
		}
		else if (player.crystal < corePrice) {
			cout << "ˮ�����㡣\n\n";
			postpone(1.5);
			goto FLAG1;
		}
		else {
			player.crystal -= corePrice;
			cout << core.cores[0].coreName << "����ɹ���\n";

			postpone(2);
			player.playerCore.addToCoreList(core.cores[0].coreID);


			core.cores[0].coreID = 0;
			core.cores[0].coreName = "����";
			core.cores[0].coreDescribe = "���칤����Ǹ����ѣ�";
			corePrice = 0;

			seeGoods++;
			goto FLAG;
		}
	}
	else if (choice == 7) {
		return;
	}
	
}
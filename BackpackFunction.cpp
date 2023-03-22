#include "TotalHead.h"

//初始化
Backpack::Backpack()
{
	items = new ITEM[MAXBackpackContains];
	items[0] = { 1, "医疗包", "恢复25%生命值", 2};
	items[1] = { 2, "能量药剂", "恢复12.5%能量", 3 };
	
	for (int i = 2; i < MAXBackpackContains; i++) {
		items[i] = { 0, "NONE", "Nothing", 0};
	}
}

Backpack::~Backpack() {}

//重置背包格子属性
void Backpack::resetItem(int locate)
{
	int i = locate - 1;
	items[i].ID = 0;
	items[i].itemName = "NONE";
	items[i].itemDescribe = "Nothing";
	items[i].itemNumber = 0;
}



//
//将新物品放入背包
//
void Backpack::addBackpack(int ID, int count)
{
	int locate = 0;

	for (locate = 0; locate < MAXBackpackContains; locate++) {

		//检测是否可叠加
		if (items[locate].ID == ID) {
			items[locate].itemNumber += count;
			cout << "\n获得：" << items[locate].itemName << "  数量：" << count << endl;
			showBackpackItems();
			cout << "\n任意键+回车：确认" << endl;
			eatLine();
			break;
		}

		//若在此退出，则背包未满
		else if (items[locate].ID == 0)
			break;
	}

	Backpack newBackpack;
	newBackpack.setItemTo(1, ID, count);
	
	//检测到背包满
	if (locate == MAXBackpackContains) {

		cout << "\n获得了" << newBackpack.items[0].itemName << "  数量：" << newBackpack.items[0].itemNumber << endl;
		cout <<  "背包已满。\n";
		showBackpackItems();
		cout << "\n1：返回  2：替换\n";

		//选择是否替换
		int choice = 0;
		countInChoice(choice);

		while (choice < 1 || choice > 2) {
			cout << "无效的选项，重新选择：";
			countInChoice(choice);
		}

		//选择替换位置
		if (choice == 2) {
			int choice2 = 0;

			cout << "选择替换位置：";
			countInChoice(choice2);

			while (choice2 < 1 || choice2 > MAXBackpackContains) {
				cout << "无效的位置，重新选择：";
				countInChoice(choice2);
			}

			choice2--;
			cout << "已将 " << items[choice2].itemName << "*" << items[choice2].itemNumber;
			setItemTo(choice2 + 1, ID, count);
			cout << " 替换为 " << items[choice2].itemName << "*" << items[choice2].itemNumber << endl;;
		}
	}

	//无可叠加位置，且有空位
	else if (locate != MAXBackpackContains && items[locate].ID != ID) {
		setItemTo(locate + 1, ID, count);
		cout << "\n获得了" << items[locate].itemName << "  数量：" << count << endl;
		postpone();
		showBackpackItems();
		cout << "\n任意键+回车：确认" << endl;
		eatLine();
	}
}


//
//显示背包
//
void Backpack::showBackpackItems()
{
	int zeroCount = 0;
	cout << "\n|背包|" << endl;
	print_();
	cout << endl;
	for (int i = 0; i < MAXBackpackContains; i++) {
		if (items[i].ID != 0) {
			cout << "|◆";
			cout << i + 1 << ":" << items[i].itemName << " x" << items[i].itemNumber << " |" << items[i].itemDescribe;
			if (i + 1 < MAXBackpackContains && items[i + 1].ID != 0)
				cout << endl;
		}
		else
			zeroCount++;

	}

	if (zeroCount == MAXBackpackContains) {
		cout << "|              背包中没有物品。            |" << endl;
		print_();
	}
	else {
		cout << endl;
		print_();
	}

}

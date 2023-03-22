#include "TotalHead.h"

void meetTreature(Player& player)
{
	srand(time(0));
	cout << "|你发现了一个箱子。\n";
	int getItem = rand() % (itemTypeNumber + 1);
	int count = rand() % 3 + 1;
	player.backPack.addBackpack(getItem, count);
}
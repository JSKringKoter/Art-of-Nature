#pragma once
#ifndef BackPack_h
#define BackPack_h

const int MAXBackpackContains = 5;
const int itemTypeNumber = 7;

class Backpack
{
public:
	struct ITEM {
		int ID;
		string itemName;
		string itemDescribe;
		int itemNumber;
	};
	ITEM* items;

	Backpack();
	~Backpack();

	void showBackpackItems();
	void resetItem(int locate);
	void setItemTo(int locater, int type, int count);
	void addBackpack(int type, int count);
};

#endif // !BackPack_h


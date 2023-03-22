#pragma once
#ifndef BUSSINESS
#define BUSSINESS

class Bussiness {
public:
	
	Backpack goods;
	int* itemcount;
	int* price;

	Core core;
	int corePrice;

	Bussiness();
	~Bussiness();

	void setBussinessItem(int locate, int itemID, int count);
	void makeRandBussinessItem(int mutiply = 1);
	void showBussinessItem();

	void buy(Player& player);
	int fightWithBussiness(Player& player);

};

#endif // !BUSSINESS

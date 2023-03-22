#include "TotalHead.h"

void print_(int lenth)
{
	for (int i = 0; i < lenth; i++) {
		cout << "——";
	}
}

void eatLine()
{
	while (cin.get() != '\n')
		;
}

void countInChoice(int& choice)
{
	while (!(cin >> choice))
	{
		cout << "无效的选项，重新选择：";
		cin.clear();
		eatLine();
	}
	cin.get();
}

void printEndl(int lenth)
{
	for (int i = 0; i < lenth; i++) {
		cout << endl;
	}
}

void postpone(double postponeTime)
{
	clock_t start = clock();
	clock_t end = postponeTime * CLOCKS_PER_SEC;
	while (clock() - start < end)
		;
}

void makeRand(int healthBase, int healthRent, int damageBase, int damageRent, int defenceBase, int defenceRent,
	int& health, int& damage, int& defence)
{
	healthRent++;
	damageRent++;
	defenceRent++;

	srand((unsigned)time(0));
	health = rand() % healthRent + healthBase;
	damage = rand() % damageRent + damageBase;
	defence = rand() % defenceRent + defenceBase;
}

int printTital()
{
	print_();
	cout << "\n|           [Art Of Nature  天工]          |\n";
	print_();

	cout << "\n\n◆Alpha 1.0.0\n◆Made by JS_KringKoter";
	printEndl();

	cout << "|1：开始普通的冒险" << endl;
	cout << "|2：开始自定义的冒险" << endl;
	cout << "|3：开始随机的冒险" << endl;
	cout << "|4：退出冒险" << endl << endl;

	int choice = 0;
	FLAG:
	countInChoice(choice);

	if (choice < 1 || choice > 4) {
		cout << "选择无效，重新选择：";
		goto FLAG;
	}

	switch (choice) {
	case 1:
		cout << "即将开始普通的冒险。\n";
		postpone();
		cout << endl;
		return 1;
	case 2:
		cout << "即将开始自定义的冒险。\n";
		postpone();
		cout << endl;
		return 2;
	case 3:
		cout << "即将开始随机的冒险。\n";
		postpone();
		cout << endl;
		return 3;
	case 4:
		cout << "退出游戏。\n";
		print_();
		cout << endl;
		return 4;
	}
}

void readSave(int& healthLevel, int& damageLevel, int& defenceLevel, int& energyLevel)
{
	string string;
	ifstream fin("save.txt", ios_base::in);

	if (!fin.is_open()) {
		healthLevel = damageLevel = defenceLevel = energyLevel = 0;
	}
	else {

		getline(fin, string);
		fin >> healthLevel;
		fin.get();

		getline(fin, string);
		fin >> damageLevel;
		fin.get();

		getline(fin, string);
		fin >> defenceLevel;
		fin.get();

		getline(fin, string);
		fin >> energyLevel;
		fin.get();
	}


	fin.close();
}

void writeSave(int healthLevel, int damageLevel, int defenceLevel, int energyLevel)
{

	ofstream fout("save.txt", ios_base::out);
	fout << "healthLevel =\n" << healthLevel << endl;
	fout << "damageLevel =\n" << damageLevel << endl;
	fout << "defenceLevel =\n" << defenceLevel << endl;
	fout << "energyLevel =\n" << energyLevel << endl;
	fout.close();
}
#pragma once
#ifndef CORE
#define CORE

const int MAXCoreListContain = 3;

class Core
{
public:

	struct coreInformation {
		int coreID;
		string coreName;
		string coreDescribe;
		int costEnergy;
	};

	int strenthCoreNumber;
	int healthCoreNumber;
	int energyCoreNumber;

	coreInformation* cores;


	Core();
	~Core();

	void resetCore(int locate);
	void setCoreTo(int locate, int ID);
	void showCoreLIst();
	void addToCoreList(int ID);
};

#endif // !CORE

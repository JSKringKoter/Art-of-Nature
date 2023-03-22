#include "TotalHead.h"

Core::Core()
{

	strenthCoreNumber = healthCoreNumber = energyCoreNumber = 0;

	coreInformation* p = new coreInformation[MAXCoreListContain];
	cores = p;

	for (int i = 0; i < MAXCoreListContain; i++) {
		cores[i] = { 0, "None", "Nothing To Describe." , 10 };
	}

}

Core::~Core() {}

void Core::showCoreLIst()
{

	cout << "\n|核心列表|\n";
	print_();
	cout << endl;
	int numberCount = 0;
	for (int i = 0; i < MAXCoreListContain; i++) {

		if (cores[i].coreID == 0) {
			break;
		}

		cout << "◆" << i + 1 << "：" << cores[i].coreName << endl;
		cout << cores[i].coreDescribe << endl;

		numberCount++;
	}

	if (numberCount == 0) {
		cout << "|               你还没有核心。             |\n";
		print_();
		cout << endl;
	}
	else {
		print_();
		cout << endl;
	}

}

//重置格子信息
void Core::resetCore(int locate)
{
	locate--;
	cores[locate].coreID = 0;
	cores[locate].coreName = "None";
	cores[locate].coreDescribe = "Nothing To Describe.";
	cores[locate].costEnergy = 0;
}


//
//核心信息
/*
locate = 格子原始位置
0 = 无
1 = 【狱炎】对目标造成140%伤害，若目标生命仍大于70%，再造成一次伤害。消耗40能量。
2 = 【惊鸿】对目标造成160%伤害，恢复15%生命。消耗50能量。
3 = 【暮光】对目标造成已损生命的30%伤害。消耗80能量。
4 = 【黎明】恢复30%生命，沉默目标1回合。消耗70能量。
5 = 【空山】沉默目标2回合，消耗60能量。
6 = 【陈年】背包中所有物品个数+1。消耗80能量。
7 = 【回音】对自身造成剩余生命10%的伤害，并以180%返还给目标。消耗50能量。
*/
void Core::setCoreTo(int locate, int ID)
{
	locate--;

	switch (ID) {
	case 1:
		cores[locate].coreName = "【狱炎】";
		cores[locate].coreDescribe = "对目标造成140%伤害，若目标生命仍大于70%，再造成一次伤害。消耗40能量。";
		cores[locate].costEnergy = 40;
		break;
	case 2:
		cores[locate].coreName = "【惊鸿】";
		cores[locate].coreDescribe = "对目标造成160%伤害，恢复15%生命。消耗50能量。";
		cores[locate].costEnergy = 50;
		break;
	case 3:
		cores[locate].coreName = "【暮光】";
		cores[locate].coreDescribe = "对目标造成已损生命的30%伤害。消耗80能量。";
		cores[locate].costEnergy = 80;
		break;
	case 4:
		cores[locate].coreName = "【黎明】";
		cores[locate].coreDescribe = "恢复30%生命，沉默目标1回合。消耗70能量。";
		cores[locate].costEnergy = 70;
		break;
	case 5:
		cores[locate].coreName = "【空山】";
		cores[locate].coreDescribe = "沉默目标2回合，消耗60能量。";
		cores[locate].costEnergy = 60;
		break;
	case 6:
		cores[locate].coreName = "【陈年】";
		cores[locate].coreDescribe = "背包中所有物品个数+1。消耗80能量。";
		cores[locate].costEnergy = 80;
		break;
	case 7:
		cores[locate].coreName = "【回音】";
		cores[locate].coreDescribe = "对自身造成剩余生命10%的伤害，并以180%返还给目标。消耗50能量。";
		cores[locate].costEnergy = 50;
		break;
	}

	cores[locate].coreID = ID;
}


void Core::addToCoreList(int ID)
{
	int locate = 0;
	bool isSame = false;

	for (locate = 0; locate < MAXCoreListContain; locate++) {

		if (cores[locate].coreID == ID) {
			cout << "\n获得了" << cores[locate].coreName << " |" << cores[locate].coreDescribe << endl;
			cout << "与列表中 ◆" << locate + 1 << "：" << cores[locate].coreName  << "重复。\n";
			showCoreLIst();
			cout << "|任意键+回车：确定\n";
			eatLine();
			isSame = true;
			break;
		}

		//若在此退出，则核心列表未满
		if (cores[locate].coreID == 0)
			break;
	}
	/*
	if (isSame == false) {
		Core newCore;
		newCore.setCoreTo(1, ID);
		cout << "获得了" << newCore.cores[0].coreName << " |" << newCore.cores[0].coreDescribe;
	}
	*/
	//检测到背包满
	if (locate == MAXCoreListContain) {
		cout << endl << "核心列表已满。\n";
		showCoreLIst();
		postpone();
		cout << "|1：返回  |2：替换\n";

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

			while (choice2 < 1 || choice2 > MAXCoreListContain) {
				cout << "无效的位置，重新选择：";
				countInChoice(choice2);
			}

			choice2--;
			cout << "已将 " << cores[choice2].coreName;
			setCoreTo(choice2 + 1, ID);
			cout << " 替换为 " << cores[choice2].coreName << endl;
		}
	}

	//无可叠加位置，且有空位
	else if (locate != MAXCoreListContain && cores[locate].coreID != ID && isSame == false) {
		setCoreTo(locate + 1, ID);
		cout << "\n获得了" << cores[locate].coreName << " |" << cores[locate].coreDescribe << endl;
		postpone();
		showCoreLIst();
		cout << "|任意键+回车：确认" << endl;
		eatLine();
	}

}

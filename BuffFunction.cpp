#include "TotalHead.h"

//初始化
Buff::Buff()
{
	BuffName = "NONE";
	BuffID = 0;
	Level = 0;
	Rend = 0;
	isHasBuff = false;
}


Buff::~Buff()
{}


/*
Buff更新
0 = 无
1 = 沉默
2 = 持续伤害
3 = 力量
4 = 虚弱
*/
void Buff::BuffUpdate(int ID, int rend, int level)
{
	switch (ID) {
	case 1:
		BuffName = "沉默";
		break;
	case 2:
		BuffName = "持续伤害";
		break;
	case 3:
		BuffName = "力量";
		break;
	case 4:
		BuffName = "虚弱";
		break;
	}

	BuffID = ID;
	Level = level;
	Rend = rend;
	isHasBuff = true;
}


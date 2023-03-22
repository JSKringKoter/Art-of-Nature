#include "TotalHead.h"

/*
设置背包格子属性
locate = 原始格子位置
0 = 空
1 = 生命药剂
2 = 能量药剂
3 = 力量药剂
4 = 高爆炸药（120伤害）
5 = 寒冰之矛（30伤害，沉默一回合）
6 = 熔岩烧瓶（50伤害，20减攻一回合）
7 = 防御药剂
*/

void Backpack::setItemTo(int locate, int ID, int count)
{

	locate--;
	string setName = "NONE";
	string setDescribe = "Nothing";

	switch (ID) {
	case 1:
		setName = "医疗包";
		setDescribe = "恢复25%生命值。";
		break;
	case 2:
		setName = "能量药剂";
		setDescribe = "恢复30%能量。";
		break;
	case 3:
		setName = "阻滞弹药";
		setDescribe = "增加10%攻击，持续2回合。";
		break;
	case 4:
		setName = "高爆炸药";
		setDescribe = "造成120点伤害。";
		break;
	case 5:
		setName = "寒冰子弹";
		setDescribe = "造成30伤害，沉默目标1回合。";
		break;
	case 6:
		setName = "熔岩烧瓶";
		setDescribe = "造成50伤害，减少目标攻击20，持续1回合。";
		break;
	case 7:
		setName = "护甲片";
		setDescribe = "增加60点防御。";
		break;
	}

	items[locate].ID = ID;
	items[locate].itemName = setName;
	items[locate].itemDescribe = setDescribe;
	items[locate].itemNumber = count;
}

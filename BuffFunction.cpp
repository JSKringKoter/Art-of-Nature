#include "TotalHead.h"

//��ʼ��
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
Buff����
0 = ��
1 = ��Ĭ
2 = �����˺�
3 = ����
4 = ����
*/
void Buff::BuffUpdate(int ID, int rend, int level)
{
	switch (ID) {
	case 1:
		BuffName = "��Ĭ";
		break;
	case 2:
		BuffName = "�����˺�";
		break;
	case 3:
		BuffName = "����";
		break;
	case 4:
		BuffName = "����";
		break;
	}

	BuffID = ID;
	Level = level;
	Rend = rend;
	isHasBuff = true;
}


#include "TotalHead.h"

/*
���ñ�����������
locate = ԭʼ����λ��
0 = ��
1 = ����ҩ��
2 = ����ҩ��
3 = ����ҩ��
4 = �߱�ըҩ��120�˺���
5 = ����֮ì��30�˺�����Ĭһ�غϣ�
6 = ������ƿ��50�˺���20����һ�غϣ�
7 = ����ҩ��
*/

void Backpack::setItemTo(int locate, int ID, int count)
{

	locate--;
	string setName = "NONE";
	string setDescribe = "Nothing";

	switch (ID) {
	case 1:
		setName = "ҽ�ư�";
		setDescribe = "�ָ�25%����ֵ��";
		break;
	case 2:
		setName = "����ҩ��";
		setDescribe = "�ָ�30%������";
		break;
	case 3:
		setName = "���͵�ҩ";
		setDescribe = "����10%����������2�غϡ�";
		break;
	case 4:
		setName = "�߱�ըҩ";
		setDescribe = "���120���˺���";
		break;
	case 5:
		setName = "�����ӵ�";
		setDescribe = "���30�˺�����ĬĿ��1�غϡ�";
		break;
	case 6:
		setName = "������ƿ";
		setDescribe = "���50�˺�������Ŀ�깥��20������1�غϡ�";
		break;
	case 7:
		setName = "����Ƭ";
		setDescribe = "����60�������";
		break;
	}

	items[locate].ID = ID;
	items[locate].itemName = setName;
	items[locate].itemDescribe = setDescribe;
	items[locate].itemNumber = count;
}

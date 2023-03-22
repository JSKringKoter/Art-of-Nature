#include "TotalHead.h"

//��ʼ��
Backpack::Backpack()
{
	items = new ITEM[MAXBackpackContains];
	items[0] = { 1, "ҽ�ư�", "�ָ�25%����ֵ", 2};
	items[1] = { 2, "����ҩ��", "�ָ�12.5%����", 3 };
	
	for (int i = 2; i < MAXBackpackContains; i++) {
		items[i] = { 0, "NONE", "Nothing", 0};
	}
}

Backpack::~Backpack() {}

//���ñ�����������
void Backpack::resetItem(int locate)
{
	int i = locate - 1;
	items[i].ID = 0;
	items[i].itemName = "NONE";
	items[i].itemDescribe = "Nothing";
	items[i].itemNumber = 0;
}



//
//������Ʒ���뱳��
//
void Backpack::addBackpack(int ID, int count)
{
	int locate = 0;

	for (locate = 0; locate < MAXBackpackContains; locate++) {

		//����Ƿ�ɵ���
		if (items[locate].ID == ID) {
			items[locate].itemNumber += count;
			cout << "\n��ã�" << items[locate].itemName << "  ������" << count << endl;
			showBackpackItems();
			cout << "\n�����+�س���ȷ��" << endl;
			eatLine();
			break;
		}

		//���ڴ��˳����򱳰�δ��
		else if (items[locate].ID == 0)
			break;
	}

	Backpack newBackpack;
	newBackpack.setItemTo(1, ID, count);
	
	//��⵽������
	if (locate == MAXBackpackContains) {

		cout << "\n�����" << newBackpack.items[0].itemName << "  ������" << newBackpack.items[0].itemNumber << endl;
		cout <<  "����������\n";
		showBackpackItems();
		cout << "\n1������  2���滻\n";

		//ѡ���Ƿ��滻
		int choice = 0;
		countInChoice(choice);

		while (choice < 1 || choice > 2) {
			cout << "��Ч��ѡ�����ѡ��";
			countInChoice(choice);
		}

		//ѡ���滻λ��
		if (choice == 2) {
			int choice2 = 0;

			cout << "ѡ���滻λ�ã�";
			countInChoice(choice2);

			while (choice2 < 1 || choice2 > MAXBackpackContains) {
				cout << "��Ч��λ�ã�����ѡ��";
				countInChoice(choice2);
			}

			choice2--;
			cout << "�ѽ� " << items[choice2].itemName << "*" << items[choice2].itemNumber;
			setItemTo(choice2 + 1, ID, count);
			cout << " �滻Ϊ " << items[choice2].itemName << "*" << items[choice2].itemNumber << endl;;
		}
	}

	//�޿ɵ���λ�ã����п�λ
	else if (locate != MAXBackpackContains && items[locate].ID != ID) {
		setItemTo(locate + 1, ID, count);
		cout << "\n�����" << items[locate].itemName << "  ������" << count << endl;
		postpone();
		showBackpackItems();
		cout << "\n�����+�س���ȷ��" << endl;
		eatLine();
	}
}


//
//��ʾ����
//
void Backpack::showBackpackItems()
{
	int zeroCount = 0;
	cout << "\n|����|" << endl;
	print_();
	cout << endl;
	for (int i = 0; i < MAXBackpackContains; i++) {
		if (items[i].ID != 0) {
			cout << "|��";
			cout << i + 1 << ":" << items[i].itemName << " x" << items[i].itemNumber << " |" << items[i].itemDescribe;
			if (i + 1 < MAXBackpackContains && items[i + 1].ID != 0)
				cout << endl;
		}
		else
			zeroCount++;

	}

	if (zeroCount == MAXBackpackContains) {
		cout << "|              ������û����Ʒ��            |" << endl;
		print_();
	}
	else {
		cout << endl;
		print_();
	}

}

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

	cout << "\n|�����б�|\n";
	print_();
	cout << endl;
	int numberCount = 0;
	for (int i = 0; i < MAXCoreListContain; i++) {

		if (cores[i].coreID == 0) {
			break;
		}

		cout << "��" << i + 1 << "��" << cores[i].coreName << endl;
		cout << cores[i].coreDescribe << endl;

		numberCount++;
	}

	if (numberCount == 0) {
		cout << "|               �㻹û�к��ġ�             |\n";
		print_();
		cout << endl;
	}
	else {
		print_();
		cout << endl;
	}

}

//���ø�����Ϣ
void Core::resetCore(int locate)
{
	locate--;
	cores[locate].coreID = 0;
	cores[locate].coreName = "None";
	cores[locate].coreDescribe = "Nothing To Describe.";
	cores[locate].costEnergy = 0;
}


//
//������Ϣ
/*
locate = ����ԭʼλ��
0 = ��
1 = �����ס���Ŀ�����140%�˺�����Ŀ�������Դ���70%�������һ���˺�������40������
2 = �����衿��Ŀ�����160%�˺����ָ�15%����������50������
3 = ��ĺ�⡿��Ŀ���������������30%�˺�������80������
4 = ���������ָ�30%��������ĬĿ��1�غϡ�����70������
5 = ����ɽ����ĬĿ��2�غϣ�����60������
6 = �����꡿������������Ʒ����+1������80������
7 = �����������������ʣ������10%���˺�������180%������Ŀ�ꡣ����50������
*/
void Core::setCoreTo(int locate, int ID)
{
	locate--;

	switch (ID) {
	case 1:
		cores[locate].coreName = "�����ס�";
		cores[locate].coreDescribe = "��Ŀ�����140%�˺�����Ŀ�������Դ���70%�������һ���˺�������40������";
		cores[locate].costEnergy = 40;
		break;
	case 2:
		cores[locate].coreName = "�����衿";
		cores[locate].coreDescribe = "��Ŀ�����160%�˺����ָ�15%����������50������";
		cores[locate].costEnergy = 50;
		break;
	case 3:
		cores[locate].coreName = "��ĺ�⡿";
		cores[locate].coreDescribe = "��Ŀ���������������30%�˺�������80������";
		cores[locate].costEnergy = 80;
		break;
	case 4:
		cores[locate].coreName = "��������";
		cores[locate].coreDescribe = "�ָ�30%��������ĬĿ��1�غϡ�����70������";
		cores[locate].costEnergy = 70;
		break;
	case 5:
		cores[locate].coreName = "����ɽ��";
		cores[locate].coreDescribe = "��ĬĿ��2�غϣ�����60������";
		cores[locate].costEnergy = 60;
		break;
	case 6:
		cores[locate].coreName = "�����꡿";
		cores[locate].coreDescribe = "������������Ʒ����+1������80������";
		cores[locate].costEnergy = 80;
		break;
	case 7:
		cores[locate].coreName = "��������";
		cores[locate].coreDescribe = "���������ʣ������10%���˺�������180%������Ŀ�ꡣ����50������";
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
			cout << "\n�����" << cores[locate].coreName << " |" << cores[locate].coreDescribe << endl;
			cout << "���б��� ��" << locate + 1 << "��" << cores[locate].coreName  << "�ظ���\n";
			showCoreLIst();
			cout << "|�����+�س���ȷ��\n";
			eatLine();
			isSame = true;
			break;
		}

		//���ڴ��˳���������б�δ��
		if (cores[locate].coreID == 0)
			break;
	}
	/*
	if (isSame == false) {
		Core newCore;
		newCore.setCoreTo(1, ID);
		cout << "�����" << newCore.cores[0].coreName << " |" << newCore.cores[0].coreDescribe;
	}
	*/
	//��⵽������
	if (locate == MAXCoreListContain) {
		cout << endl << "�����б�������\n";
		showCoreLIst();
		postpone();
		cout << "|1������  |2���滻\n";

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

			while (choice2 < 1 || choice2 > MAXCoreListContain) {
				cout << "��Ч��λ�ã�����ѡ��";
				countInChoice(choice2);
			}

			choice2--;
			cout << "�ѽ� " << cores[choice2].coreName;
			setCoreTo(choice2 + 1, ID);
			cout << " �滻Ϊ " << cores[choice2].coreName << endl;
		}
	}

	//�޿ɵ���λ�ã����п�λ
	else if (locate != MAXCoreListContain && cores[locate].coreID != ID && isSame == false) {
		setCoreTo(locate + 1, ID);
		cout << "\n�����" << cores[locate].coreName << " |" << cores[locate].coreDescribe << endl;
		postpone();
		showCoreLIst();
		cout << "|�����+�س���ȷ��" << endl;
		eatLine();
	}

}

#include "TotalHead.h"

//��Ҫȥ����������������ܣ�����case3 = 101�Ҳ�����case4
void Enemy::defineHowToActive(int case1, int case2, int case3, int case4)
{

	if (buff.BuffID == 1 && buff.Rend - 1 > 0) {
		enemyHowToActive = 0;
	}

	srand((unsigned)time(0));

	FLAG:
	int define = rand() % 101;

	/*
1 = ����
2 = ��
3 = ����
*/
	if (1 <= define && define < case1)
		enemyHowToActive = 1;
	else if (case1 <= define && define < case2)
		enemyHowToActive = 2;
	else if (case2 <= define && define < case3)
		enemyHowToActive = 3;
	else if (case3 <= define && define <= case4)
		enemyHowToActive = 4;


	//һЩ��������
	//����ֵ��������������
	if (enemyHealth == enemyMaxHealth && enemyHowToActive == 3)
		goto FLAG;
	//����ֵ����70%����ʹ�ü���
	if (enemyHealth >= enemyMaxHealth * 0.7 && enemyHowToActive == 4)
		goto FLAG;
}

/*
1 = ����
2 = ��
3 = ����
*/
void Enemy::enemyActive(Player& player)
{

	cout << "\n|�з��غ�|\n";
	print_();
	postpone();

	BuffEffect();

	switch (enemyHowToActive) {
	case 0:
		cout << "\n�����޷��ж���\n";
		postpone();
		break;

	case 1:
		cout << "\n���˽����˹�����\n";
		postpone();
		enemyAttack(player);
		break;

	case 2:
		cout << "\n���˽����˸񵲡�\n";
		postpone();
		cout << "���˵Ļ���������" << (int)(enemyDamage * 0.8) << "�㡣\n";
		postpone();
		enemyDefence += (int)(enemyDamage * 0.8);
		break;

	case 3:
		cout << "\n���˽���������";
		postpone();
		cout << "\n����������" << (int)(enemyMaxHealth * 0.1) << "������ֵ��\n";
		postpone();
		enemyBeingHeal(enemyMaxHealth * 0.1);
		break;

	}

	cout << "�з��غϽ�����\n";
	print_();
	printEndl();
	postpone(2);
	isBuffOver();
}
#include "TotalHead.h"

void BOSS::BOSSUseSkill(Player& player)
{

	int record = 0;

	switch (BOSSSkill.enemySkill.skillID) {
		//��׻�
	case 1:
		record = player.playerDefence;
		player.playerDefence = player.playerDefence / 2;
		cout << "������ʧ" << record / 2 << "�㡣\n";
		break;

		//ǿ����
	case 2:
		enemyAttack(player, enemyDamage * 1.5);
		break;
		
		//����
	case 3:
		player.buff.BuffUpdate(1, 1, 1);
		cout << "�㱻��Ĭ1�غϡ�" << endl;
		break;

		//��
	case 4:
		buff.BuffUpdate(3, 2, 3);
		cout << "���˹���������30������2�غϡ�" << endl;
		break;

		//��Ѫ
	case 5:
		record = enemyHealth * 0.2;
		enemyBeingHurt(record);
		cout << "�з��ܵ�" << record << "���˺���\n";
		enemyAttack(player, record * 0.3);
		break;

		//����
	case 6:
		player.buff.BuffUpdate(1, 2, 1);
		cout << "���ţţ��ס�ˣ����غ��޷��ж���" << endl;
		break;

		//��˪��Ӱ��
	case 7:
		cout << "�㱻��˪��Ӱ��������ţţ����ʹ��" << endl;
		enemyAttack(player, enemyDamage * 1.2);
		player.buff.BuffUpdate(2, 3, 3);
	}

	postpone();
}
/*
�з�����
1 = ����׻���  |����Ŀ��50%���ס�
2 = ��ǿ������  |���150%�˺���
3 = �����  |��ĬĿ��1�غϡ�
4 = ���񱩡�  |����������30������2�غϡ�
5 = ����Ѫ��  |���������ʣ������20%�˺�����������30%������Ŀ�ꡣ
*/
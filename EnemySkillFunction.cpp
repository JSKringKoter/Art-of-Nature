#include "TotalHead.h"

EnemySkillClass::EnemySkillClass()
{
	enemySkill.skillDescirbe = "Nothing";
	enemySkill.skillName = "NONE";
	enemySkill.skillID = 0;
}

EnemySkillClass::~EnemySkillClass() {};

/*
�з�����
1 = ����׻���  |����Ŀ��50%���ס�
2 = ��ǿ������  |���150%�˺���
3 = ��������  |��ĬĿ��1�غϡ�
4 = ���񱩡�  |����������30������2�غϡ�
5 = ����Ѫ��  |���������ʣ������30%�˺�����������Ŀ�ꡣ
6 = ��������  |��ĬĿ��2�غϡ�
7 = ��������Ӱ����  |�����������120%�˺������3�غϳ����˺���
*/
void EnemySkillClass::setEnemySkillTo(int ID)
{
	switch (ID) {
	case 1:
		enemySkill.skillName = "����׻���";
		enemySkill.skillDescirbe = "|����Ŀ��50%���ס�";
		break;
	case 2:
		enemySkill.skillName = "��ǿ������";
		enemySkill.skillDescirbe = "|���150%�˺���";
		break;
	case 3:
		enemySkill.skillName = "��������";
		enemySkill.skillDescirbe = "|��ĬĿ��1�غϡ�";
		break;
	case 4:
		enemySkill.skillName = "���񱩡�";
		enemySkill.skillDescirbe = "|����������30������2�غϡ�";
		break;
	case 5:
		enemySkill.skillName = "����Ѫ��";
		enemySkill.skillDescirbe = "|���������ʣ������30%�˺������������㡣";
		break;
	case 6:
		enemySkill.skillName = "��������";
		enemySkill.skillDescirbe = "|��ĬĿ��2�غϡ�";
		break;
	case 7:
		enemySkill.skillName = "��������Ӱ����";
		enemySkill.skillDescirbe = "|�����������120%�˺������3�غϳ����˺���";
	}

	enemySkill.skillID = ID;
}
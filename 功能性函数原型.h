#pragma once
#ifndef Function
#define Function
//��ӡ����
void print_(int lenth = 11);

//����������
void eatLine();

//����ѡ��
void countInChoice(int& choice);

//��ʽ����ӡ����
void printEndl(int lenth = 4);

//��ʱ
void postpone(double postponeTime = 0.8);

//���� ���������������������
/*
Base = ������ֵ
Rent = ������Χ
*/
void makeRand(int healthBase, int healthRent, int damageBase, int damageRent, int defenceBase, int defenceRent, 
	   int& health, int& damage, int& defence);

//��ӡ����
int printTital();

//��ȡ�浵
void readSave(int& health, int& damage, int& defence, int& energy);
void writeSave(int healthUp, int damageUp, int defenceUp, int energyUp);

#endif // !Function

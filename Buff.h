#pragma once
#ifndef Buff_h
#define Buff_h


class Buff
{
public:

	string BuffName;
	int BuffID;
	int Level;
	int Rend;
	bool isHasBuff;

	Buff();
	~Buff();

	/*
Buff����
0 = ��
1 = ��Ĭ
2 = �����˺�
3 = ����
4 = ����
*/
	void BuffUpdate(int ID, int rend, int level);
};

#endif // !Buff

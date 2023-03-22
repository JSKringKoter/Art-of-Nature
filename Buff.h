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
Buff更新
0 = 无
1 = 沉默
2 = 持续伤害
3 = 力量
4 = 虚弱
*/
	void BuffUpdate(int ID, int rend, int level);
};

#endif // !Buff

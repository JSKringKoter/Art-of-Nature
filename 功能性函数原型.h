#pragma once
#ifndef Function
#define Function
//打印横线
void print_(int lenth = 11);

//清理输入行
void eatLine();

//输入选择
void countInChoice(int& choice);

//格式化打印换行
void printEndl(int lenth = 4);

//延时
void postpone(double postponeTime = 0.8);

//产生 生命，攻击，防御随机数
/*
Base = 基础数值
Rent = 浮动范围
*/
void makeRand(int healthBase, int healthRent, int damageBase, int damageRent, int defenceBase, int defenceRent, 
	   int& health, int& damage, int& defence);

//打印标题
int printTital();

//读取存档
void readSave(int& health, int& damage, int& defence, int& energy);
void writeSave(int healthUp, int damageUp, int defenceUp, int energyUp);

#endif // !Function

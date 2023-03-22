#include "TotalHead.h"

EnemySkillClass::EnemySkillClass()
{
	enemySkill.skillDescirbe = "Nothing";
	enemySkill.skillName = "NONE";
	enemySkill.skillID = 0;
}

EnemySkillClass::~EnemySkillClass() {};

/*
敌方技能
1 = 【碎甲击】  |削减目标50%护甲。
2 = 【强力击】  |造成150%伤害。
3 = 【禁锢】  |沉默目标1回合。
4 = 【狂暴】  |攻击力提升30，持续2回合。
5 = 【暴血】  |对自身造成剩余生命30%伤害，并返还给目标。
6 = 【冰冻】  |沉默目标2回合。
7 = 【寒冰幻影剑】  |立即对你造成120%伤害，获得3回合持续伤害Ⅲ。
*/
void EnemySkillClass::setEnemySkillTo(int ID)
{
	switch (ID) {
	case 1:
		enemySkill.skillName = "【碎甲击】";
		enemySkill.skillDescirbe = "|削减目标50%护甲。";
		break;
	case 2:
		enemySkill.skillName = "【强力击】";
		enemySkill.skillDescirbe = "|造成150%伤害。";
		break;
	case 3:
		enemySkill.skillName = "【禁锢】";
		enemySkill.skillDescirbe = "|沉默目标1回合。";
		break;
	case 4:
		enemySkill.skillName = "【狂暴】";
		enemySkill.skillDescirbe = "|攻击力提升30，持续2回合。";
		break;
	case 5:
		enemySkill.skillName = "【暴血】";
		enemySkill.skillDescirbe = "|对自身造成剩余生命30%伤害，并返还给你。";
		break;
	case 6:
		enemySkill.skillName = "【冰冻】";
		enemySkill.skillDescirbe = "|沉默目标2回合。";
		break;
	case 7:
		enemySkill.skillName = "【寒冰幻影剑】";
		enemySkill.skillDescirbe = "|立即对你造成120%伤害，获得3回合持续伤害Ⅲ。";
	}

	enemySkill.skillID = ID;
}
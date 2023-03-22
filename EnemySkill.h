#pragma once
#ifndef ENERY_SKILL
#define ENERY_SKILL

class EnemySkillClass
{
public:
	struct EnemySkillInformation {
		int skillID;
		string skillName;
		string skillDescirbe;
	};

	EnemySkillInformation enemySkill;

	EnemySkillClass();
	~EnemySkillClass();

	void setEnemySkillTo(int ID);
};

#endif // !ENERY_SKILL

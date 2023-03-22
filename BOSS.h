#pragma once
#ifndef BOSS_H
#define BOSS_H


class BOSS :
    public Enemy
{
public:
    EnemySkillClass BOSSSkill;

    BOSS();
    BOSS(int enemy_health, int enemy_damage, int enemy_defence, string enemy_name, int skillType);
    ~BOSS();

    void BOSSUseSkill(Player& player);
    void BOSSActive(Player& player);
    virtual void showEnemyMenu();
};

#endif // !BOSS
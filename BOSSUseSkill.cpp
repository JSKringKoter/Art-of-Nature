#include "TotalHead.h"

void BOSS::BOSSUseSkill(Player& player)
{

	int record = 0;

	switch (BOSSSkill.enemySkill.skillID) {
		//碎甲击
	case 1:
		record = player.playerDefence;
		player.playerDefence = player.playerDefence / 2;
		cout << "护甲损失" << record / 2 << "点。\n";
		break;

		//强力击
	case 2:
		enemyAttack(player, enemyDamage * 1.5);
		break;
		
		//禁语
	case 3:
		player.buff.BuffUpdate(1, 1, 1);
		cout << "你被沉默1回合。" << endl;
		break;

		//狂暴
	case 4:
		buff.BuffUpdate(3, 2, 3);
		cout << "敌人攻击力提升30，持续2回合。" << endl;
		break;

		//暴血
	case 5:
		record = enemyHealth * 0.2;
		enemyBeingHurt(record);
		cout << "敌方受到" << record << "点伤害。\n";
		enemyAttack(player, record * 0.3);
		break;

		//冰冻
	case 6:
		player.buff.BuffUpdate(1, 2, 1);
		cout << "你的牛牛冻住了，两回合无法行动。" << endl;
		break;

		//冰霜幻影剑
	case 7:
		cout << "你被冰霜幻影剑击中了牛牛。剧痛！" << endl;
		enemyAttack(player, enemyDamage * 1.2);
		player.buff.BuffUpdate(2, 3, 3);
	}

	postpone();
}
/*
敌方技能
1 = 【碎甲击】  |削减目标50%护甲。
2 = 【强力击】  |造成150%伤害。
3 = 【禁语】  |沉默目标1回合。
4 = 【狂暴】  |攻击力提升30，持续2回合。
5 = 【暴血】  |对自身造成剩余生命20%伤害，并将其中30%返还给目标。
*/
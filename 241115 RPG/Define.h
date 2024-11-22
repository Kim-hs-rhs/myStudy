#pragma once

#define PURE = 0

template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

typedef struct tagInfo
{
	char szName[32];
	int iHp, iAttack, iArmor, iGold;
}INFO;

enum JOBINDEX { WORRIOR = 1, THIEF, MAGE, MONK, ARCHER, JOB_END };
enum ITEMINDEX { IT_WEAPON, IT_ARMOR, IT_MISC, IT_END };
enum MONSTERINDEX { M_EASY, M_NORMAL, M_HARD, M_END };
enum DUNGEONINDEX { DG_EASY, DG_NORMAL, DG_HARD, DG_END };
#pragma once

#include "Monster.h"
#include "Player.h"

class Field
{
public:
	enum MONSTERINDEX { EASY = 1, NORMAL, HARD, END };

public:
	Field();
	~Field();

public:
	void Initialize();
	void Update();
	void Release();

	int Fight();

	void Set_PlayerAddress(Player* pPlayer);

private:
	Player* m_CopyPlayerF;
	Monster* m_pMonster;
};


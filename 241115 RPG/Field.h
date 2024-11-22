#pragma once
#include "Dungeon.h"
#include "Player.h"

class Dungeon;

class Field
{
public:
	Field();
	~Field();

public:
	void Initialize();
	void Update();
	void Release();

public:
	void Set_Player(Base* pPlayer) { m_pPlayerF = pPlayer; }

private:
	Base* m_pPlayerF;
	Dungeon* m_pDungeon;
};


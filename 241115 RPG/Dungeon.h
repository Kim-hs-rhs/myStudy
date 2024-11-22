#pragma once
#include "Monster.h"
#include "Player.h"

class Dungeon
{
public:
	Dungeon();
	~Dungeon();

public:
	void Initialize();
	void Update(DUNGEONINDEX eType);
	void Release();

public:
	void Set_Player(Base* pPlayer) { m_pPlayerD = pPlayer; }

private:
	Base* m_pMonsterD[3];
	list<Base*> m_DungeonList;
	Base* m_pPlayerD;
};


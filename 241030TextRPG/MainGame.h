#pragma once

#include "Player.h"
#include "Field.h"
#include "Store.h"

class MainGame
{
public:
	enum AREAINDEX { FIELD = 1, STORE, ENDGAME };

public:
	MainGame();
	~MainGame();

public:
	void Initialize();
	void Update();
	void Release();

private:
	Player* m_pPlayer;
	Field* m_pField;
	Store* m_pStore;
};


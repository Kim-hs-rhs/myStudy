#pragma once
#include "Item.h"
#include "Player.h"

class Inven
{
public:
	Inven();
	~Inven();

public:
	void Initialize();
	void Update();
	bool Result_Buy(ITEMINDEX eType, Base* pItem);
	void Release();

public:
	void Set_Player(Base* pPlayer) { m_pPlayerI = pPlayer; }
	void Render();

private:
	vector<Base*> m_vecInven[IT_END];
	Base* m_pPlayerI;
	const int m_InvenSize;
};


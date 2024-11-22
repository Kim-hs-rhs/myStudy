#pragma once
#include "Item.h"
#include "Player.h"

class Inven;

class Store
{
public:
	Store();
	~Store();

public:
	void Initialize();
	void Update();
	void Release();

public:
	void Select(ITEMINDEX eType);
	void Select_Coffee();
	void Buy(ITEMINDEX eType);
	

public:
	void Set_Player(Base* pPlayer) { m_pPlayerS = pPlayer; }
	void Set_Inven(Inven* pInven) { m_pInvenS = pInven; }

private:
	vector<Base*> vecItem[IT_END];
	map<int, Base*> m_mapItem;
	Base* m_pPlayerS;
	Inven* m_pInvenS;
};


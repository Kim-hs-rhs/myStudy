#pragma once

#include "Player.h"
#include "Weapon.h"
#include "Armor.h"

class Store
{
public:
	Store();
	~Store();

public:
	void Initialize();
	void Update();
	void Release();
	
	void Select_Buy();
	void Select_Enforce();

	void Buy_Weapon();
	void Buy_Armor();

	

public:
	void Set_PlayerAddress(Player* pPlayer) { m_CopyPlayerS = pPlayer; }

private:
	Player* m_CopyPlayerS;
	Weapon* m_pWeapon;
	Armor* m_pArmor;
};


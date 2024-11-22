#pragma once
#include "Base.h"
#include "MainGame.h"
#include "Inven.h"

class Inven;

class Player final : public Base
{
public:
	Player();
	virtual ~Player();

public:
	virtual void Render()override;
	void Set_Attack(int _iAttack) { m_tInfo.iAttack += _iAttack; }
	void Set_Armor(int _iArmor) { m_tInfo.iArmor += _iArmor; }
	void Set_Hp(int _iHp) { m_tInfo.iHp += _iHp; if (100 < m_tInfo.iHp) { m_tInfo.iHp = 100; } }
	void Set_Gold(int _iGold) { m_tInfo.iGold += _iGold; }

public:
	bool Select_Job();
	void Update();
	void Release();

public:
	void Set_Inven(Inven* pInven) { m_pInvenP = pInven; }
	bool Equip(Base* pItem, ITEMINDEX eType);
	void Render_Equip();

private:
	vector<Base*> m_vecEquip[2];
	Inven* m_pInvenP;
};


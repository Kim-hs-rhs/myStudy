#pragma once

#include "Define.h"

class Monster
{
public:
	Monster();
	~Monster();

public:
	void Initialize_Easy();
	void Initialize_Normal();
	void Initialize_Hard();
	void Update();
	void Release();

public:
	void Render();

	void Set_Hp(int _iHp) { m_tInfo.iHp = _iHp; }
	void Set_Attack(int _iAttack) { m_tInfo.iAttack = _iAttack; }
	void Set_Shield(int _iShield) { m_tInfo.iShield = _iShield; }
	void Set_Gold(int _iGold) { m_tInfo.iGold = _iGold; }

	int Get_Hp() { return m_tInfo.iHp; }
	int Get_Attack() { return m_tInfo.iAttack; }
	int Get_Shield() { return m_tInfo.iShield; }
	int Get_Gold() { return m_tInfo.iGold; }

	INFO Get_Info() { return m_tInfo; }

	void Set_Damage(int _iAttack) { m_tInfo.iHp -= _iAttack; }

	

private:
	INFO m_tInfo;
};


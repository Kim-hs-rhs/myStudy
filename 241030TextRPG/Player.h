#pragma once

#include "Define.h"

class Player
{
public:
	enum JOBINDEX { WORRIOR = 1, THIEF, MAGE, MONK, ARCHER };

public:
	Player();
	~Player();
	
	Player(const Player& rhs);

public:
	void Initialize();
	void Update();
	void Release();

	void Render();
	
	static void Draw_Line();

	void Victory();  // ÀüÅõ ½Â¸® È½¼ö

public:
	void Set_Job(const char* pName) { strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), pName); }
	
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
	void Add_Gold(int _iGold) { m_tInfo.iGold += _iGold; }
	void Add_Attack(int _iAttack) { m_tInfo.iAttack += _iAttack; }
	void Add_Shield(int _iShield) { m_tInfo.iShield += _iShield; }
	void Minus_Gold(int _iGold) { m_tInfo.iGold -= _iGold; }

	void Death();

	//this ¿¬½À¿ë
	Player* Get_this()
	{
		return this;
	}


private:
	INFO m_tInfo;
	static int iVictory;
};


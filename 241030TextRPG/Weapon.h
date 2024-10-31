#pragma once

#include "Define.h"

class Weapon
{
public:
	Weapon();
	~Weapon();

public:
	void Initialize();
	void Update();
	void Release();

	void Render();

	void Set_Weapon_01();
	void Set_Weapon_02();
	void Set_Weapon_03();
		

	const char* Get_Name(int _iNumber) { return m_tInfo[_iNumber - 1].szName; }
	
	int Get_Attack(int _iNumber) { return m_tInfo[_iNumber - 1].iAttack; }
	
	int Get_Price(int _iNumber) { return m_tInfo[_iNumber - 1].iPrice; }

private:
	WINFO m_tInfo[3];
};


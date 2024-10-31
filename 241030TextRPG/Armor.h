#pragma once

#include "Define.h"

class Armor
{
public:
	Armor();
	~Armor();

public:
	void Initialize();
	void Update();
	void Release();

	void Render();

	const char* Get_Name() { return m_tInfo.szName; }

	int Get_Shield() { return m_tInfo.iShield; }
	int Get_Price() { return m_tInfo.iPrice; }


private:
	AINFO m_tInfo;
};


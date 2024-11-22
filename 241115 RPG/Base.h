#pragma once
#include "Define.h"

class Base abstract
{
public:
	Base();
	Base(const char* pName, int _iHp, int _iAttack, int _iArmor, int _iGold);
	virtual ~Base();

public:
	virtual void Render() PURE;
	
public:
	INFO Get_Info() { return m_tInfo; }

protected:
	INFO	m_tInfo;
};


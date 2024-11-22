#include "pch.h"
#include "Base.h"

Base::Base()
{
}

Base::Base(const char* pName, int _iHp, int _iAttack, int _iArmor, int _iGold)
{
	strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), pName);
	m_tInfo.iHp = _iHp;
	m_tInfo.iAttack = _iAttack;
	m_tInfo.iArmor = _iArmor;
	m_tInfo.iGold = _iGold;
}

Base::~Base()
{
}



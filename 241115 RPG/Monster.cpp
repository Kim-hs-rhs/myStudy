#include "pch.h"
#include "Monster.h"

Monster::Monster()
{
}

Monster::~Monster()
{
}

void Monster::Render()
{
	MainGame::Draw_Line();
	cout << "이름 : " << m_tInfo.szName << "\t 보상 : " << m_tInfo.iGold << endl;
	cout << "체력 : " << m_tInfo.iHp << "\t 공격력 : " << m_tInfo.iAttack << "\t 방어력 : " << m_tInfo.iArmor << endl;
}

void Monster::Set_Monster(MONSTERINDEX eType)
{
	if (eType == M_EASY)
	{
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "초급");
		m_tInfo.iHp = 30;
		m_tInfo.iAttack = 3;
		m_tInfo.iArmor = 0;
		m_tInfo.iGold = 100;
	}

	if (eType == M_NORMAL)
	{
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "중급");
		m_tInfo.iHp = 60;
		m_tInfo.iAttack = 6;
		m_tInfo.iArmor = 1;
		m_tInfo.iGold = 200;
	}

	if (eType == M_HARD)
	{
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "고급");
		m_tInfo.iHp = 90;
		m_tInfo.iAttack = 9;
		m_tInfo.iArmor = 2;
		m_tInfo.iGold = 300;
	}
}

void Monster::Initialize()
{
}

void Monster::Update()
{
}

void Monster::Release()
{
}

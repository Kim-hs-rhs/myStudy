#include "pch.h"
#include "Item.h"

Item::Item()
{
}

Item::Item(const char* pName, int _iHp, int _iAttack, int _iArmor, int _iGold)
	:Base(pName, _iHp, _iAttack, _iArmor, _iGold)
{
}

Item::~Item()
{
}

void Item::Render()
{
	MainGame::Draw_Line();
	cout << "이름 : " << m_tInfo.szName << "\t 가격 : " << m_tInfo.iGold << endl;
	cout << "체력 : " << m_tInfo.iHp << "\t 공격력 : " << m_tInfo.iAttack << "\t 방어력 : " << m_tInfo.iArmor << endl;
}

void Item::Initialize()
{
}

void Item::Update()
{
}

void Item::Release()
{
}

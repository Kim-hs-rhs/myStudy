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
	cout << "�̸� : " << m_tInfo.szName << "\t ���� : " << m_tInfo.iGold << endl;
	cout << "ü�� : " << m_tInfo.iHp << "\t ���ݷ� : " << m_tInfo.iAttack << "\t ���� : " << m_tInfo.iArmor << endl;
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

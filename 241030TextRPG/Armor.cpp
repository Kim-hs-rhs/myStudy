#include "pch.h"
#include "Armor.h"
#include "Player.h"

Armor::Armor()
{
	memset(&m_tInfo, 0, sizeof(AINFO));
}

Armor::~Armor()
{
	Release();
}

void Armor::Initialize()
{
	strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "Ãµ°©¿Ê");
	m_tInfo.iShield = 1;
	m_tInfo.iPrice = 1000;
}

void Armor::Update()
{
}

void Armor::Release()
{
}

void Armor::Render()
{
	Player::Draw_Line();
	cout << "ÀÌ¸§ : " << m_tInfo.szName << '\t' << "¹æ¾î·Â : " << m_tInfo.iShield << '\t' << "°¡°Ý : " << m_tInfo.iPrice << endl;
	Player::Draw_Line();
}

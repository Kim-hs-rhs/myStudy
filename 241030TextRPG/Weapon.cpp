#include "pch.h"
#include "Weapon.h"
#include "Player.h"

Weapon::Weapon()
{
	for (int i = 0; i < 3; ++i)
	{
		memset(&(m_tInfo[i]), 0, sizeof(WINFO));
	}
}

Weapon::~Weapon()
{
	Release();
}

void Weapon::Initialize()
{
	Set_Weapon_01();
	Set_Weapon_02();
	Set_Weapon_03();
}

void Weapon::Update()
{

}

void Weapon::Release()
{

}

void Weapon::Render()
{
	Player::Draw_Line();
	for (int i = 0; i < 3; ++i)
	{
		cout << "�̸� : " << m_tInfo[i].szName << '\t' << "���ݷ� : " << m_tInfo[i].iAttack << '\t' << "���� : " << m_tInfo[i].iPrice << endl;
	}
	Player::Draw_Line();
}

void Weapon::Set_Weapon_01()
{
	strcpy_s(m_tInfo[0].szName, sizeof(m_tInfo[0].szName), "���");
	m_tInfo[0].iAttack = 5;
	m_tInfo[0].iPrice = 500;
}

void Weapon::Set_Weapon_02()
{
	strcpy_s(m_tInfo[1].szName, sizeof(m_tInfo[1].szName), "���ҵ�");
	m_tInfo[1].iAttack = 10;
	m_tInfo[1].iPrice = 1000;
}

void Weapon::Set_Weapon_03()
{
	strcpy_s(m_tInfo[2].szName, sizeof(m_tInfo[2].szName), "�ռҵ�");
	m_tInfo[2].iAttack = 20;
	m_tInfo[2].iPrice = 2000;
}

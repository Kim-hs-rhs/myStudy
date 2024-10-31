#include "pch.h"
#include "Monster.h"
#include "Player.h"

Monster::Monster()
{
	memset(&m_tInfo, 0, sizeof(INFO));
}

Monster::~Monster()
{
	Release();
}

void Monster::Initialize_Easy()
{
	strcpy_s(m_tInfo.szName, sizeof(&m_tInfo.szName), "초급");
	Set_Attack(3);
	Set_Hp(30);
	Set_Shield(0);
	Set_Gold(300);
}

void Monster::Initialize_Normal()
{
	strcpy_s(m_tInfo.szName, sizeof(&m_tInfo.szName), "중급");
	Set_Attack(6);
	Set_Hp(60);
	Set_Shield(2);
	Set_Gold(600);
}

void Monster::Initialize_Hard()
{
	strcpy_s(m_tInfo.szName, sizeof(&m_tInfo.szName), "고급");
	Set_Attack(9);
	Set_Hp(90);
	Set_Shield(3);
	Set_Gold(900);
}

void Monster::Update()
{
}

void Monster::Release()
{
}

void Monster::Render()
{
	Player::Draw_Line();
	cout << "이름 : " << m_tInfo.szName << endl;
	cout << "체력 : " << m_tInfo.iHp << '\t' << "공격력 : " << m_tInfo.iAttack << '\t' << "방어력 : " << m_tInfo.iShield << '\t' << "골드 : " << m_tInfo.iGold << endl;
}

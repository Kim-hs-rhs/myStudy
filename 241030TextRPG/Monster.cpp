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
	strcpy_s(m_tInfo.szName, sizeof(&m_tInfo.szName), "�ʱ�");
	Set_Attack(3);
	Set_Hp(30);
	Set_Shield(0);
	Set_Gold(300);
}

void Monster::Initialize_Normal()
{
	strcpy_s(m_tInfo.szName, sizeof(&m_tInfo.szName), "�߱�");
	Set_Attack(6);
	Set_Hp(60);
	Set_Shield(2);
	Set_Gold(600);
}

void Monster::Initialize_Hard()
{
	strcpy_s(m_tInfo.szName, sizeof(&m_tInfo.szName), "���");
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
	cout << "�̸� : " << m_tInfo.szName << endl;
	cout << "ü�� : " << m_tInfo.iHp << '\t' << "���ݷ� : " << m_tInfo.iAttack << '\t' << "���� : " << m_tInfo.iShield << '\t' << "��� : " << m_tInfo.iGold << endl;
}

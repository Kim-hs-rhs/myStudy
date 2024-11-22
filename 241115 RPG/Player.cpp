#include "pch.h"
#include "Player.h"

Player::Player() : m_pInvenP(nullptr)
{
	memset(&m_tInfo, 0, sizeof(INFO));

	m_vecEquip[0].reserve(1);
	m_vecEquip[1].reserve(1);

	m_vecEquip[0].push_back(nullptr);
	m_vecEquip[1].push_back(nullptr);
}

Player::~Player()
{
	Release();
}

void Player::Render()
{
	MainGame::Draw_Line();
	cout << "이름 : " << m_tInfo.szName << "\t 골드 : " << m_tInfo.iGold << endl;
	cout << "체력 : " << m_tInfo.iHp << "\t 공격력 : " << m_tInfo.iAttack << "\t 방어력 : " << m_tInfo.iArmor << endl;
}

bool Player::Select_Job()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		cout << "0. 이전화면 1. 전사 2. 도적 3. 마법사 4. 도사, 5. 궁사 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 0:
			return false;

		case WORRIOR:
			strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "전사");
			m_tInfo.iHp = 100;
			m_tInfo.iAttack = 10;
			m_tInfo.iArmor = 1;
			m_tInfo.iGold = 10000;
			break;

		case THIEF:
			strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "도적");
			m_tInfo.iHp = 100;
			m_tInfo.iAttack = 10;
			m_tInfo.iArmor = 1;
			m_tInfo.iGold = 10000;
			break;

		case MAGE:
			strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "마법사");
			m_tInfo.iHp = 100;
			m_tInfo.iAttack = 10;
			m_tInfo.iArmor = 1;
			m_tInfo.iGold = 10000;
			break;
		
		case MONK:
			strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "도사");
			m_tInfo.iHp = 100;
			m_tInfo.iAttack = 10;
			m_tInfo.iArmor = 1;
			m_tInfo.iGold = 10000;
			break;

		case ARCHER:
			strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "궁사");
			m_tInfo.iHp = 100;
			m_tInfo.iAttack = 10;
			m_tInfo.iArmor = 1;
			m_tInfo.iGold = 10000;
			break;

		default:
			cout << "잘못된 입력" << endl;
			system("pause");
			continue;
		}

		return true;
	}
}

void Player::Update()
{
}

void Player::Release()
{
}

// 두번째 장착이면 true를 반환//
bool Player::Equip(Base* pItem, ITEMINDEX eType)
{
	if (nullptr == m_vecEquip[eType][0])
	{
		m_vecEquip[eType].push_back(pItem);
		return false;
	}
	
	m_vecEquip[eType].pop_back();
	m_vecEquip[eType][0] = nullptr;
	m_vecEquip[eType].push_back(pItem);

	return true;
}

void Player::Render_Equip()
{
	if (!m_vecEquip[0][0])
	{
		cout << "장착한 무기가 없습니다." << endl;
	}

	else
	{
		cout << "현재 장착한 무기 : " << m_vecEquip[0][0]->Get_Info().szName << endl;
	}

	if (!m_vecEquip[1][0])
	{
		cout << "장착한 방어구가 없습니다." << endl;
	}

	else
	{
		cout << "현재 장착한 방어구 : " << m_vecEquip[1][0]->Get_Info().szName << endl;
	}

	cout << endl;
}

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
	cout << "�̸� : " << m_tInfo.szName << "\t ��� : " << m_tInfo.iGold << endl;
	cout << "ü�� : " << m_tInfo.iHp << "\t ���ݷ� : " << m_tInfo.iAttack << "\t ���� : " << m_tInfo.iArmor << endl;
}

bool Player::Select_Job()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		cout << "0. ����ȭ�� 1. ���� 2. ���� 3. ������ 4. ����, 5. �û� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 0:
			return false;

		case WORRIOR:
			strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "����");
			m_tInfo.iHp = 100;
			m_tInfo.iAttack = 10;
			m_tInfo.iArmor = 1;
			m_tInfo.iGold = 10000;
			break;

		case THIEF:
			strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "����");
			m_tInfo.iHp = 100;
			m_tInfo.iAttack = 10;
			m_tInfo.iArmor = 1;
			m_tInfo.iGold = 10000;
			break;

		case MAGE:
			strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "������");
			m_tInfo.iHp = 100;
			m_tInfo.iAttack = 10;
			m_tInfo.iArmor = 1;
			m_tInfo.iGold = 10000;
			break;
		
		case MONK:
			strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "����");
			m_tInfo.iHp = 100;
			m_tInfo.iAttack = 10;
			m_tInfo.iArmor = 1;
			m_tInfo.iGold = 10000;
			break;

		case ARCHER:
			strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "�û�");
			m_tInfo.iHp = 100;
			m_tInfo.iAttack = 10;
			m_tInfo.iArmor = 1;
			m_tInfo.iGold = 10000;
			break;

		default:
			cout << "�߸��� �Է�" << endl;
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

// �ι�° �����̸� true�� ��ȯ//
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
		cout << "������ ���Ⱑ �����ϴ�." << endl;
	}

	else
	{
		cout << "���� ������ ���� : " << m_vecEquip[0][0]->Get_Info().szName << endl;
	}

	if (!m_vecEquip[1][0])
	{
		cout << "������ ���� �����ϴ�." << endl;
	}

	else
	{
		cout << "���� ������ �� : " << m_vecEquip[1][0]->Get_Info().szName << endl;
	}

	cout << endl;
}

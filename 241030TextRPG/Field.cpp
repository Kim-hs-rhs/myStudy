#include "pch.h"
#include "Field.h"
#include "Define.h"
#include "Player.h"

int Player::iVictory = 0;

Field::Field() : m_CopyPlayerF(nullptr), m_pMonster(nullptr)
{
	
}

Field::~Field()
{
	Release();
}

void Field::Initialize()
{
}

void Field::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		m_CopyPlayerF->Render();
		
		cout << "1. �ʱ� 2. �߱� 3. ��� 4. �� �ܰ� : ";
		cin >> iInput;

		switch (iInput)
		{
		case Field::EASY:
			m_pMonster = new Monster;
			m_pMonster->Initialize_Easy();
			break;

		case Field::NORMAL:
			m_pMonster = new Monster;
			m_pMonster->Initialize_Normal();
			break;

		case Field::HARD:
			m_pMonster = new Monster;
			m_pMonster->Initialize_Hard();
			break;

		case Field::END:
			return;
			
		default:
			cout << "�߸��� �Է�" << endl;
			system("pause");
			continue;
		}

		int iResult = Fight();

		if (1 == iResult)
		{
			
		}

		if (0 == iResult)
		{
			SAFE_DELETE(m_pMonster);
		}
	}
}

void Field::Release()
{
	SAFE_DELETE(m_pMonster);
}

int Field::Fight()
{
	Player player;
	
	int iInput(0);
	
	while (true)
	{
		system("cls");

		m_CopyPlayerF->Render();
		m_pMonster->Render();

		cout << "1. ���� 2. ���� : ";
		cin >> iInput;

		if (1 == iInput)
		{
			m_CopyPlayerF->Set_Damage(m_pMonster->Get_Info().iAttack - m_CopyPlayerF->Get_Info().iShield);
			m_pMonster->Set_Damage(m_CopyPlayerF->Get_Info().iAttack - m_pMonster->Get_Info().iShield);

			if (0 >= m_CopyPlayerF->Get_Info().iHp)
			{
				m_CopyPlayerF->Death();
				system("pause");
				return 1;
			}

			if (0 >= m_pMonster->Get_Info().iHp)
			{
				m_CopyPlayerF->Add_Gold(m_pMonster->Get_Info().iGold);
				cout << "���� óġ�߽��ϴ�." << endl;
				player.Victory();
				system("pause");
				return 0;
			}
		}

		else if (2 == iInput)
		{
			return 0;
		}

		else
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			system("pause");
			continue;
		}
	}
}

void Field::Set_PlayerAddress(Player* pPlayer)
{
	m_CopyPlayerF = pPlayer;
}

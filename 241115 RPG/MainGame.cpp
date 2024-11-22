#include "pch.h"
#include "MainGame.h"

MainGame::MainGame() : m_pPlayer(nullptr), m_pField(nullptr), m_pStore(nullptr), m_pInven(nullptr)
{
}

MainGame::~MainGame()
{
	Release();
}

bool MainGame::Initialize()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		cout << "1. ���� ���� 2. ���� : ";
		cin >> iInput;

		if (2 == iInput)
		{
			return false;
		}

		else if (1 == iInput)
		{
			if (!m_pPlayer)
			{
				m_pPlayer = new Player;
				if (!dynamic_cast<Player*>(m_pPlayer)->Select_Job())
				{
					Safe_Delete(m_pPlayer);
					continue;
				}
			}

			if (!m_pField)
			{
				m_pField = new Field;
				
			}

			if (!m_pStore)
			{
				m_pStore = new Store;
				m_pStore->Initialize();
			}

			if (!m_pInven)
			{
				m_pInven = new Inven;
			}

			m_pStore->Set_Player(m_pPlayer);
			m_pStore->Set_Inven(m_pInven);
			m_pInven->Set_Player(m_pPlayer);
			m_pField->Set_Player(m_pPlayer);
			dynamic_cast<Player*>(m_pPlayer)->Set_Inven(m_pInven);
		}
		
		else
		{
			cout << "�߸��� �Է�" << endl;
			system("pause");
			continue;
		}

		return true;
	}
}

void MainGame::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		m_pPlayer->Render();

		cout << "1. ����� 2. ���� 3. �κ��丮 4. ���� ���� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pField->Initialize();
			m_pField->Update();
			break;

		case 2:
			m_pStore->Update();
			break;

		case 3:
			m_pInven->Update();
			break;

		case 4:
			return;

		default:
			cout << "�߸��� �Է�" << endl;
			system("pause");
		}
	}
}

void MainGame::Release()
{
	Safe_Delete<Base*>(m_pPlayer);
	Safe_Delete<Field*>(m_pField);
	Safe_Delete<Store*>(m_pStore);
	Safe_Delete<Inven*>(m_pInven);
}

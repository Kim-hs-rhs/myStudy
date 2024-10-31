#include "pch.h"
#include "MainGame.h"

MainGame::MainGame() : m_pPlayer(nullptr), m_pField(nullptr), m_pStore(nullptr)
{
	
}

MainGame::~MainGame()
{
	Release();
}

void MainGame::Initialize()
{
	if (!m_pPlayer)
	{
		m_pPlayer = new Player;
		m_pPlayer->Initialize();
	}

	if (!m_pField)
	{
		m_pField = new Field;
	}

	if (!m_pStore)
	{
		m_pStore = new Store;
	}

	m_pField->Set_PlayerAddress(m_pPlayer->Get_this());
	m_pStore->Set_PlayerAddress(m_pPlayer->Get_this());
}

void MainGame::Update()
{
	int iInput(0);
	
	while (true)
	{
		system("cls");

		m_pPlayer->Render();

		cout << "1. ����� 2. ���� 3. ���� : ";
		cin >> iInput;
		
		switch (iInput)
		{
		case MainGame::FIELD:
			m_pField->Update();
			
			break;

		case MainGame::STORE:
			m_pStore->Update();
			
			break;

		case MainGame::ENDGAME:
			cout << "������ �����մϴ�." << endl;
			system("pause");
			return;

		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			system("pause");
			continue;
		}
	}
}

void MainGame::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pField);
	SAFE_DELETE(m_pStore);
}

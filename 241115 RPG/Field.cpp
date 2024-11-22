#include "pch.h"
#include "Field.h"

Field::Field() : m_pPlayerF(nullptr), m_pDungeon(nullptr)
{
}

Field::~Field()
{
	Release();
}

void Field::Initialize()
{
	m_pDungeon = new Dungeon;
	m_pDungeon->Set_Player(m_pPlayerF);
}

void Field::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");
		m_pPlayerF->Render();

		cout << "던전을 선택하세요(0. 돌아가기, 1. 초급 2. 중급 3. 고급) : ";
		cin >> iInput;

		--iInput;

		if (-1 == iInput)
		{
			return;
		}
		
		m_pDungeon->Initialize();
		m_pDungeon->Update((DUNGEONINDEX)iInput);
	}
}

void Field::Release()
{
	Safe_Delete<Dungeon*>(m_pDungeon);
}

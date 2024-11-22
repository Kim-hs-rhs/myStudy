#include "pch.h"
#include "Dungeon.h"

Dungeon::Dungeon()
{
	for (int i = 0; i < 3; ++i)
	{
		m_pMonsterD[i] = nullptr;
	}
}

Dungeon::~Dungeon()
{
	Release();
}

void Dungeon::Initialize()
{
	for (int i = 0; i < 3; ++i)
	{
		m_pMonsterD[i] = new Monster;
	}

	dynamic_cast<Monster*>(m_pMonsterD[0])->Set_Monster(M_EASY);
	dynamic_cast<Monster*>(m_pMonsterD[1])->Set_Monster(M_NORMAL);
	dynamic_cast<Monster*>(m_pMonsterD[2])->Set_Monster(M_HARD);

	for (int i = 0; i < 3; ++i)
	{
		m_DungeonList.push_back(m_pMonsterD[i]);
	}
}

void Dungeon::Update(DUNGEONINDEX eType)
{
	int iInput(0);

	list<Base*>::iterator iter = m_DungeonList.begin();

	while (true)
	{
		system("cls");

		m_pPlayerD->Render();

		iter = m_DungeonList.begin();

		if (DG_EASY == eType)
		{
			(*iter)->Render();
		}

		else if (DG_NORMAL == eType)
		{
			iter++;
			(*iter)->Render();
		}

		else if (DG_HARD == eType)
		{
			iter++;
			iter++;
			(*iter)->Render();
		}

		cout << "1. 공격 2. 방어 3. 도망 : ";
		cin >> iInput;

		if (3 == iInput)
			return;

		else if (2 == iInput)
		{
			dynamic_cast<Player*>(m_pPlayerD)->Set_Hp(-(dynamic_cast<Monster*>(*iter)->Get_Info().iAttack - dynamic_cast<Player*>(m_pPlayerD)->Get_Info().iArmor));
			
		}

		else if (1 == iInput)
		{
			
		}
		
		else
		{
			cout << "잘못된 입력" << endl;
			system("pause");
		}
	}
}

void Dungeon::Release()
{
	for_each(m_DungeonList.begin(), m_DungeonList.end(), Safe_Delete<Base*>);
	m_DungeonList.clear();
}

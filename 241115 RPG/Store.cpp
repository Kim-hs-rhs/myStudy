#include "pch.h"
#include "Store.h"

Store::Store() : m_pPlayerS(nullptr), m_pInvenS(nullptr)
{
	
}

Store::~Store()
{
}

void Store::Initialize() //pName, _iHp, _iAttack, _iArmor, _iGold
{
	vecItem[IT_WEAPON].push_back(new Item("숏소드", 0, 10, 0, 1000));
	vecItem[IT_WEAPON].push_back(new Item("롱소드", 0, 20, 0, 2000));
	vecItem[IT_WEAPON].push_back(new Item("에스톡", 0, 30, 0, 3000));

	vecItem[IT_ARMOR].push_back(new Item("천갑옷", 0, 0, 1, 500));
	vecItem[IT_ARMOR].push_back(new Item("철갑옷", 0, 0, 2, 1500));
	vecItem[IT_ARMOR].push_back(new Item("금갑옷", 0, 0, 3, 2500));

	vecItem[IT_MISC].push_back(new Item("하급포션", 10, 0, 0, 300));
	vecItem[IT_MISC].push_back(new Item("중급포션", 20, 0, 0, 400));
	vecItem[IT_MISC].push_back(new Item("고급포션", 30, 0, 0, 500));

	m_mapItem.emplace(1, new Item("카페라떼", 0, 50, 0, 2500));
	m_mapItem.emplace(2, new Item("카페모카", 0, 60, 0, 3000));
	m_mapItem.emplace(3, new Item("믹스커피", 0, 50, 0, 2500));
}

void Store::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		m_pPlayerS->Render();
		
		cout << "0. 커피 1. 무기 2. 방어구 3. 잡템 4. 돌아가기 : ";
		cin >> iInput;

		if (4 == iInput)
		{
			return;
		}
		
		else if (1 <= iInput && 3 >= iInput)
		{
			Select((ITEMINDEX)(iInput - 1));
		}

		else if (0 == iInput)
		{
			Select_Coffee();
		}

		else
		{
			cout << "잘못된 입력" << endl;
			system("pause");
		}
	}
}

void Store::Release()
{
	for (int i = 0; i < IT_END; ++i)
	{
		for_each(vecItem[i].begin(), vecItem[i].end(), Safe_Delete<Base*>);
		vecItem[i].clear();
	}

	map<int, Base*>::iterator iter = m_mapItem.begin();

	for (; iter != m_mapItem.end(); ++iter)
	{
		Safe_Delete<Base*>(iter->second);
	}
	
	for (size_t i = 0; i < m_mapItem.size(); ++i)
	{
		m_mapItem.erase(i);
	}
}

void Store::Select(ITEMINDEX eType)
{
	int iInput(0);
	
	while (true)
	{
		system("cls");

		m_pPlayerS->Render();

		for (size_t i = 0; i < vecItem[eType].size(); ++i)
		{
			vecItem[eType][i]->Render();
		}

		cout << "1. 구매 2. 판매 3. 돌아가기 : ";
		cin >> iInput;
		cout << endl;

		switch (iInput)
		{
		case 1:
			Buy(eType);
			break;

		case 2:
			break;

		case 3:
			return;

		default:
			cout << "잘못된 입력" << endl;
			system("pause");
		}
	}
}

void Store::Select_Coffee()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		m_pPlayerS->Render();

		for (map<int, Base*>::iterator iter = m_mapItem.begin()
			; iter != m_mapItem.end(); ++iter)
		{
			cout << (*iter).first << endl;
			(*iter).second->Render();
		}

		cout << "커피 선택(0. 돌아가기) : ";
		cin >> iInput;

		if (0 == iInput)
		{
			return;
		}

		system("pause");
	}
}

void Store::Buy(ITEMINDEX eType)
{
	int iInput(0);

	while (true)
	{
		system("cls");

		m_pPlayerS->Render();

		for (size_t i = 0; i < vecItem[eType].size(); ++i)
		{
			vecItem[eType][i]->Render();
		}

		cout << "구매할 물건 선택(0. 돌아가기)";

		for (int i = 0; i < 3; ++i)
		{
			cout << " " << i + 1 << ". " << vecItem[eType][i]->Get_Info().szName;
		}
		cout << " : ";
		cin >> iInput;

		if (0 == iInput)
		{
			return;
		}

		else if (0 < iInput && 4 > iInput)
		{
			if (m_pPlayerS->Get_Info().iGold < vecItem[eType][iInput - 1]->Get_Info().iGold)
			{
				cout << "돈이 부족합니다." << endl;
				system("pause");
			}

			else if (m_pPlayerS->Get_Info().iGold >= vecItem[eType][iInput - 1]->Get_Info().iGold
				&& m_pInvenS->Result_Buy(eType, vecItem[eType][iInput - 1]))
			{
				dynamic_cast<Player*>(m_pPlayerS)->Set_Gold(-vecItem[eType][iInput - 1]->Get_Info().iGold);
				cout << vecItem[eType][iInput - 1]->Get_Info().szName << "구매 성공" << endl;
				system("pause");
			}

			else
			{
				cout << "인벤토리가 가득 찼습니다." << endl;
				system("pause");
			}
		}

		else
		{
			cout << "잘못된 입력" << endl;
			system("pause");
		}
	}
}

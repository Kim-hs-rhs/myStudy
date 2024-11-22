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
	vecItem[IT_WEAPON].push_back(new Item("���ҵ�", 0, 10, 0, 1000));
	vecItem[IT_WEAPON].push_back(new Item("�ռҵ�", 0, 20, 0, 2000));
	vecItem[IT_WEAPON].push_back(new Item("������", 0, 30, 0, 3000));

	vecItem[IT_ARMOR].push_back(new Item("õ����", 0, 0, 1, 500));
	vecItem[IT_ARMOR].push_back(new Item("ö����", 0, 0, 2, 1500));
	vecItem[IT_ARMOR].push_back(new Item("�ݰ���", 0, 0, 3, 2500));

	vecItem[IT_MISC].push_back(new Item("�ϱ�����", 10, 0, 0, 300));
	vecItem[IT_MISC].push_back(new Item("�߱�����", 20, 0, 0, 400));
	vecItem[IT_MISC].push_back(new Item("�������", 30, 0, 0, 500));

	m_mapItem.emplace(1, new Item("ī���", 0, 50, 0, 2500));
	m_mapItem.emplace(2, new Item("ī���ī", 0, 60, 0, 3000));
	m_mapItem.emplace(3, new Item("�ͽ�Ŀ��", 0, 50, 0, 2500));
}

void Store::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		m_pPlayerS->Render();
		
		cout << "0. Ŀ�� 1. ���� 2. �� 3. ���� 4. ���ư��� : ";
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
			cout << "�߸��� �Է�" << endl;
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

		cout << "1. ���� 2. �Ǹ� 3. ���ư��� : ";
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
			cout << "�߸��� �Է�" << endl;
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

		cout << "Ŀ�� ����(0. ���ư���) : ";
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

		cout << "������ ���� ����(0. ���ư���)";

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
				cout << "���� �����մϴ�." << endl;
				system("pause");
			}

			else if (m_pPlayerS->Get_Info().iGold >= vecItem[eType][iInput - 1]->Get_Info().iGold
				&& m_pInvenS->Result_Buy(eType, vecItem[eType][iInput - 1]))
			{
				dynamic_cast<Player*>(m_pPlayerS)->Set_Gold(-vecItem[eType][iInput - 1]->Get_Info().iGold);
				cout << vecItem[eType][iInput - 1]->Get_Info().szName << "���� ����" << endl;
				system("pause");
			}

			else
			{
				cout << "�κ��丮�� ���� á���ϴ�." << endl;
				system("pause");
			}
		}

		else
		{
			cout << "�߸��� �Է�" << endl;
			system("pause");
		}
	}
}

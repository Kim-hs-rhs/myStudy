#include "pch.h"
#include "Inven.h"

Inven::Inven() : m_pPlayerI(nullptr), m_InvenSize(5)
{
	for(int i = 0; i < 3; ++i)
	{
		m_vecInven[i].reserve(m_InvenSize);
	}
}

Inven::~Inven()
{
}

void Inven::Initialize()
{
}

void Inven::Update()
{
	char szSelect[32] = " ";
	const char szReturn[32] = "������";
	// ������ ��� ������ ����//
	int iData(0), iSrc(0);

	while (true)
	{
		system("cls");
		Render();

		dynamic_cast<Player*>(m_pPlayerI)->Render_Equip();

		cout << "����(���)�� ������ �̸� �Է�(������ �Է� �� ���ư�) : ";
		cin >> szSelect;
		
		if (!strcmp(szReturn, szSelect))
			return;

		for (int i = 0; i < IT_MISC; ++i)
		{
			for (vector<Base*>::iterator iter = m_vecInven[i].begin()
				; iter != m_vecInven[i].end(); ++iter)
			{
				if (!strcmp(szSelect, (*iter)->Get_Info().szName))
				{
					if (dynamic_cast<Player*>(m_pPlayerI)->Equip((*iter), (ITEMINDEX)i))
					{
						dynamic_cast<Player*>(m_pPlayerI)->Set_Attack(-iData);
						dynamic_cast<Player*>(m_pPlayerI)->Set_Armor(-iSrc);
					}

					cout << (*iter)->Get_Info().szName << " ���� �Ϸ�" << endl;
					dynamic_cast<Player*>(m_pPlayerI)->Set_Attack((*iter)->Get_Info().iAttack);
					dynamic_cast<Player*>(m_pPlayerI)->Set_Armor((*iter)->Get_Info().iArmor);
					system("pause");

					//������ ����� ������ ����//
					iData = (*iter)->Get_Info().iAttack;
					iSrc = (*iter)->Get_Info().iArmor;
				}
			}
		}
		
		for (vector<Base*>::iterator iter = m_vecInven[IT_MISC].begin()
			; iter != m_vecInven[IT_MISC].end(); ++iter)
		{
			if (!strcmp(szSelect, (*iter)->Get_Info().szName))
			{
				cout << (*iter)->Get_Info().szName << " ��� �Ϸ�" << endl;
				dynamic_cast<Player*>(m_pPlayerI)->Set_Hp((*iter)->Get_Info().iHp);
				system("pause");
			}
		}
	}
}

bool Inven::Result_Buy(ITEMINDEX eType, Base* pItem)
{
	if (m_InvenSize <= m_vecInven[eType].size())
	{
		return false;
	}

	m_vecInven[eType].push_back(pItem);

	return true;
}

void Inven::Release()
{
	for (int i = 0; i < IT_END; ++i)
	{
		for_each(m_vecInven[i].begin(), m_vecInven[i].end(), Safe_Delete<Base*>);
		m_vecInven[i].clear();
	}
}

void Inven::Render()
{
	for (int i = 0; i < IT_END; ++i)
	{
		if (IT_WEAPON == i)
		{
			cout << "<1. ���� ���>" << endl;
		}

		else if (IT_ARMOR == i)
		{
			cout << "<2. �� ���>" << endl;
		}

		else
		{
			cout << "<3. ��ȭ ���>" << endl;
		}

		for (size_t j = 0; j < m_vecInven[i].size(); ++j)
		{
			m_vecInven[i][j]->Render();
		}

		cout << endl;
	}
}

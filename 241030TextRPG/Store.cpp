#include "pch.h"
#include "Store.h"

Store::Store() : m_CopyPlayerS(nullptr), m_pWeapon(nullptr), m_pArmor(nullptr)
{

}

Store::~Store()
{
	Release();
}

void Store::Initialize()
{
	if (!m_pWeapon)
	{
		m_pWeapon = new Weapon;
	}
	
	if (!m_pArmor)
	{
		m_pArmor = new Armor;
	}
}

void Store::Update()
{
	int iInput(0);
	
	while (true)
	{
		system("cls");

		m_CopyPlayerS->Render();

		cout << "1. ���� 2. ��ȭ 3. ������ : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Initialize();
			Select_Buy();
			break;

		case 2:
			Select_Enforce();
			break;

		case 3:
			if (!m_pWeapon)
			{
				SAFE_DELETE(m_pWeapon);
			}

			if (!m_pArmor)
			{
				SAFE_DELETE(m_pArmor);
			}
			return;

		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			system("pause");
			continue;
		}
	}
}

void Store::Release()
{
	SAFE_DELETE(m_pWeapon);
	SAFE_DELETE(m_pArmor);
}

void Store::Select_Buy()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		m_CopyPlayerS->Render();

		cout << "1. ���� 2. �� 3. ���� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pWeapon->Initialize();
			Buy_Weapon();
			break;

		case 2:
			m_pArmor->Initialize();
			Buy_Armor();
			break;

		case 3:
			return;

		default:
			cout << "�߸��� �Է�" << endl;
			system("pause");
			continue;
		}
	}
	

}

void Store::Select_Enforce()
{
	int iSelect(0);

	
}

void Store::Buy_Weapon()
{
	int iSelect(0);

	while (true)
	{
		system("cls");

		m_CopyPlayerS->Render();
		m_pWeapon->Render();

		if (0 >= m_CopyPlayerS->Get_Gold())
		{
			cout << "���� �ϳ��� ���׿�" << endl;
			system("pause");
			return;
		}

		cout << "������ ���� ����" << endl;
		cout << "1. " << m_pWeapon->Get_Name(1) << '\t' << " 2. " << m_pWeapon->Get_Name(2) << '\t' << " 3. " << m_pWeapon->Get_Name(3) << '\t' << "4. ���ư��� : ";
		cin >> iSelect;

		if (4 == iSelect)
		{
			return;
		}

		else if ((1 <= iSelect) && (4 > iSelect))
		{
			if (m_pWeapon->Get_Price(iSelect) <= m_CopyPlayerS->Get_Gold())
			{
				cout << "���� �Ϸ�" << endl;
				m_CopyPlayerS->Minus_Gold(m_pWeapon->Get_Price(iSelect));
				m_CopyPlayerS->Add_Attack(m_pWeapon->Get_Attack(iSelect));
				system("pause");
			}

			else
			{
				cout << "���� �����մϴ�." << endl;
				system("pause");
				continue;
			}
		}

		else
		{
			cout << "�߸��� �Է�" << endl;
			system("pause");
			continue;
		}
	}
}

void Store::Buy_Armor()
{
	int iSelect(0);

	while (true)
	{
		system("cls");

		m_CopyPlayerS->Render();
		m_pArmor->Render();

		if (0 >= m_CopyPlayerS->Get_Gold())
		{
			cout << "���� ������ ���ư��ϴ�." << endl;
			system("pause");
			return;
		}

		cout << "������ ���� ����" << endl;
		cout << "1. " << m_pArmor->Get_Name() << '\t' << "2. ���ư��� : ";
		cin >> iSelect;

		if (2 == iSelect)
		{
			return;
		}

		if (1 == iSelect)
		{
			if (m_pArmor->Get_Price() <= m_CopyPlayerS->Get_Gold())
			{
				cout << "���� �Ϸ�" << endl;
				m_CopyPlayerS->Minus_Gold(m_pArmor->Get_Price());
				m_CopyPlayerS->Add_Shield(m_pArmor->Get_Shield());
				system("pause");
			}

			else
			{
				cout << "���� �����մϴ�." << endl;
				system("pause");
				continue;
			}
		}
	}
}
#include "pch.h"
#include "Player.h"

Player::Player()
{
	memset(&m_tInfo, 0, sizeof(INFO));
}

Player::~Player()
{

}

Player::Player(const Player& rhs)
{
	
}

void Player::Initialize()
{
	int iInput(0);
	bool bSelect(false);

	while (!bSelect)
	{
		system("cls");

		cout << "������ �����ϼ���(1. ���� 2. ���� 3. ������ 4. ���� 5. �û�) : ";
		cin >> iInput;

		switch (iInput)
		{
		case Player::WORRIOR:
			Set_Job("����");
			Set_Attack(10);
			Set_Hp(100);
			Set_Shield(0);
			Set_Gold(1000);
			bSelect = true;
			break;

		case Player::THIEF:
			Set_Job("����");
			Set_Attack(10);
			Set_Hp(100);
			Set_Shield(0);
			Set_Gold(1000);
			bSelect = true;
			break;

		case Player::MAGE:
			Set_Job("������");
			Set_Attack(10);
			Set_Hp(100);
			Set_Shield(0);
			Set_Gold(1000);
			bSelect = true;
			break;

		case Player::MONK:
			Set_Job("����");
			Set_Attack(10);
			Set_Hp(100);
			Set_Shield(0);
			Set_Gold(1000);
			bSelect = true;
			break;

		case Player::ARCHER:
			Set_Job("�û�");
			Set_Attack(10);
			Set_Hp(100);
			Set_Shield(0);
			Set_Gold(1000);
			bSelect = true;
			break;

		default:
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			system("pause");
		}
	}
}

void Player::Update()
{

}

void Player::Release()
{

}

void Player::Render()
{
	Draw_Line();
	cout << "�̸� : " << m_tInfo.szName << endl;
	cout << "ü�� : " << m_tInfo.iHp << '\t' << "���ݷ� : " << m_tInfo.iAttack << '\t' << "���� : " << m_tInfo.iShield << '\t' << "��� : " << m_tInfo.iGold << endl;
}

void Player::Draw_Line()
{
	cout << "============================================================" << endl;
}

void Player::Victory()
{
	++iVictory;
	cout << "�������� �¸��� Ƚ�� : " << iVictory << endl;
}

void Player::Death()
{
	cout << "����Ͽ� �������� ��� �Ҿ����ϴ�." << endl;
	
	Set_Attack(10);
	Set_Hp(100);
	Set_Shield(0);
	Set_Gold(0);
}



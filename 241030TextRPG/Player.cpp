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

		cout << "직업을 선택하세요(1. 전사 2. 도적 3. 마법사 4. 도사 5. 궁사) : ";
		cin >> iInput;

		switch (iInput)
		{
		case Player::WORRIOR:
			Set_Job("전사");
			Set_Attack(10);
			Set_Hp(100);
			Set_Shield(0);
			Set_Gold(1000);
			bSelect = true;
			break;

		case Player::THIEF:
			Set_Job("도적");
			Set_Attack(10);
			Set_Hp(100);
			Set_Shield(0);
			Set_Gold(1000);
			bSelect = true;
			break;

		case Player::MAGE:
			Set_Job("마법사");
			Set_Attack(10);
			Set_Hp(100);
			Set_Shield(0);
			Set_Gold(1000);
			bSelect = true;
			break;

		case Player::MONK:
			Set_Job("도사");
			Set_Attack(10);
			Set_Hp(100);
			Set_Shield(0);
			Set_Gold(1000);
			bSelect = true;
			break;

		case Player::ARCHER:
			Set_Job("궁사");
			Set_Attack(10);
			Set_Hp(100);
			Set_Shield(0);
			Set_Gold(1000);
			bSelect = true;
			break;

		default:
			cout << "잘못 입력하셨습니다." << endl;
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
	cout << "이름 : " << m_tInfo.szName << endl;
	cout << "체력 : " << m_tInfo.iHp << '\t' << "공격력 : " << m_tInfo.iAttack << '\t' << "방어력 : " << m_tInfo.iShield << '\t' << "골드 : " << m_tInfo.iGold << endl;
}

void Player::Draw_Line()
{
	cout << "============================================================" << endl;
}

void Player::Victory()
{
	++iVictory;
	cout << "전투에서 승리한 횟수 : " << iVictory << endl;
}

void Player::Death()
{
	cout << "사망하여 아이템을 모두 잃었습니다." << endl;
	
	Set_Attack(10);
	Set_Hp(100);
	Set_Shield(0);
	Set_Gold(0);
}



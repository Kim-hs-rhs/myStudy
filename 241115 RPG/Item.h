#pragma once
#include "Base.h"
#include "MainGame.h"

class Item final : public Base
{
public:
	Item();
	Item(const char* pName, int _iHp, int _iAttack, int _iArmor, int _iGold);
	~Item();

public:
	virtual void Render()override;

public:
	void Initialize();
	void Update();
	void Release();
};


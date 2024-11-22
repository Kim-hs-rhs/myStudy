#pragma once
#include "Base.h"
#include "MainGame.h"

class Monster final : public Base
{
public:
	Monster();
	virtual ~Monster();

public:
	virtual void Render()override;
	void Set_Monster(MONSTERINDEX eType);

public:
	void Initialize();
	void Update();
	void Release();
};


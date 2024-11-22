#pragma once
#include "Player.h"
#include "Field.h"
#include "Store.h"
#include "Inven.h"

class Store;
class Field;

class MainGame
{
public:
	MainGame();
	~MainGame();

public:
	bool Initialize();
	void Update();
	void Release();

public:
	static void Draw_Line() { cout << "===============================================" << endl; }

private:
	Base*	m_pPlayer;
	Field*	m_pField;
	Store*	m_pStore;
	Inven*	m_pInven;
};


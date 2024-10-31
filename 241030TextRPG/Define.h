#pragma once

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; }

typedef struct tagCinfo
{
	char szName[32];
	int iHp, iAttack, iShield;
	int iGold;
}INFO;

typedef struct tagWinfo
{
	char szName[32];
	int iAttack;
	int iPrice;
}WINFO;

typedef struct tagAinfo
{
	char szName[32];
	int iShield;
	int iPrice;
}AINFO;

typedef struct tagMinfo
{
	char szName[32];
	char szEffect[128];
}MINFO;
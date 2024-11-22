#include "pch.h"
#include "MainGame.h"

int main()
{
    MainGame    MainGame;

    if (MainGame.Initialize())
    {
        MainGame.Update();
    }
       
    return 0;
}

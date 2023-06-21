#include <iostream>
#include "Gamelogic.h"
#include "core.h"
#include "console.h"
using namespace std;

void Update(char _cMap[VERTICLE][HORIZON], PPLAYER _pPlayer, std::vector<Landmine> vecland)
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		
	}
}

void Render(char _cMap[VERTICLE][HORIZON], PPLAYER _pPlayer, std::vector<Landmine> vecland)
{

	for(int i = 0; i < VERTICLE; i++)
	{
		for(int j = 0; j < HORIZON; j++)
		{
			if (_pPlayer->tpos.x == j && _pPlayer->tpos.y == i)
			{
				Setcolor(7, 3);
				cout << "¡×";
				Setcolor(7, 0);
			}
		}
	}

	Gotoxy(0, 12);
	for (int i = 0; i < 3; i++)
		cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á" << endl;
}

void obstacle(char _cMap[VERTICLE][HORIZON], PPLAYER _pPlayer, std::vector<Landmine> vecland)
{
	if (_pPlayer->pBulletCount > 1)
		return;
}

void move(PPLAYER _pPlayer, int jump)
{
    static int foot = 0;

    if (jump == 0)
        _pPlayer->tpos.y = 0;
    else if (jump == 2)
        _pPlayer->tpos.y--;
    else _pPlayer->tpos.y++;

    Gotoxy(_pPlayer->tpos.x, 15 - _pPlayer->tpos.y);cout << "                 ";
    Gotoxy(_pPlayer->tpos.x, 16 - _pPlayer->tpos.y);cout << "         ¡á¡á¡á¡á¡á¡á¡á¡á";
    Gotoxy(_pPlayer->tpos.x, 17 - _pPlayer->tpos.y);cout << "         ¡á¡á¡á¡á¡á¡á¡á¡á";
    Gotoxy(_pPlayer->tpos.x, 18 - _pPlayer->tpos.y);cout << "         ¡á¡á¡á¡á¡á¡á¡á¡á";
    Gotoxy(_pPlayer->tpos.x, 19 - _pPlayer->tpos.y);cout << " ¡á      ¡á¡á¡á¡á¡á¡á¡á¡á ";
    Gotoxy(_pPlayer->tpos.x, 20 - _pPlayer->tpos.y);cout << " ¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á ";
    Gotoxy(_pPlayer->tpos.x, 21 - _pPlayer->tpos.y);cout << " ¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á  ¡á ";
    Gotoxy(_pPlayer->tpos.x, 22 - _pPlayer->tpos.y);cout << "   ¡á¡á¡á¡á¡á¡á¡á¡á¡á     ";
    Gotoxy(_pPlayer->tpos.x, 23 - _pPlayer->tpos.y);

    if (jump == 1 || jump == 2) {
        cout << "    ¡á¡á¡á ¡á¡á       ";
        Gotoxy(2, 24 - _pPlayer->tpos.y);
        cout << "    ¡á¡á   ¡á¡á      ";
    }
    else if (foot == 0) {
        cout << "    ¡á¡á¡á¡á  ¡á¡á¡á    ";
        Gotoxy(2, 24 - _pPlayer->tpos.y);
        cout << "      ¡á¡á         ";
        foot = !foot;
    }
    else if (foot == 1) {
        cout << "     ¡á¡á¡á ¡á¡á      ";
        Gotoxy(2, 24 - _pPlayer->tpos.y);
        cout << "          ¡á¡á     ";
        foot = !foot;
    }

    Gotoxy(2, 25 - _pPlayer->tpos.y);
    if (jump == 0) {
        cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á";
    }
    else {
        cout << "                ";
    }
    Sleep(_pPlayer->speed);
}

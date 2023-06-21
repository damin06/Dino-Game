#include <iostream>
#include<Windows.h>
#include "startsceen.h"
#include "console.h"
#include "Gamelogic.h"
using namespace std;

int main()
{
	char map[VERTICLE][HORIZON] = {};
	PLAYER _player;
	vector<Landmine> _land;
	_player.tpos.x = 2;
	_player.tpos.y = 0;

	while (true)
	{
		system("cls");
		GameTiltle();

		int iMenu = MenuDraw();
		if(iMenu == 0)
		{
			break;
		}
		else if(iMenu == 1)
		{
			Info();
		}
		else if(iMenu == 2)
		{
			cout << "게임을 종료합니다." << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << '\r' << 3 - i << "...";
				Sleep(1000);
			}
			return 0;
		}
		Sleep(1000);
	}

	system("cls");
	while (true)
	{
		Render(map, &_player, _land);
	}
}
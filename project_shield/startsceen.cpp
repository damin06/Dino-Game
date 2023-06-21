#include "startsceen.h"
#include "console.h"
#include <iostream>
#include <Windows.h>
#include<conio.h>
#include <fcntl.h>
#include <io.h>
using namespace std;

void GameTiltle()
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	//wcout << L"	  ________	 __                                 __        __            __        __	" << endl;
	//wcout << L"	 /        |	/  |                               /  |      /  |          /  |      /  |	" << endl;
	//wcout << L"	 $$$$$$$$ /	$$ |____    ______		   _______ $$ |____  $$/   ______  $$ |  ____$$ |	" << endl;
	//wcout << L"	    $$ |	$$      \  /	  \	      /       |$$      \ /  | /      \ $$ | /    $$ |	" << endl;
	//wcout << L"	    $$ |	$$$$$$$  |/$$$$$$  |	 /$$$$$$$/ $$$$$$$  |$$ |/$$$$$$  |$$ |/$$$$$$$ |	" << endl;
	//wcout << L"	    $$ |	$$ |  $$ |$$    $$ |	 $$      \ $$ |  $$ |$$ |$$    $$ |$$ |$$ |  $$ |	" << endl;
	//wcout << L"	    $$ |	$$ |  $$ |$$$$$$$$/	      $$$$$$  |$$ |  $$ |$$ |$$$$$$$$/ $$ |$$ \__$$ |	" << endl;
	//wcout << L"	    $$ |	$$ |  $$ |$$       |	 /     $$/ $$ |  $$ |$$ |$$       |$$ |$$    $$ |	" << endl;
	//wcout << L"	    $$ /	$$ /  $$/  $$$$$$$/	      $$$$$$$/  $$/   $$/ $$/  $$$$$$$/ $$/  $$$$$$$/	" << endl;


	Gotoxy(17,5);
wcout << L" .---. .-. .-..----.    .----..-. .-..-..----..-.   .----.  " << endl;
Gotoxy(17, 6);

wcout << L"{_   _}| {_} || {_     { {__  | {_} || || {_  | |   | {}  \ " << endl;
Gotoxy(17, 7);

wcout << L"  | |  | { } || {__    .-._} }| { } || || {__ | `--.|     / " << endl;
Gotoxy(17, 8);

wcout << L"  `-'  `-' `-'`----'   `----' `-' `-'`-'`----'`----'`----'  " << endl;

	int curmode = _setmode(_fileno(stdout), prevmode);




}

int KeyController()
{
	//if (GetAsyncKeyState(VK_UP) & 0x8000)
	//	return (int)KEY::UP;
	//if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	//	return (int)KEY::DOWN;
	//if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	//	return (int)KEY::SPACEBAR;
	int iCk = _getch();
	if(iCk == 224)
	{
		iCk = _getch();
		switch (iCk)
		{
		case 72:
			return (int)KEY::UP;
			break;
		case 80:
			return (int)KEY::DOWN;
			break;
		}
	}
	else if(iCk == 32)
	{
		return (int)KEY::SPACEBAR;
	}
	

	Sleep(200);
	return -1;
}

void Info()
{
	while (true)
	{
		system("cls");
		Setcolor(0, 6);
		cout << "[조작법]" << endl << endl;;
		cout << "스페이스바 점프" << endl;
		cout << "엔터 총 발사" << endl << endl;

		Setcolor(0, 7);
		cout << "스페이스바를 눌러 로비로....";
		if (KeyController() == (int)KEY::SPACEBAR)
		{
		Setcolor(7, 0);
			break;
		}
	}
}

int MenuDraw()
{
	int x = 30;
	int y = 12;

	Gotoxy(x, y);
	cout << "게임 시작";
	Gotoxy(x, y + 1);
	cout << "게임 정보";
	Gotoxy(x, y + 2);
	cout << "종료 하기";

	
	int iCk = _getch();
	while (true)
	{
		int iKey = KeyController();
		switch (iKey)
		{
		case (int)KEY::UP:
		{
			if (y > 12) // y는 13~14만 가능.
			{
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, --y);
				cout << ">";
			}
		}
		break;
		case (int)KEY::DOWN:
		{
			if (y < 14) // y는 13~14만 가능.
			{
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, ++y);
				cout << ">";
			}

		}
		break;
		case (int)KEY::SPACEBAR:
		{
			return y - 12;
		}
		break;
		default:
			break;
		}
	}
	Sleep(200);
	return -1;
}

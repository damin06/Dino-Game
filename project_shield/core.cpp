#include "core.h"
using namespace std;

void GotoXY(int x, int y)
{
	COORD Cur = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

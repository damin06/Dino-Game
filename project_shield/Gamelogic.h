#pragma once
#include <vector>

const int HORIZON = 100;
const int VERTICLE = 30;

typedef struct _tagpos
{
	int x;
	int y;
}POS, * POSS;

typedef struct _tagplayer
{
	POS tpos;
	POS tNewpos;
	int life;
	int pBulletCount;
	int obstacleCount;
	int speed;
} PLAYER, * PPLAYER;

typedef struct _landmine
{
	POS tpos;
	POS tNewpos;
} Landmine, * LLandmine;

void Update(char _cMap[VERTICLE][HORIZON], PPLAYER _pPlayer, std::vector<Landmine> vecland);
void Render(char _cMap[VERTICLE][HORIZON], PPLAYER _pPlayer, std::vector<Landmine> vecland);
void obstacle(char _cMap[VERTICLE][HORIZON], PPLAYER _pPlayer, std::vector<Landmine> vecland);
void move(PPLAYER _pPlayer, int jump = 0);
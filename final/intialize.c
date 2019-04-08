#include "monster.h"


void initializeMonster(int x, int y)
{

    if (jeu.nombreMonstres < MONSTRES_MAX )
	{

        monster[jeu.nombreMonstres].sprite = loadImage("graphics/monster1.png");

        monster[jeu.nombreMonstres].direction = LEFT;

        monster[jeu.nombreMonstres].frameNumber = 0;
        monster[jeu.nombreMonstres].frameTimer = TIME_BETWEEN_2_FRAMES;

        monster[jeu.nombreMonstres].x = x;
        monster[jeu.nombreMonstres].y = y;

        monster[jeu.nombreMonstres].w = TILE_SIZE;
        monster[jeu.nombreMonstres].h = TILE_SIZE;

        monster[jeu.nombreMonstres].timerMort = 0;
        monster[jeu.nombreMonstres].onGround = 0;

        jeu.nombreMonstres++;

	}

}




#include "defs.h"



typedef struct Input
{
	int left, right, up, down, jump, attack, enter, erase, pause;
} Input;



typedef struct Gestion
{

    SDL_Surface *screen;
    int nombreMonstres;

} Gestion;



typedef struct Map
{

	SDL_Surface *background, *tileSet;

	int startX, startY;

	int maxX, maxY;


	int tile[MAX_MAP_Y][MAX_MAP_X];

} Map;




typedef struct GameObject
{

	SDL_Surface *sprite;

	int x, y;

	int h, w;


	int frameNumber, frameTimer;
	int etat, direction;


	int onGround, timerMort;
	float dirX, dirY;
	int saveX, saveY;


	int jump;



} GameObject;



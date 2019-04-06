
#include "player.h"


void initializePlayer(void)
{
    player.sprite = loadImage("graphics/walkright.png");

    player.direction = RIGHT;
    player.etat = WALK;

    player.frameNumber = 0;
    player.frameTimer = TIME_BETWEEN_2_FRAMES;

    player.x = 20;
    player.y = 304;

}


void drawplayer()
{
	SDL_Rect dest;

	dest.x = player.x - map.startX;
	dest.y = player.y - map.startY;
	dest.w = PLAYER_WIDTH;
	dest.h = PLAYER_HEIGTH;

	/* Rectangle source à blitter */
	SDL_Rect src;

	src.x = player.frameNumber * PLAYER_WIDTH;
	src.y = 0;
	src.w = PLAYER_WIDTH;
	src.h = PLAYER_HEIGTH;


	SDL_BlitSurface(player.sprite, &src, jeu.screen, &dest);

}


void updatePlayer(void)
{

 	if (input.left == 1)
	{
		player.x -= PLAYER_SPEED;

		if (player.x < 0)
		{
			player.x = 0;
		}

		if(player.direction == RIGHT)
		{
		    player.direction = LEFT;
		    player.sprite = loadImage("graphics/walkleft.png");
		}
	}

	else if (input.right == 1)
	{
		player.x += PLAYER_SPEED;

		if (player.x + PLAYER_WIDTH >= map.maxX)
		{
			player.x = map.maxX - PLAYER_WIDTH;;
		}

		if(player.direction == LEFT)
		{
		    player.direction =  RIGHT;
		    player.sprite = loadImage("graphics/walkright.png");
		}

    }

    centerScrollingOnPlayer();

}


void centerScrollingOnPlayer(void)
{
	//On définit les coordonnées du début de l'affichage de la map par rapport à celles
	//du joueur.
	//Pour centrer le joueur, la map doit donc s'afficher à un demi-écran avant la position
	//du joueur.
	//Puis on "clamp" (limite) l'affichage de l'écran pour ne pas sortir de la map.
	map.startX = player.x - (SCREEN_WIDTH / 2);

	if (map.startX < 0)
	{
		map.startX = 0;
	}

	else if (map.startX + SCREEN_WIDTH >= map.maxX)
	{
		map.startX = map.maxX - SCREEN_WIDTH;
	}

	map.startY = player.y - (SCREEN_HEIGHT / 2);

	if (map.startY < 0)
	{
		map.startY = 0;
	}

	else if (map.startY + SCREEN_HEIGHT >= map.maxY)
	{
		map.startY = map.maxY - SCREEN_HEIGHT;
	}
}





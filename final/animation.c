
#include "animation.h"


void drawAnimatedEntity(GameObject *entity)
{

    if (entity->frameTimer <= 0)
    {
 
        entity->frameTimer = TIME_BETWEEN_2_FRAMES;

        entity->frameNumber++;

        if(entity->frameNumber >= entity->sprite->w / entity->w)
            entity->frameNumber = 0;

    }

    else
        entity->frameTimer--;


 
	SDL_Rect dest;


	dest.x = entity->x - map.startX;
	dest.y = entity->y - map.startY;
	dest.w = entity->w;
	dest.h = entity->h;

	SDL_Rect src;


	src.x = entity->frameNumber * entity->w;
	src.y = 0;
	src.w = entity->w;
	src.h = entity->h;



	SDL_BlitSurface(entity->sprite, &src, jeu.screen, &dest);



}



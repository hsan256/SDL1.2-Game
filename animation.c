
#include "animation.h"


void drawanimatedplayer(void)
{
    if (player.frameTimer <= 0)
    {
        player.frameTimer = TIME_BETWEEN_2_FRAMES;

        player.frameNumber++;

        if(player.frameNumber >= player.sprite->w / PLAYER_WIDTH - 1)
            player.frameNumber = 0;

    }
    else
        player.frameTimer--;

    drawplayer();

}



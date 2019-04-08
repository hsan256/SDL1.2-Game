
#include "monster.h"
#include "init.h"

void updateMonsters(void)
{

    int i;

    for ( i = 0; i < jeu.nombreMonstres; i++ )
    {

        if (monster[i].timerMort == 0)
        {

            monster[i].dirX = 0;
            monster[i].dirY += GRAVITY_SPEED;


            if (monster[i].dirY >= MAX_FALL_SPEED)
                monster[i].dirY = MAX_FALL_SPEED;

            if (monster[i].x == monster[i].saveX || checkFall(monster[i]) == 1 )
            {
                if (monster[i].direction == LEFT)
                {
                    monster[i].direction = RIGHT;
                    monster[i].sprite = loadImage("graphics/monster1right.png");
                }
                else
                {
                    monster[i].direction = LEFT;
                    monster[i].sprite = loadImage("graphics/monster1.png");
                }

            }


            if(monster[i].direction == LEFT)
                monster[i].dirX -= 2;
            else
                monster[i].dirX += 2;

            monster[i].saveX = monster[i].x;

            mapCollision(&monster[i]);


            if (collide(&player, &monster[i]) == 1)
            {

                player.timerMort = 1;
            }
            else if (collide(&player, &monster[i]) == 2)
            {
                monster[i].timerMort = 1;
            }




          }

        if (monster[i].timerMort > 0)
        {
            monster[i].timerMort--;
 
            if (monster[i].timerMort == 0)
            {
                monster[i] = monster[jeu.nombreMonstres-1];
                jeu.nombreMonstres--;
            }
        }

    }


}




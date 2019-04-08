#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enig.h"
#include <time.h>

int main()
{

	SDL_Surface *screen;
	enigme  e;
	int s,r,run =1,running=1,alea;
	char image[30]="";
	SDL_Event event;
    srand(time(NULL));


	 SDL_Init ( SDL_INIT_VIDEO ) ;



	 screen=SDL_SetVideoMode(1024,630,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF );
	 init_enigme(&e);

	 while (run)
	 {
	    running=1,r=0 ;
	     SDL_PollEvent(&event);
           switch(event.type)
            {
              case SDL_QUIT:
                run = 0;
			  break ;
            }

      generate_afficher ( screen  , image ,&e,&alea) ;


      s=solution_e (image );
			do{
			r=resolution (&running,&run);
			}while((r>3 || r<1) && running!=0) ;


      while(running){

				afficher_resultat (screen,s,r,&e) ;
			       SDL_WaitEvent(&event);
                     switch(event.type)
                       {
					     case SDL_QUIT :
                              running =0 ;
						      run=0 ;
					     break ;
                         case SDL_KEYDOWN :

                             switch( event.key.keysym.sym )
                                  {
			                        case  SDLK_ESCAPE:
			                           running= 0 ;
			                        break ;
			                      }
						 break ;
                       }
                    }
   }
      SDL_FreeSurface(screen);
      SDL_Quit();
	return 0;
}


#include "structs.h"

extern GameObject monster[];
extern Gestion jeu;
extern GameObject player;
extern Map map;


extern SDL_Surface *loadImage(char *name);
extern void mapCollision(GameObject *entity);
extern int collide(GameObject *player, GameObject *monster);
extern int checkFall(GameObject monster);


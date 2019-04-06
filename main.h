#include "structs.h"

void init(char *);
void cleanup(void);
void getInput(void);
void draw(void);
void loadGame(void);
void delay(unsigned int frameLimit);
void updatePlayer(void);
void initializePlayer(void);


Input input;
Gestion jeu;
Map map;
Hero player;


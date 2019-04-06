
#include "map.h"



void loadMap(char *name)
{
	int x, y;
	FILE *fp;

	fp = fopen(name, "rb");


	if (fp == NULL)
	{
		printf("Failed to open map %s\n", name);

		exit(1);
	}


	map.maxX = map.maxY = 0;

	for (y=0;y<MAX_MAP_Y;y++)
	{
		for (x=0;x<MAX_MAP_X;x++)
		{
			fscanf(fp, "%d", &map.tile[y][x]);

			if (map.tile[y][x] > 0)
			{
				if (x > map.maxX)
				{
					map.maxX = x;
				}

				if (y > map.maxY)
				{
					map.maxY = y;
				}
			}
		}
	}


	map.maxX = (map.maxX + 1) * TILE_SIZE;
	map.maxY = (map.maxY + 1) * TILE_SIZE;


	map.startX = map.startY = 0;


	fclose(fp);

}




void drawMap(void)
{
	int x, y, mapX, x1, x2, mapY, y1, y2, xsource, ysource, a;


	mapX = map.startX / TILE_SIZE;


	x1 = (map.startX % TILE_SIZE) * -1;


	x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);

	mapY = map.startY / TILE_SIZE;
	y1 = (map.startY % TILE_SIZE) * -1;
	y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE);


	for (y = y1; y < y2; y += TILE_SIZE)
	{

		mapX = map.startX / TILE_SIZE;


		for (x = x1; x < x2; x += TILE_SIZE)
		{


            a = map.tile[mapY][mapX];

            ysource = a / 10 * TILE_SIZE;
            xsource = a % 10 * TILE_SIZE;

		    drawTile(map.tileSet, x, y, xsource, ysource);

            mapX++;
		}

		mapY++;
	}
}


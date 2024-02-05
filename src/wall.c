/*
 * Implementation for Wall type
 * Lien Zhu
 */


#include "wall.h"


void update_wall(Wall *wall)
{
}

void draw_wall(Wall wall)
{
    DrawLineEx(wall.start, wall.end, wall.thiccness, wall.color);
}

/*
 * Declaration for Wall type
 * Lien Zhu
 */


#ifndef WALL_H
#define WALL_H


#include <raylib.h>
#include "global.h"


typedef struct Wall {
    Vector2 start;
    Vector2 end;
    float thiccness;
    Color color;
} Wall;

void update_wall(Wall *wall);
void draw_wall(Wall wall);
void draw_guides(void);


#endif // !WALL_H

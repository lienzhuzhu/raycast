/*
 * Declaration for Wall type
 * Lien Zhu
 */


#ifndef WALL_H
#define WALL_H


#include <raylib.h>


typedef struct Wall {
    Rectangle body;
} Wall;

void update_wall(Wall *wall);
void draw_wall(Wall wall);


#endif // !WALL_H

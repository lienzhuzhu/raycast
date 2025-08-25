/*
 * Some helpful constants
 * Lien Zhu
 */


#ifndef GLOBAL_H
#define GLOBAL_H


#include <raylib.h>


#define SCREEN_WIDTH        800
#define SCREEN_HEIGHT       800

#define MIN_FPS             10.f
#define TARGET_FPS          240.f

#define SCREEN_CENTER_X     GetScreenWidth()/2.f
#define SCREEN_CENTER_Y     GetScreenHeight()/2.f

#define NUM_WORLD_WALLS     4

Vector2 get_crosshair(void);
void draw_crosshair(Vector2);


#endif // !GLOBAL_H

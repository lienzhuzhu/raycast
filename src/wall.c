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

void draw_guides(void)
{
    Vector2 points[4] = {
        {SCREEN_CENTER_X - SCREEN_CENTER_X / 2.f, SCREEN_CENTER_Y - SCREEN_CENTER_Y / 2.f},
        {SCREEN_CENTER_X + SCREEN_CENTER_X / 2.f, SCREEN_CENTER_Y - SCREEN_CENTER_Y / 2.f},
        {SCREEN_CENTER_X - SCREEN_CENTER_X / 2.f, SCREEN_CENTER_Y + SCREEN_CENTER_Y / 2.f},
        {SCREEN_CENTER_X + SCREEN_CENTER_X / 2.f, SCREEN_CENTER_Y + SCREEN_CENTER_Y / 2.f},
    };

    Wall top = {
        .start = points[0],
        .end = points[1],
        .thiccness = 4.f,
        .color = LIGHTGRAY
    };

    Wall left = {
        .start = points[0],
        .end = points[2],
        .thiccness = 4.f,
        .color = LIGHTGRAY
    };

    Wall right = {
        .start = points[1],
        .end = points[3],
        .thiccness = 4.f,
        .color = LIGHTGRAY
    };

    Wall bottom = {
        .start = points[2],
        .end = points[3],
        .thiccness = 4.f,
        .color = LIGHTGRAY
    };

    draw_wall(top);
    draw_wall(left);
    draw_wall(right);
    draw_wall(bottom);
}

/*
 * Global functions implementations
 * Lien Zhu
 */


#include "global.h"
#include "raylib.h"


void draw_guides(void)
{
    Vector2 points[4] = {
        {SCREEN_CENTER_X - SCREEN_CENTER_X / 2.f, SCREEN_CENTER_Y - SCREEN_CENTER_Y / 2.f},
        {SCREEN_CENTER_X + SCREEN_CENTER_X / 2.f, SCREEN_CENTER_Y - SCREEN_CENTER_Y / 2.f},
        {SCREEN_CENTER_X - SCREEN_CENTER_X / 2.f, SCREEN_CENTER_Y + SCREEN_CENTER_Y / 2.f},
        {SCREEN_CENTER_X + SCREEN_CENTER_X / 2.f, SCREEN_CENTER_Y + SCREEN_CENTER_Y / 2.f},
    };

    DrawLineV(points[0], points[1], LIGHTGRAY);
    DrawLineV(points[0], points[2], LIGHTGRAY);
    DrawLineV(points[1], points[3], LIGHTGRAY);
    DrawLineV(points[2], points[3], LIGHTGRAY);
}

void draw_crosshair()
{
    Vector2 target = { GetMouseX(), GetMouseY() };
    DrawCircleV(target, 2.f, RED);
}

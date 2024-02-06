/*
 * Global functions implementations
 * Lien Zhu
 */


#include "global.h"


void draw_guides(void)
{
    Vector2 size = {10.f, 10.f};
    Vector2 topLeft = {10.f, 10.f};
    Vector2 topRight = {(GetScreenWidth()) - 20.f, 10.f};
    Vector2 bottomLeft = {10.f, (GetScreenHeight()) - 20.f};
    Vector2 bottomRight = {(GetScreenWidth()) - 20.f, (GetScreenHeight()) - 20.f};

    DrawRectangleV(topLeft, size, RED);
    DrawRectangleV(topRight, size, BLUE);
    DrawRectangleV(bottomLeft, size, BLUE);
    DrawRectangleV(bottomRight, size, RED);

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


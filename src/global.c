/*
 * Global functions implementations
 * Lien Zhu
 */


#include "global.h"
#include "raylib.h"


void draw_line(Line line, Color color)
{
    DrawLineV(line.start, line.end, color);
}

void draw_guides(void)
{
    Vector2 points[4] = {
        {SCREEN_CENTER_X - SCREEN_CENTER_X / 2.f, SCREEN_CENTER_Y - SCREEN_CENTER_Y / 2.f},
        {SCREEN_CENTER_X + SCREEN_CENTER_X / 2.f, SCREEN_CENTER_Y - SCREEN_CENTER_Y / 2.f},
        {SCREEN_CENTER_X - SCREEN_CENTER_X / 2.f, SCREEN_CENTER_Y + SCREEN_CENTER_Y / 2.f},
        {SCREEN_CENTER_X + SCREEN_CENTER_X / 2.f, SCREEN_CENTER_Y + SCREEN_CENTER_Y / 2.f},
    };

    Line top = {
        .start = points[0],
        .end = points[1]
    };

    Line left = {
        .start = points[0],
        .end = points[2]
    };

    Line right = {
        .start = points[1],
        .end = points[3]
    };

    Line bottom = {
        .start = points[2],
        .end = points[3]
    };

    draw_line(top, LIGHTGRAY);
    draw_line(left, LIGHTGRAY);
    draw_line(right, LIGHTGRAY);
    draw_line(bottom, LIGHTGRAY);
}

Vector2 get_crosshair()
{
    Vector2 crosshair = { GetMouseX(), GetMouseY() };
    return crosshair;
}

void draw_crosshair(Vector2 crosshair)
{
    DrawCircleV(crosshair, 2.f, RED);
}

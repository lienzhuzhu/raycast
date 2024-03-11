/*
 * Global functions implementations
 * Lien Zhu
 */


#include "global.h"
#include "raylib.h"


Vector2 get_crosshair()
{
    Vector2 crosshair = { GetMouseX(), GetMouseY() };
    return crosshair;
}

void draw_crosshair(Vector2 crosshair)
{
    DrawCircleV(crosshair, 2.f, RED);
}

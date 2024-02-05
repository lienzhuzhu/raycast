/*
 * Implementation for Laser type and functions.
 * Lien Zhu
 */


#include <raylib.h>
#include <raymath.h>

#include "laser.h"


void update_laser(Laser *laser, Vector2 position)
{
    laser->position = position;

    //Vector2 direction = {
    //    .x = GetMouseX() - laser->position.x,
    //    .y = GetMouseY() - laser->position.y
    //};
    Vector2 direction = {
        .x = GetMouseX(),
        .y = GetMouseY()
    };
    laser->direction = direction;
    //laser->direction = Vector2Normalize(direction);
}

void draw_laser(Laser laser)
{
    DrawLineV(laser.position, laser.direction, RAYWHITE);
}

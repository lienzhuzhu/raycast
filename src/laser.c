/*
 * Implementation for Laser type and functions.
 * Lien Zhu
 */


#include <raylib.h>
#include <raymath.h>
#include <stdio.h>

#include "laser.h"
#include "checks.h"
#include "global.h"


void update_laser(Laser *laser, Vector2 position)
{
    laser->position = position;

    Vector2 direction = {
        .x = GetMouseX() - laser->position.x,
        .y = GetMouseY() - laser->position.y
    };
    
    laser->direction = Vector2Normalize(direction);
}

void draw_laser(Laser laser, Wall wall)
{
    Vector2 end = {
        .x = laser.position.x + laser.direction.x,
        .y = laser.position.y + laser.direction.y
    };
    LaserCollision collision = get_collision_with_wall(&laser, &wall);

    if (collision.hit) {
        DrawLineV(laser.position, collision.point, RED);
        DrawCircleV(collision.point, 6.f, BLACK);
        printf("%f\n", collision.distance);
    } else {
        Vector2 crosshair = get_crosshair();
        DrawLineV(laser.position, crosshair, LIGHTGRAY);
        draw_crosshair(crosshair);
    }
}

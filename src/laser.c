/*
 * Implementation for Laser type and functions.
 * Lien Zhu
 */


#include <raylib.h>
#include <raymath.h>

#include "laser.h"
#include "checks.h"


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
        DrawCircleV(collision.point, 8.f, RED);
        DrawLineV(laser.position, collision.point, RED);
    } else {
        DrawLineV(laser.position, end, LIGHTGRAY);
    }
}

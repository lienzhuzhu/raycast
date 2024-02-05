/*
 * Collision checking functions
 * Lien Zhu
 */


#include "checks.h"


LaserCollision get_collision_with_wall(Laser *laser, Wall *wall)
{
    LaserCollision collision;

    double x1 = wall->start.x;
    double y1 = wall->start.y;
    double x2 = wall->end.x;
    double y2 = wall->end.y;

    double x3 = laser->position.x;
    double y3 = laser->position.y;
    double x4 = laser->position.x + laser->direction.x;
    double y4 = laser->position.y + laser->direction.y;

    double denom = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

    if (denom == 0) {
        collision.hit = false;
    } else {
        double t =  ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denom;
        double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denom;

        if (0 < t && t < 1 && 0 < u) {
            collision.hit = true;
            collision.point.x = x1 + t * (x2 - x1);
            collision.point.y = y1 + t * (y2 - y1);
        }
    }

    return collision;
}

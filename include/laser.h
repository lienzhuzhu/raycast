/*
 * Declaration for Laser type, which is basically a 2d raylib::Ray.
 * Lien Zhu
 */


#ifndef LASER_H
#define LASER_H


#include <raylib.h>
#include "wall.h"


typedef struct Laser {
    Vector2 position;
    Vector2 direction;
} Laser;

typedef struct LaserCollision {
    bool hit;
    float distance;
    Vector2 point;
    Vector2 normal;
} LaserCollision;

void update_laser(Laser *laser, Vector2 position);
void draw_laser(Laser laser, Wall *world);


#endif // !LASER_H

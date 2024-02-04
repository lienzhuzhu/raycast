/*
 * Declaration for collision checking functions.
 * Lien Zhu
 */


#ifndef CHECKS_H
#define CHECKS_H


#include <raylib.h>
#include "laser.h"
#include "wall.h"


LaserCollision get_collision_with_wall(Laser *laser, Wall *wall);


#endif // !CHECKS_H

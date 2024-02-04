/*
 * Declaration for Player type
 * Lien Zhu
 */


#ifndef PLAYER_H
#define PLAYER_H


#include <raylib.h>
#include "laser.h"


typedef struct Player {
    Laser *lasers;
    Vector2 position;
} Player;


#endif // !PLAYER_H

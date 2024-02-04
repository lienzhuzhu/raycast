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
    Vector2 velocity;
    float size;
    Color color;
} Player;

void init_player(Player *player);
void control_player(Player *player);
void update_player(Player *player, double dt);
void draw_player(Player player);


#endif // !PLAYER_H

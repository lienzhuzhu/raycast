/*
 * Declaration for Player type
 * Lien Zhu
 */


#ifndef PLAYER_H
#define PLAYER_H


#include <raylib.h>
#include "laser.h"
#include "wall.h"


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
void delete_player(Player *player);

void update_lasers(Player *player);
void draw_lasers(Player *player, Wall *wall);


#endif // !PLAYER_H

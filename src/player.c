/*
 * Player type implementation
 * Lien Zhu
 */


#include <stdio.h>
#include "player.h"
#include "global.h"
#include "raylib.h"

#define SPEED   100


void init_player(Player *player)
{
    player->lasers = NULL;
    player->position = (Vector2){SCREEN_CENTER_X, SCREEN_CENTER_Y};
    player->velocity = (Vector2){0.f, 0.f};
    player->size = 10.f;
    player->color = RED;
}

void control_player(Player *player)
{
    if (IsKeyDown(KEY_UP)) {
        player->velocity.y = -SPEED;
    }
    if (IsKeyDown(KEY_DOWN)) {
        player->velocity.y = SPEED;
    }
    if (IsKeyUp(KEY_UP) && IsKeyUp(KEY_DOWN)) {
        player->velocity.y = 0.f;
    }

    if (IsKeyDown(KEY_LEFT)) {
        player->velocity.x = -SPEED;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        player->velocity.x = SPEED;
    }
    if (IsKeyUp(KEY_LEFT) && IsKeyUp(KEY_RIGHT)) {
        player->velocity.x = 0.f;
    }
}

void update_player(Player *player, double dt)
{
    //player->position.x += player->velocity.x * dt;
    //player->position.y += player->velocity.y * dt;

    player->position.x = GetMouseX();
    player->position.y = GetMouseY();
}

void draw_player(Player player)
{
    DrawCircleV(player.position, player.size, player.color);
}

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
    Laser laser = {
        .position = { player->position.x, player->position.y },
        .direction = { GetMouseX(), GetMouseY() }
    };

    player->lasers = NULL;
    player->position = (Vector2){SCREEN_CENTER_X, SCREEN_CENTER_Y};
    player->velocity = (Vector2){0.f, 0.f};
    player->size = 10.f;
    player->color = RAYWHITE;
}

void control_player(Player *player)
{
    if (IsKeyDown(KEY_W)) {
        player->velocity.y = -SPEED;
    }
    if (IsKeyDown(KEY_S)) {
        player->velocity.y = SPEED;
    }
    if (IsKeyUp(KEY_W) && IsKeyUp(KEY_S)) {
        player->velocity.y = 0.f;
    }

    if (IsKeyDown(KEY_A)) {
        player->velocity.x = -SPEED;
    }
    if (IsKeyDown(KEY_D)) {
        player->velocity.x = SPEED;
    }
    if (IsKeyUp(KEY_A) && IsKeyUp(KEY_D)) {
        player->velocity.x = 0.f;
    }
}

void update_player(Player *player, double dt)
{
    player->position.x += player->velocity.x * dt;
    player->position.y += player->velocity.y * dt;

    //player->position.x = GetMouseX();
    //player->position.y = GetMouseY();
}

void draw_player(Player player)
{
    DrawCircleV(player.position, player.size, player.color);
}

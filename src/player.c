/*
 * Player type implementation
 * Lien Zhu
 */


#include "player.h"
#include "global.h"
#include "raylib.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SPEED   100


void init_player(Player *player)
{
    player->position = (Vector2){SCREEN_CENTER_X, SCREEN_CENTER_Y};
    player->velocity = (Vector2){0.f, 0.f};
    player->size = 10.f;
    player->color = RAYWHITE;

    Laser* laser = malloc(sizeof(Laser));
    if (laser != NULL) {
        laser->position = player->position;
        laser->direction = (Vector2){ GetMouseX(), GetMouseY() };
        player->lasers = laser;
    } else {
        player->lasers = NULL;
    }
}

void control_player(Player *player) {
    player->velocity.x = 0.f;
    player->velocity.y = 0.f;

    if (IsKeyDown(KEY_W)) {
        player->velocity.y -= SPEED; // Move up
    }
    if (IsKeyDown(KEY_S)) {
        player->velocity.y += SPEED; // Move down
    }
    if (IsKeyDown(KEY_A)) {
        player->velocity.x -= SPEED; // Move left
    }
    if (IsKeyDown(KEY_D)) {
        player->velocity.x += SPEED; // Move right
    }

    // Normalize velocity if moving diagonally to maintain constant speed
    if (player->velocity.x != 0.f && player->velocity.y != 0.f) {
        float norm = sqrt(player->velocity.x * player->velocity.x + player->velocity.y * player->velocity.y);
        player->velocity.x /= norm;
        player->velocity.y /= norm;
        player->velocity.x *= SPEED;
        player->velocity.y *= SPEED;
    }
}

void update_player(Player *player, double dt)
{
    player->position.x += player->velocity.x * dt;
    player->position.y += player->velocity.y * dt;

    update_lasers(player);
}

void draw_player(Player player)
{
    draw_lasers(&player);
    DrawCircleV(player.position, player.size, player.color);
}

void update_lasers(Player *player)
{
    update_laser(player->lasers, player->position);
}

void draw_lasers(Player *player)
{
    Laser laser = *(player->lasers);
    draw_laser(laser);
}

void delete_player(Player *player)
{
    if (player->lasers != NULL) {
        free(player->lasers);
        player->lasers = NULL;
    }
}

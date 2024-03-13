/*
 * Driver code for collision detection demo.
 * Lien Zhu
 */


#include "player.h"
#include "global.h"
#include "raylib.h"
#include "wall.h"
#include <time.h> // Include for clock_gettime


int main(void)
{
    SetTraceLogLevel(LOG_WARNING);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Collision Detection");
    HideCursor();

    double dt = 1.f / TARGET_FPS;
    struct timespec prev_time_point;
    clock_gettime(CLOCK_MONOTONIC, &prev_time_point); // Get current time
    double accumulator = 0.0;

    int num_walls = 0;
    Wall wall = {
        .start = {SCREEN_CENTER_X + 100, SCREEN_CENTER_Y - 100},
        .end = {SCREEN_CENTER_X + 120, SCREEN_CENTER_Y + 80},
        .thiccness = 6.f,
        .color = LIGHTGRAY
    };
    ++num_walls;


    Player player;
    init_player(&player);

    Wall world[NUM_WORLD_WALLS + num_walls];
    world[0] = wall;


    while (!WindowShouldClose())
    {
        struct timespec curr_time_point;
        clock_gettime(CLOCK_MONOTONIC, &curr_time_point);

        double frame_time = (curr_time_point.tv_sec - prev_time_point.tv_sec) + (curr_time_point.tv_nsec - prev_time_point.tv_nsec) / 1e9;
        if (frame_time > 1.f / MIN_FPS) {
            frame_time = 1.f / MIN_FPS;
        }
        prev_time_point = curr_time_point;
        accumulator += frame_time;

        control_player(&player);

        while (accumulator >= dt)
        {
            update_player(&player, dt);
            update_lasers(&player);
            accumulator -= dt;
        }

        BeginDrawing();

            ClearBackground(RAYWHITE);

            draw_guides();
            draw_wall(wall);
            draw_lasers(&player, world);
            draw_player(player);

        EndDrawing();
    }

    delete_player(&player);

    CloseWindow();

    return 0;
}

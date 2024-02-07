/*
 * Driver code for raycast program
 * Lien Zhu
 */


#include "player.h"
#include "global.h"
#include "wall.h"
#include <time.h> // Include for clock_gettime


int main(void)
{
    SetTraceLogLevel(LOG_WARNING);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raycasting");
    HideCursor();

    double dt = 1.f / TARGET_FPS;
    struct timespec prev_time_point;
    clock_gettime(CLOCK_MONOTONIC, &prev_time_point); // Get current time
    double accumulator = 0.0;


    Player player;
    init_player(&player);

    Wall w = {
        .start = {SCREEN_CENTER_X + 100, SCREEN_CENTER_Y - 100},
        .end = {SCREEN_CENTER_X + 120, SCREEN_CENTER_Y + 80},
        .thiccness = 6.f,
        .color = LIGHTGRAY
    };


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
            draw_wall(w);
            draw_lasers(&player, &w);
            draw_player(player);

        EndDrawing();
    }

    delete_player(&player);

    CloseWindow();

    return 0;
}

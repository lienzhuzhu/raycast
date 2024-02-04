/*
 * Driver code for raycast program
 * Lien Zhu
 */


#include "player.h"
#include "global.h"
#include "raylib.h"
#include <time.h> // Include for clock_gettime

int main(void)
{
    SetTraceLogLevel(LOG_WARNING);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raycasting");

    double dt = 1.f / TARGET_FPS;
    struct timespec prev_time_point;
    clock_gettime(CLOCK_MONOTONIC, &prev_time_point); // Get current time
    double accumulator = 0.0;

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

        while (accumulator >= dt)
        {
            accumulator -= dt;
        }

        BeginDrawing();

            ClearBackground(RAYWHITE);
            draw_guides();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

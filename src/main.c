/*
 * Driver code for raycast program
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
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raycasting");
    //HideCursor();

    double dt = 1.f / TARGET_FPS;
    struct timespec prev_time_point;
    clock_gettime(CLOCK_MONOTONIC, &prev_time_point); // Get current time
    double accumulator = 0.0;


    Player player;
    init_player(&player);

    Wall w = {
        .start = {SCREEN_CENTER_X + 100, SCREEN_CENTER_Y - 50},
        .end = {SCREEN_CENTER_X + 100, SCREEN_CENTER_Y + 50},
        .thiccness = 6.f,
        .color = RAYWHITE
    };

    Camera2D camera = { 0 };
    camera.target = player.position;
    camera.offset = (Vector2){ GetScreenWidth()/2.f, GetScreenHeight()/2.f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;


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
            accumulator -= dt;
        }

        //camera.target = player.position;

        BeginDrawing();

            ClearBackground(BLACK);

            //BeginMode2D(camera);

            draw_guides();
            draw_player(player);
            draw_wall(w);

            //EndMode2D();

        EndDrawing();
    }

    delete_player(&player);

    CloseWindow();

    return 0;
}

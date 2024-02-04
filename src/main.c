/*
 * Driver code for raycast program
 * Lien Zhu
 */


#include "player.h"
#include "global.h"
#include "raylib.h"
#include <time.h> // Include for clock_gettime


void draw_guides(void)
{
    Vector2 size = {10.f, 10.f};
    Vector2 topLeft = {10.f, 10.f};
    Vector2 topRight = {(GetScreenWidth()) - 20.f, 10.f};
    Vector2 bottomLeft = {10.f, (GetScreenHeight()) - 20.f};
    Vector2 bottomRight = {(GetScreenWidth()) - 20.f, (GetScreenHeight()) - 20.f};

    DrawRectangleV(topLeft, size, RED);
    DrawRectangleV(topRight, size, BLUE);
    DrawRectangleV(bottomLeft, size, BLUE);
    DrawRectangleV(bottomRight, size, RED);

    Vector2 points[4] = {
        {SCREEN_CENTER_X - SCREEN_CENTER_X / 2.f, SCREEN_CENTER_Y - SCREEN_CENTER_Y / 2.f},
        {SCREEN_CENTER_X + SCREEN_CENTER_X / 2.f, SCREEN_CENTER_Y - SCREEN_CENTER_Y / 2.f},
        {SCREEN_CENTER_X - SCREEN_CENTER_X / 2.f, SCREEN_CENTER_Y + SCREEN_CENTER_Y / 2.f},
        {SCREEN_CENTER_X + SCREEN_CENTER_X / 2.f, SCREEN_CENTER_Y + SCREEN_CENTER_Y / 2.f},
    };

    DrawLineV(points[0], points[1], BLACK);
    DrawLineV(points[0], points[2], BLACK);
    DrawLineV(points[1], points[3], BLACK);
    DrawLineV(points[2], points[3], BLACK);
}

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

        //control_player(&player);

        while (accumulator >= dt)
        {
            update_player(&player, dt);
            accumulator -= dt;
        }

        //camera.target = player.position;

        BeginDrawing();

            ClearBackground(RAYWHITE);

            //BeginMode2D(camera);

            draw_guides();
            draw_player(player);

            //EndMode2D();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

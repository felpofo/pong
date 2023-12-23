#include <stdio.h>
#include <stdbool.h>
#include "raylib.h"
#include "pong.h"
#include "ai.h"

#define PIXEL_SIZE 24

int game_size = 20;
Player player, ai;
Ball ball;

int main() {
    player.size = ai.size = 3;
    player.x = 1;
    ai.x = game_size - 1;
    player.y = ai.y = game_size / 2 - player.size / 2;
    player.strenght = 0;

    ball = (Ball) {
        .x = game_size / 2,
        .y = game_size / 2,
        .a = -1,
        .b = -1
    };

    InitWindow(game_size * PIXEL_SIZE, game_size * PIXEL_SIZE, "Tong");
    int fps = 6;
    SetTargetFPS(fps);

    int rounds = 0;
    int next_speedup = 3;
    int prev_direction = 0;
    bool ball_moves = false;
    while (!WindowShouldClose()) {
        prev_direction = ball.a;

        int move = -IsKeyDown(KEY_UP) + IsKeyDown(KEY_DOWN);
        if (move < 0) player_move_upwards(&player, 0);
        if (move > 0) player_move_downwards(&player, game_size);
        if (!move) player.strenght = 0;

        ai_move(&ai, &player, &ball, game_size);

        if (ball_moves) {
            ball_move(&ball, &player, &ai, game_size);
        }

        if (prev_direction != ball.a) {
            rounds++;
        }

        ball_moves = !ball_moves;

        if (rounds >= next_speedup) {
            rounds = 0;
            next_speedup *= 1.5;
            SetTargetFPS(fps += 2);
        }

        BeginDrawing();
        ClearBackground(BLACK);

        DrawRectangle(player.x * PIXEL_SIZE,   player.y * PIXEL_SIZE, PIXEL_SIZE, player.size * PIXEL_SIZE, WHITE);
        DrawRectangle((ai.x - 1) * PIXEL_SIZE, ai.y * PIXEL_SIZE,     PIXEL_SIZE, ai.size * PIXEL_SIZE,     WHITE);

        DrawRectangle(ball.x * PIXEL_SIZE, ball.y * PIXEL_SIZE, PIXEL_SIZE, PIXEL_SIZE, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
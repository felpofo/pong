#pragma once

// #include "raylib.h"

typedef struct Player {
    int x, y, size;
    int strenght;
} Player;

void player_move_upwards(Player* player, int min);
void player_move_downwards(Player* player, int max);

typedef struct Ball {
    int x, y;
    int a, b;
} Ball;

void ball_move(Ball* ball, Player* player1, Player* player2, int bounds);
void ball_change_projection(Ball* ball, int strenght);

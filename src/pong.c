#include "pong.h"

void ball_move(Ball* ball, Player* left, Player* right, int bounds) {
    int x = ball->x + ball->a;
    int y = ball->y + ball->b;

    // player1 lose
    if (ball->x <= 0) {
        ball->x = bounds / 2;
        ball->y = bounds / 2;
        ball->a = ball->b = -1;
        return;
    }

    // player2 lose
    if (ball->x >= bounds - 1) {
        ball->x = bounds / 2;
        ball->y = bounds / 2;
        ball->a = ball->b = -1;
        return;
    }

    // player1 collision
    if (left->x == x && y >= left->y && y <= left->y + left->size) {
        ball->a = -ball->a;
        ball->b = left->strenght ?: ball->b;
        x = ball->x + ball->a;
        y = ball->y + ball->b;
    }

    // player2 collision
    if (right->x == x + 1 && y >= right->y && y <= right->y + right->size) {
        ball->a = -ball->a;
        ball->b = right->strenght ?: ball->b;
        x = ball->x + ball->a;
        y = ball->y + ball->b;
    }

    // ball touches ceiling
    if (y < 0) {
        ball->b = -ball->b;
        y = ball->y + ball->b;
    }

    // ball touches floor
    if (y >= bounds) {
        ball->b = -ball->b;
        y = ball->y + ball->b;
    }

    ball->x = x;
    ball->y = y;
}

void ball_change_projection(Ball* ball, int strenght) {
    ball->a = -ball->a * strenght;
    ball->b = -ball->b * strenght;
}

void player_move_upwards(Player* player, int min) {
    if (player->y > min) {
        player->y--;
        player->strenght = 0;
    }

    if (player->strenght < 0)
        player->strenght = 0;

    player->strenght--;
}

void player_move_downwards(Player* player, int max) {
    if (player->y < max - player->size) {
        player->y++;
        player->strenght = 0;
    }

    if (player->strenght > 0)
        player->strenght = 0;

    player->strenght++;
}
#include <string.h>
#include "ai.h"
#include "pong.h"

void ai_move(Player* ai, Player* oponent, Ball* ball, int bounds) {
    Ball expected;
    memcpy(&expected, ball, sizeof(Ball));

    while (expected.x < ai->x) {
        ball_move(&expected, oponent, ai, bounds);

        if (expected.a < 0) break;
    }

    if (expected.y <= ai->y) {
        player_move_upwards(ai, 0);
    }

    if (expected.y >= ai->y + ai->size) {
        player_move_downwards(ai, bounds);
    }
}
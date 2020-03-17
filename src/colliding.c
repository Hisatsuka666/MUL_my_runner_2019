/*
** EPITECH PROJECT, 2020
** colliding.c
** File description:
** colliding fucntion source file
*/

#include "../include/my_runner.h"

void is_colliding(game_t  *game, pnj_t *pnj, parallax_t *parallax)
{
    pnj->hitbox.rect.top = pnj->hitbox.position.y;
    pnj->hitbox.rect.left = pnj->hitbox.position.x;
    parallax->obstacle.hitbox.rect.top = parallax->obstacle.hitbox.position.y;
    parallax->obstacle.hitbox.rect.left = parallax->obstacle.hitbox.position.x;
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(pnj->live1.clock)) > 200) {
        if (sfIntRect_intersects(&pnj->hitbox.rect,
        &parallax->obstacle.hitbox.rect, NULL)) {
            pnj->lives -= 1;
            if (pnj->lives == 0) {
                game->lose = 1;
            }
        }
        sfClock_restart(pnj->live1.clock);
    }
}
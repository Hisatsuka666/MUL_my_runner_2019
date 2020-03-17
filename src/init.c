/*
** EPITECH PROJECT, 2020
** init.c
** File description:
** init source file
*/

#include "../include/my_runner.h"

void init_window(game_t *game)
{
    game->mode.width = 1920;
    game->mode.height = 1080;
    game->mode.bitsPerPixel = 32;
    game->clock = sfClock_create();
}

void init_hitbox(pnj_t *pnj)
{
    pnj->hitbox.rect.top = pnj->hitbox.position.y;
    pnj->hitbox.rect.left = pnj->hitbox.position.x;
    pnj->hitbox.rect.width = 360 * 0.20;
    pnj->hitbox.rect.height = 450 * 0.20;
}

void init_pnj_rect(pnj_t *pnj)
{
    pnj->lives = 3;
    pnj->jumping = 0;
    pnj->rect.top = 0;
    pnj->rect.left = 0;
    pnj->rect.width = 363;
    pnj->rect.height = 458;
}

void init_clock(intro_t *intro, pnj_t *pnj, parallax_t *parallax)
{
    intro->clock = sfClock_create();
    pnj->clock = sfClock_create();
    pnj->animation = sfClock_create();
    pnj->live1.clock = sfClock_create();
    pnj->live2.clock = sfClock_create();
    pnj->live3.clock = sfClock_create();
    parallax->obstacle.clock = sfClock_create();
    parallax->floor.clock = sfClock_create();
    parallax->trees.clock = sfClock_create();
    parallax->mountain.clock = sfClock_create();
    parallax->cloud.clock = sfClock_create();
}
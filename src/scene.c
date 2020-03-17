/*
** EPITECH PROJECT, 2020
** scene.c
** File description:
** scene source file
*/

#include "../include/my_runner.h"

void change_scene(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyReturn) && game->scene == 0) {
        game->scene = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyP) && game->scene == 1) {
        game->scene = 2;
    }
    if (sfKeyboard_isKeyPressed(sfKeyR) && game->scene == 2) {
        game->scene = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && game->scene == 2) {
        game->scene = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) && game->scene == 0) {
        sfRenderWindow_close(game->window);
    }
}

void display_lose(game_t *game, pnj_t *pnj)
{
    if (game->lose == 1)
        sfRenderWindow_drawSprite(game->window,
        pnj->you_lose.sprite, NULL);
}
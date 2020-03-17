/*
** EPITECH PROJECT, 2020
** events.c
** File description:
** events source file
*/

#include "../include/my_runner.h"

void close_window(game_t *game)
{
    if (game->Event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
}

void state_png(game_t *game, pnj_t *pnj)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (pnj->jumping != 1) {
            pnj->jumping = 1;
            pnj->velocity = -900;
        }
    }
}

void activate_hitboxes(game_t *game, pnj_t *pnj)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(pnj->live2.clock)) > 200) {
        if (sfKeyboard_isKeyPressed(sfKeyH) && pnj->hitboxes == 0) {
            pnj->hitboxes = 1;
        }
        sfClock_restart(pnj->live2.clock);
    }
}

void desactivate_hitboxes(game_t *game, pnj_t *pnj)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(pnj->live3.clock)) > 200) {
        if (sfKeyboard_isKeyPressed(sfKeyJ) && pnj->hitboxes == 1) {
            pnj->hitboxes = 0;
        }
        sfClock_restart(pnj->live3.clock);
    }
}

void analyse_events(game_t *game, pnj_t *pnj)
{
    change_scene(game);
    state_png(game, pnj);
    activate_hitboxes(game, pnj);
    desactivate_hitboxes(game, pnj);
    close_window(game);
}
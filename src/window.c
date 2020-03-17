/*
** EPITECH PROJECT, 2020
** window.c
** File description:
** source file for window
*/

#include "../include/my_runner.h"

void create_window(game_t *game)
{
    game->window = sfRenderWindow_create(game->mode, "Road Runner",
    sfResize | sfClose, NULL);
    if (!game->window)
        exit (84);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    sfRenderWindow_setVerticalSyncEnabled(game->window, sfFalse);
}
/*
** EPITECH PROJECT, 2020
** parallax.c
** File description:
** parallax source file
*/

#include "../include/my_runner.h"

void display_game_trees(game_t *game, parallax_t *parallax)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
    (parallax->trees.clock)) > 0.10) {
        sfSprite_setPosition(parallax->trees.sprite, parallax->trees.position);
        sfSprite_setPosition(parallax->trees.sprite2,
        parallax->trees.position2);
        if (game->scene != 2 && game->lose != 1) {
            if (parallax->trees.position.x < -1919)
                parallax->trees.position.x = 1920;
            if (parallax->trees.position2.x < -1919)
                parallax->trees.position2.x = 1920;
            else {
                parallax->trees.position.x -= 3 +
                (sfTime_asSeconds(sfClock_getElapsedTime(game->clock)) * 0.05);
                parallax->trees.position2.x -= 3 +
                (sfTime_asSeconds(sfClock_getElapsedTime(game->clock)) * 0.05);
            }
        }
        sfClock_restart(parallax->trees.clock);
    }
    draw(game, parallax);
}

void display_game_moutains(game_t *game, parallax_t *parallax)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
    (parallax->mountain.clock)) > 0.10) {
        sfSprite_setPosition(parallax->mountain.sprite,
        parallax->mountain.position);
        sfSprite_setPosition(parallax->mountain.sprite2,
        parallax->mountain.position2);
        if (game->scene != 2 && game->lose != 1) {
            if (parallax->mountain.position.x < -1919)
                parallax->mountain.position.x = 1920;
            if (parallax->mountain.position2.x < -1919)
                parallax->mountain.position2.x = 1920;
            else {
                parallax->mountain.position.x -= 0.5 +
                (sfTime_asSeconds(sfClock_getElapsedTime(game->clock)) * 0.05);
                parallax->mountain.position2.x -= 0.5 +
                (sfTime_asSeconds(sfClock_getElapsedTime(game->clock)) * 0.05);
            }
        }
        sfClock_restart(parallax->mountain.clock);
    }
    draw(game, parallax);
}

void display_game_clouds(game_t *game, parallax_t *parallax)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
    (parallax->cloud.clock)) > 0.10) {
        sfSprite_setPosition(parallax->cloud.sprite,
        parallax->cloud.position);
        sfSprite_setPosition(parallax->cloud.sprite2,
        parallax->cloud.position2);
        if (game->scene != 2 && game->lose != 1) {
            if (parallax->cloud.position.x < -1919)
                parallax->cloud.position.x = 1920;
            if (parallax->cloud.position2.x < -1919)
                parallax->cloud.position2.x = 1920;
            else {
                parallax->cloud.position.x -= 0.08 +
                (sfTime_asSeconds(sfClock_getElapsedTime(game->clock)) * 0.05);
                parallax->cloud.position2.x -= 0.08 +
                (sfTime_asSeconds(sfClock_getElapsedTime(game->clock)) * 0.05);
            }
        }
        sfClock_restart(parallax->cloud.clock);
    }
    draw(game, parallax);
}
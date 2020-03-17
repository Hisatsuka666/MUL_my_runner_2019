/*
** EPITECH PROJECT, 2020
** display.c
** File description:
** display source file
*/

#include "../include/my_runner.h"

void display_pause(game_t *game, pause_t *pause)
{
    if (game->scene == 2)
        sfRenderWindow_drawSprite(game->window, pause->sprite, NULL);
}

void update_obstacle (game_t *game, parallax_t *parallax)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
    (parallax->obstacle.clock)) > 0.50) {
        sfSprite_setPosition(parallax->obstacle.sprite,
        parallax->obstacle.position);
        if (game->scene != 2 && game->lose != 1) {
            if (parallax->obstacle.position.x < -50)
                parallax->obstacle.position.x = 1930;
            else {
                parallax->obstacle.position.x -= 8 +
                (sfTime_asSeconds(sfClock_getElapsedTime(game->clock)) * 0.05);
            }
        }
        sfClock_restart(parallax->obstacle.clock);
    }
    draw(game, parallax);
}

void display_game_bg(game_t *game, parallax_t *parallax)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
    (parallax->floor.clock)) > 0.50) {
        sfSprite_setPosition(parallax->floor.sprite, parallax->floor.position);
        sfSprite_setPosition(parallax->floor.sprite2,
        parallax->floor.position2);
        if (game->scene != 2 && game->lose != 1) {
            if (parallax->floor.position.x < -1919)
                parallax->floor.position.x = 1920;
            if (parallax->floor.position2.x < -1919)
                parallax->floor.position2.x = 1920;
            else {
                parallax->floor.position.x -= 8 +
                (sfTime_asSeconds(sfClock_getElapsedTime(game->clock)) * 0.05);
                parallax->floor.position2.x -= 8 +
                (sfTime_asSeconds(sfClock_getElapsedTime(game->clock)) * 0.05);
            }
        }
        sfClock_restart(parallax->floor.clock);
    }
    draw(game, parallax);
}

void draw(game_t *game, parallax_t *parallax)
{
    sfRenderWindow_drawSprite(game->window, parallax->sky.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, parallax->cloud.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, parallax->cloud.sprite2, NULL);
    sfRenderWindow_drawSprite(game->window, parallax->mountain.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, parallax->mountain.sprite2, NULL);
    sfRenderWindow_drawSprite(game->window, parallax->trees.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, parallax->trees.sprite2, NULL);
    sfRenderWindow_drawSprite(game->window, parallax->floor.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, parallax->floor.sprite2, NULL);
    sfRenderWindow_drawSprite(game->window, parallax->obstacle.sprite, NULL);
}

void draw_lives(game_t *game, pnj_t *pnj)
{
    if (pnj->lives >= 1) {
        sfRenderWindow_drawSprite(game->window, pnj->live1.sprite, NULL);
        if (pnj->lives >= 2) {
            sfRenderWindow_drawSprite(game->window, pnj->live2.sprite, NULL);
            if (pnj->lives >= 3) {
                sfRenderWindow_drawSprite(game->window, pnj->live3.sprite,
                NULL);
            }
        }
    }
}
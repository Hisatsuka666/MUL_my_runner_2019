/*
** EPITECH PROJECT, 2020
** display_intro.c
** File description:
** display intro source file
*/

#include "../include/my_runner.h"

void display_layer1(game_t *game, intro_t *intro)
{
    sfRenderWindow_drawSprite(game->window, intro->layer1.sprite, NULL);
}

void display_layer2(game_t *game, intro_t *intro)
{
    sfRenderWindow_drawSprite(game->window, intro->layer2.sprite, NULL);
}

void display_layer3(game_t *game, intro_t *intro)
{
    sfRenderWindow_drawSprite(game->window, intro->layer3.sprite, NULL);
}

void display_layer4(game_t *game, intro_t *intro)
{
    sfRenderWindow_drawSprite(game->window, intro->layer4.sprite, NULL);
}

void display_layer4_2(game_t *game, intro_t *intro)
{
    sfRenderWindow_drawSprite(game->window, intro->layer5.sprite, NULL);
}
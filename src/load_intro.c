/*
** EPITECH PROJECT, 2020
** intro.c
** File description:
** intro source file
*/

#include "../include/my_runner.h"

void load_intro(intro_t *intro)
{
    intro->layer1.texture = sfTexture_createFromFile
    ("assets/intro1.jpg", NULL);
    intro->layer2.texture = sfTexture_createFromFile
    ("assets/intro2.jpg", NULL);
    intro->layer3.texture = sfTexture_createFromFile
    ("assets/warner_intro.png", NULL);
    intro->layer4.texture = sfTexture_createFromFile
    ("assets/PARALLAX/layer01.png", NULL);
    intro->layer5.texture = sfTexture_createFromFile
    ("assets/PARALLAX/layer02.png", NULL);
    intro->logo.texture = sfTexture_createFromFile
    ("assets/runner.png", NULL);
    intro->layer1.sprite = sfSprite_create();
    intro->layer2.sprite = sfSprite_create();
    intro->layer3.sprite = sfSprite_create();
    intro->layer4.sprite = sfSprite_create();
    intro->layer5.sprite = sfSprite_create();
    intro->logo.sprite = sfSprite_create();
    load_intro_texture(intro);
}

void load_intro_texture(intro_t *intro)
{
    sfSprite_setTexture(intro->layer1.sprite, intro->layer1.texture, sfTrue);
    sfSprite_setTexture(intro->layer2.sprite, intro->layer2.texture, sfTrue);
    sfSprite_setTexture(intro->layer3.sprite, intro->layer3.texture, sfTrue);
    sfSprite_setTexture(intro->layer4.sprite, intro->layer4.texture, sfTrue);
    sfSprite_setTexture(intro->layer5.sprite, intro->layer5.texture, sfTrue);
    sfSprite_setTexture(intro->logo.sprite, intro->logo.texture, sfTrue);
    sfSprite_setPosition(intro->logo.sprite, (sfVector2f){640, 250});
}

void display_intro(game_t *game, intro_t *intro)
{
    intro->time = sfClock_getElapsedTime(intro->clock);
    intro->seconds = intro->time.microseconds / 1000000.0;

    if (intro->clocktimer < 1)
        display_layer1(game, intro);
    if (intro->clocktimer == 1) {
        display_layer2(game, intro);
    }
    if (intro->clocktimer == 2) {
        display_layer3(game, intro);
    }
    if (intro->clocktimer > 2) {
        display_layer4(game, intro);
        display_layer4_2(game, intro);
        display_logo(game, intro);
    }
    if (intro->seconds > 2) {
        sfClock_restart(intro->clock);
        intro->clocktimer += 1;
    }
}

void display_logo(game_t *game, intro_t *intro)
{
    sfRenderWindow_drawSprite(game->window, intro->logo.sprite, NULL);
}
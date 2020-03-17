/*
** EPITECH PROJECT, 2020
** load.c
** File description:
** load main file
*/

#include "../include/my_runner.h"

void load_music(music_t *music)
{
    music->music = sfMusic_createFromFile("assets/videoplayback.ogg");
    if (!music->music)
        exit (84);
}

void load_obstacle(parallax_t *parallax)
{
    parallax->obstacle.texture = sfTexture_createFromFile
    ("assets/png/kunai.png", NULL);
    parallax->obstacle.sprite = sfSprite_create();
    parallax->obstacle.position.x = 1930;
    parallax->obstacle.position.y = 785;
    parallax->obstacle.hitbox.position.x = parallax->obstacle.position.x;
    parallax->obstacle.hitbox.position.y = parallax->obstacle.position.y;
    sfSprite_setTexture(parallax->obstacle.sprite,
    parallax->obstacle.texture, sfTrue);
}

void load_pnj(pnj_t *pnj)
{
    pnj->texture = sfTexture_createFromFile
    ("assets/sprite.png", NULL);
    pnj->sprite = sfSprite_create();
    pnj->ground_pos = 785;
    pnj->position.x = 100;
    pnj->position.y = pnj->ground_pos;
    sfSprite_setTexture(pnj->sprite, pnj->texture, sfTrue);
    sfSprite_setPosition(pnj->sprite, (sfVector2f){100, 785});
    sfSprite_setScale(pnj->sprite, (sfVector2f){0.30, 0.30});
}

void load_pnj_lives(pnj_t *pnj)
{
    pnj->live1.texture = sfTexture_createFromFile("assets/png/heart.png", NULL);
    pnj->live2.texture = sfTexture_createFromFile("assets/png/heart.png", NULL);
    pnj->live3.texture = sfTexture_createFromFile("assets/png/heart.png", NULL);
    pnj->live1.sprite = sfSprite_create();
    pnj->live2.sprite = sfSprite_create();
    pnj->live3.sprite = sfSprite_create();
    pnj->live1.position.x = 0;
    pnj->live2.position.x = 60;
    pnj->live3.position.x = 120;
    pnj->live1.position.y = 0;
    pnj->live2.position.y = 0;
    pnj->live2.position.y = 0;
    sfSprite_setTexture(pnj->live1.sprite, pnj->live1.texture, sfTrue);
    sfSprite_setTexture(pnj->live2.sprite, pnj->live2.texture, sfTrue);
    sfSprite_setTexture(pnj->live3.sprite, pnj->live3.texture, sfTrue);
    sfSprite_setPosition(pnj->live1.sprite, (sfVector2f){0, 0});
    sfSprite_setPosition(pnj->live2.sprite, (sfVector2f){60, 0});
    sfSprite_setPosition(pnj->live3.sprite, (sfVector2f){120, 0});
}

void load_pause(pause_t *pause)
{
    pause->texture = sfTexture_createFromFile("assets/pause.png", NULL);
    pause->sprite = sfSprite_create();
    pause->position.x = 500;
    pause->position.y = 500;
    sfSprite_setTexture(pause->sprite, pause->texture, sfTrue);
    sfSprite_setPosition(pause->sprite, (sfVector2f){550, 400});
}
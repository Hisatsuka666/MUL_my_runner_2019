/*
** EPITECH PROJECT, 2020
** load_parallax.c
** File description:
** source file load parallax
*/

#include "../include/my_runner.h"

void load_floor(parallax_t *parallax)
{
    parallax->floor.texture =
    sfTexture_createFromFile("assets/parallax/layer05.png", NULL);
    parallax->floor.texture2 =
    sfTexture_createFromFile("assets/parallax/layer05.png", NULL);
    parallax->floor.sprite = sfSprite_create();
    parallax->floor.sprite2 = sfSprite_create();
    sfSprite_setTexture(parallax->floor.sprite,
    parallax->floor.texture, sfTrue);
    sfSprite_setTexture(parallax->floor.sprite2,
    parallax->floor.texture2, sfTrue);
    parallax->floor.position = (sfVector2f){0, 0};
    parallax->floor.position2 = (sfVector2f){1920, 0};
}

void load_sky(parallax_t *parallax)
{
    parallax->sky.texture =
    sfTexture_createFromFile("assets/parallax/layer01.png", NULL);
    parallax->sky.texture2 =
    sfTexture_createFromFile("assets/parallax/layer01.png", NULL);
    parallax->sky.sprite = sfSprite_create();
    parallax->sky.sprite2 = sfSprite_create();
    sfSprite_setTexture(parallax->sky.sprite, parallax->sky.texture, sfTrue);
    sfSprite_setTexture(parallax->sky.sprite2, parallax->sky.texture2, sfTrue);
    parallax->sky.position = (sfVector2f){0, 0};
    parallax->sky.position2 = (sfVector2f){1920, 0};
}

void load_cloud(parallax_t *parallax)
{
    parallax->cloud.texture =
    sfTexture_createFromFile("assets/parallax/layer02.png", NULL);
    parallax->cloud.texture2 =
    sfTexture_createFromFile("assets/parallax/layer02.png", NULL);
    parallax->cloud.sprite = sfSprite_create();
    parallax->cloud.sprite2 = sfSprite_create();
    sfSprite_setTexture(parallax->cloud.sprite,
    parallax->cloud.texture, sfTrue);
    sfSprite_setTexture(parallax->cloud.sprite2,
    parallax->cloud.texture2, sfTrue);
    parallax->cloud.position = (sfVector2f){0, 0};
    parallax->cloud.position2 = (sfVector2f){1920, 0};
}

void load_mountain(parallax_t *parallax)
{
    parallax->mountain.texture =
    sfTexture_createFromFile("assets/parallax/layer03.png", NULL);
    parallax->mountain.texture2 =
    sfTexture_createFromFile("assets/parallax/layer03.png", NULL);
    parallax->mountain.sprite = sfSprite_create();
    parallax->mountain.sprite2 = sfSprite_create();
    sfSprite_setTexture(parallax->mountain.sprite,
    parallax->mountain.texture, sfTrue);
    sfSprite_setTexture(parallax->mountain.sprite2,
    parallax->mountain.texture2, sfTrue);
    parallax->mountain.position = (sfVector2f){0, 0};
    parallax->mountain.position2 = (sfVector2f){1920, 0};
}

void load_trees(parallax_t *parallax)
{
    parallax->trees.texture =
    sfTexture_createFromFile("assets/parallax/layer04.png", NULL);
    parallax->trees.texture2 =
    sfTexture_createFromFile("assets/parallax/layer04.png", NULL);
    parallax->trees.sprite = sfSprite_create();
    parallax->trees.sprite2 = sfSprite_create();
    sfSprite_setTexture(parallax->trees.sprite,
    parallax->trees.texture, sfTrue);
    sfSprite_setTexture(parallax->trees.sprite2,
    parallax->trees.texture2, sfTrue);
    parallax->trees.position2 = (sfVector2f){0, 10};
    parallax->trees.position2 = (sfVector2f){1920, 10};
}
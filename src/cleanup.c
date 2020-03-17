/*
** EPITECH PROJECT, 2020
** cleanup.c
** File description:
** cleanup source file
*/

#include "../include/my_runner.h"

void cleanup_gbg(parallax_t *parallax)
{
    sfSprite_destroy(parallax->floor.sprite);
    sfSprite_destroy(parallax->floor.sprite2);
    sfSprite_destroy(parallax->sky.sprite);
    sfSprite_destroy(parallax->sky.sprite2);
    sfSprite_destroy(parallax->cloud.sprite);
    sfSprite_destroy(parallax->cloud.sprite2);
    sfSprite_destroy(parallax->mountain.sprite);
    sfSprite_destroy(parallax->mountain.sprite2);
    sfSprite_destroy(parallax->trees.sprite);
    sfSprite_destroy(parallax->trees.sprite2);
    sfTexture_destroy(parallax->floor.texture);
    sfTexture_destroy(parallax->floor.texture2);
    free(parallax);
}

void cleanup_pnj(pnj_t *pnj)
{
    sfClock_destroy(pnj->clock);
    sfSprite_destroy(pnj->sprite);
    sfTexture_destroy(pnj->texture);
    free(pnj);
}
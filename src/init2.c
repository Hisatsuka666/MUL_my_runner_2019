/*
** EPITECH PROJECT, 2020
** init2.c
** File description:
** second source file for init funcs
*/

#include "../include/my_runner.h"

void init_hitbox_obs(parallax_t *parallax)
{
    parallax->obstacle.hitbox.rect.top = parallax->obstacle.hitbox.position.y;
    parallax->obstacle.hitbox.rect.left = parallax->obstacle.hitbox.position.x;
    parallax->obstacle.hitbox.rect.width = 32;
    parallax->obstacle.hitbox.rect.height = 160;
}

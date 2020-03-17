/*
** EPITECH PROJECT, 2020
** load_game.c
** File description:
** source file that load the game
*/

#include "../include/my_runner.h"

void load_game(intro_t *intro, music_t
*music, parallax_t *parallax, pause_t *pause, pnj_t *pnj)
{
    load_intro(intro);
    load_music(music);
    load_game_scene(parallax);
    load_pnj(pnj);
    load_pause(pause);
    load_lose(pnj);
    load_pnj_lives(pnj);
    load_obstacle(parallax);
    return;
}

void load_game_scene(parallax_t *parallax)
{
    load_floor(parallax);
    load_sky(parallax);
    load_cloud(parallax);
    load_mountain(parallax);
    load_trees(parallax);
    return;
}

void load_lose(pnj_t *pnj)
{
    pnj->you_lose.texture = sfTexture_createFromFile("assets/lose.png", NULL);
    pnj->you_lose.sprite = sfSprite_create();
    pnj->you_lose.position.x = 500;
    pnj->you_lose.position.y = 500;
    sfSprite_setTexture(pnj->you_lose.sprite, pnj->you_lose.texture, sfTrue);
    sfSprite_setPosition(pnj->you_lose.sprite, (sfVector2f){600, 300});
}
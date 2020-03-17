/*
** EPITECH PROJECT, 2020
** game.c
** File description:
** game engine source file
*/

#include "../include/my_runner.h"

void game_engine(game_t *game, intro_t *intro, pnj_t *pnj,
parallax_t *parallax, pause_t *pause, music_t *music)
{
    if (game->scene == 0) {
        display_intro(game, intro);
    }
    if (game->scene == 1 || game->scene == 2) {
        sfMusic_stop(music->music);
        display_parallax(game, parallax);
        update(pnj, game, parallax);
        draw_run(game, pnj, parallax);
        draw_lives(game, pnj);
        display_pause(game, pause);
        display_lose(game, pnj);
        if (pnj->hitboxes == 1) {
            draw_hitbox(game, pnj);
            draw_hitbox_obs(game, parallax);
        }
    }
}

void display_parallax(game_t *game, parallax_t *parallax)
{
    update_obstacle(game, parallax);
    display_game_bg(game, parallax);
    display_game_trees(game, parallax);
    display_game_moutains(game, parallax);
    display_game_clouds(game, parallax);
}
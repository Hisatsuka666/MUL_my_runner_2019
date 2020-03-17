/*
** EPITECH PROJECT, 2020
** animate.c
** File description:
** animation source file
*/

#include "../include/my_runner.h"

static const float GRAV = 2000;

void animate_pnj(pnj_t *pnj, game_t *game)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(pnj->animation)) > 45) {
        if (game->scene != 2 && pnj->jumping != 1 && game->lose != 1) {
            if (pnj->rect.left == 3267)
                pnj->rect.left = -363;
            pnj->rect.left += 363;
        }
        sfClock_restart(pnj->animation);
    }
}

void draw_hitbox(game_t *game, pnj_t *pnj)
{
    sfRectangleShape *box = sfRectangleShape_create();
    sfRectangleShape_setSize(box, (sfVector2f)
    {pnj->hitbox.rect.width, pnj->hitbox.rect.height});
    sfRectangleShape_setFillColor(box, sfMagenta);
    sfRectangleShape_setPosition(box, (sfVector2f)
    {pnj->hitbox.position.x, pnj->hitbox.position.y});
    sfRenderWindow_drawRectangleShape(game->window, box, NULL);
}

void draw_hitbox_obs(game_t *game, parallax_t *parallax)
{
    sfRectangleShape *box1 = sfRectangleShape_create();
    sfRectangleShape_setSize(box1, (sfVector2f)
    {parallax->obstacle.hitbox.rect.width,
    parallax->obstacle.hitbox.rect.height});
    sfRectangleShape_setFillColor(box1, sfGreen);
    sfRectangleShape_setPosition(box1, (sfVector2f)
    {parallax->obstacle.hitbox.position.x,
    parallax->obstacle.hitbox.position.y});
    sfRenderWindow_drawRectangleShape(game->window, box1, NULL);
}

void draw_run(game_t *game, pnj_t *pnj, parallax_t *parallax)
{
    sfSprite_setTextureRect(pnj->sprite, pnj->rect);
    sfSprite_setPosition(pnj->sprite, (sfVector2f){pnj->position.x,
    pnj->position.y});
    pnj->hitbox.position.x = pnj->position.x + 20;
    pnj->hitbox.position.y = pnj->position.y + 20;
    parallax->obstacle.hitbox.position.x = parallax->obstacle.position.x;
    parallax->obstacle.hitbox.position.y = parallax->obstacle.position.y;
    sfRenderWindow_drawSprite(game->window, pnj->sprite, NULL);
}

void update(pnj_t *pnj, game_t *game, parallax_t *parallax)
{
    if (game->scene != 2 && game->lose != 1) {
        animate_pnj(pnj, game);
        is_colliding(game, pnj, parallax);
        pnj->velocity += GRAV *
        sfTime_asSeconds(sfClock_getElapsedTime(pnj->clock));
        pnj->position.y += pnj->velocity *
        sfTime_asSeconds(sfClock_getElapsedTime(pnj->clock));
        if (pnj->position.y >= pnj->ground_pos) {
            pnj->position.y = pnj->ground_pos;
            pnj->jumping = 0;
            pnj->velocity = 0;
        }
    }
    sfClock_restart(pnj->clock);
}
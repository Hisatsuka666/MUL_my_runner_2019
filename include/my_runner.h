/*
** EPITECH PROJECT, 2019
** my_runner.h
** File description:
** header file
*/

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Window.h>
#include <SFML/Window/Export.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <math.h>

typedef struct music {
    sfMusic *music;
    struct music *next;
} music_t;

typedef struct game {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent Event;
    sfIntRect rect;
    sfClock *clock;
    sfVector2f set_pos;
    sfVector2f ret_pos;
    int scene;
    int lose;
    int win;
} game_t;

typedef struct map {
    size_t len;
    FILE *fd;
} map_t;

typedef struct lives {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfClock *clock;
} lives_t;

typedef struct hitbox {
    sfIntRect rect;
    sfVector2f position;
} hitbox_t;

typedef struct pnj {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfClock *clock;
    sfClock *animation;
    sfVector2f position;
    lives_t you_lose;
    int ground_pos;
    int running;
    int jumping;
    int hitboxes;
    int velocity;
    int lives;
    hitbox_t hitbox;
    lives_t live1;
    lives_t live2;
    lives_t live3;
} pnj_t;

typedef struct object {
    sfTexture *texture;
    sfTexture *texture2;
    sfSprite *sprite;
    sfSprite *sprite2;
    sfIntRect rect;
    hitbox_t hitbox;
    sfClock *clock;
    sfVector2f position;
    sfVector2f position2;
} object_t;

typedef struct parallax
{
    object_t floor;
    object_t trees;
    object_t mountain;
    object_t cloud;
    object_t sky;
    object_t obstacle;
} parallax_t;

typedef struct menu
{
    object_t menu_logo;
    object_t menu_bg;
} menu_t;

typedef struct intro_bin
{
    sfTexture *texture;
    sfSprite *sprite;
} intro_bin_t;

typedef struct intro {
    intro_bin_t layer1;
    intro_bin_t layer2;
    intro_bin_t layer3;
    intro_bin_t layer4;
    intro_bin_t layer5;
    intro_bin_t logo;
    sfClock *clock;
    sfTime time;
    float seconds;
    int clocktimer;
} intro_t;

typedef struct pause {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
} pause_t;

typedef struct bg {
    sfTexture *texture;
    sfSprite *sprite;
} bg_t;

int main(int ac, char **av);
void my_putchar(char c);
void my_putstr(char const *str);
int is_help(int ac, char **av);
int is_flag(char *str);
void display_help(void);
void create_window(game_t *game);
void change_scene(game_t *game);
void close_window(game_t *game);
void analyse_events(game_t *game, pnj_t *pnj);
void activate_hitboxes(game_t *game, pnj_t *pnj);
void desactivate_hitboxes(game_t *game, pnj_t *pnj);
void state_png(game_t *game, pnj_t *pnj);
void init(game_t *game, pnj_t *pnj, pause_t *pause, parallax_t *parallax);
void init_window(game_t *game);
void init_pnj_rect(pnj_t *pnj);
void init_obs_rect(parallax_t *parallax);
void init_hitbox(pnj_t *pnj);
void init_hitbox_obs(parallax_t *parallax);
void init_clock(intro_t *intro, pnj_t *pnj, parallax_t *parallax);
void display_intro(game_t *game, intro_t *intro);
void display_pause(game_t *game, pause_t *pause);
void display_lose(game_t *game, pnj_t *pnj);
void display_game_bg(game_t *game, parallax_t *parallax);
void load_intro(intro_t *intro);
void load_intro_texture(intro_t *intro);
void load_music(music_t *music);
void load_pause(pause_t *pause);
void load_pnj(pnj_t *pnj);
void load_lose(pnj_t *pnj);
void load_pnj_lives(pnj_t *pnj);
void load_obstacle(parallax_t *parallax);
void load_floor(parallax_t *parallax);
void load_sky(parallax_t *parallax);
void load_cloud(parallax_t *parallax);
void load_mountain(parallax_t *parallax);
void load_trees(parallax_t *parallax);
void load_game_scene(parallax_t *parallax);
void display_game_trees(game_t *game, parallax_t *parallax);
void display_game_moutains(game_t *game, parallax_t *parallax);
void display_game_clouds(game_t *game, parallax_t *parallax);
void display_parallax(game_t *game, parallax_t *parallax);
void update_obstacle(game_t *game, parallax_t *parallax);
void load_game(intro_t *intro, music_t
*music, parallax_t *parallax, pause_t *pause, pnj_t *pnj);
void game_engine(game_t *game, intro_t *intro, pnj_t *pnj,
parallax_t *parallax, pause_t *pause, music_t *music);
void draw(game_t *game, parallax_t *parallax);
void draw_hitbox(game_t *game, pnj_t *pnj);
void draw_hitbox_obs(game_t *game, parallax_t *parallax);
void draw_run(game_t *game, pnj_t * pnj, parallax_t *parallax);
void draw_lives(game_t *game, pnj_t *pnj);
void animate_pnj(pnj_t *pnj, game_t *game);
void update(pnj_t *pnj, game_t *game, parallax_t *parallax);
void is_colliding(game_t  *game, pnj_t *pnj, parallax_t *parallax);
void display_layer1(game_t *game, intro_t *intro);
void display_layer2(game_t *game, intro_t *intro);
void display_layer3(game_t *game, intro_t *intro);
void display_layer4(game_t *game, intro_t *intro);
void display_layer4_2(game_t *game, intro_t *intro);
void display_logo(game_t *game, intro_t *intro);
void cleanup_gbg(parallax_t *parallax);
void cleanup_pnj(pnj_t *pnj);
void cleanup_menu(menu_t *menu);

#endif /* !MY_RUNNER_H_ */

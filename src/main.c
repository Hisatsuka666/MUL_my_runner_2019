/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main file for runner project
*/

#include "../include/my_runner.h"

void init(game_t *game, pnj_t *pnj, pause_t *pause, parallax_t *parallax)
{
    init_window(game);
    init_pnj_rect(pnj);
    init_hitbox(pnj);
    init_hitbox_obs(parallax);
}

void display_help(void)
{
    my_putstr("Hello ! You need help ?\n");
    my_putstr("Here are the instructions :\n");
    my_putstr("1) Once you have started the game, \
    wait for the intro to be finished.\n");
    my_putstr("2) When you are in the menu ('Runner' would be displayed) :\n");
    my_putstr("Press ENTER to play.\n");
    my_putstr("Press Q to quit.\n");
    my_putstr("3) While playing :\n");
    my_putstr("Press KEY UP to jump.\n");
    my_putstr("Press P to pause.\n");
    my_putstr("Press H to draw hitboxes or J to disable them\n");
    my_putstr("4) While in pause :\n");
    my_putstr("Press R to resume.\n");
    my_putstr("Press ESCAPE to return to menu.\n");
    my_putstr("You only have 3HP. When you hit a kunai, you loose 1HP\n");
    my_putstr("Everything is going faster, your goal is to \
    survive the longest time !\n");
    my_putstr("You can only quit on the menu.\n");
    my_putstr("HAVE FUN !\n");
}

int is_flag(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '-') {
            i++;
        }
        if (str[i] == 'h' || str[i] == 'H') {
            return (1);
        } else {
            my_putstr("'");
            my_putstr(str);
            my_putstr("'");
            my_putstr(" isn't an option, try '-h' for help\n");
            return (0);
        }
    }
}

int is_help(int ac, char **av)
{
    int help = 0;
    if (ac == 2) {
        help = is_flag(av[1]);
        if (help == 1) {
            display_help();
            return (1);
        } else {
            return (0);
        }
    } else {
        return (0);
    }
}

int main(int ac, char **av)
{
    game_t *game = malloc(sizeof(*game));
    parallax_t *parallax = malloc(sizeof(*parallax));
    pnj_t *pnj = malloc(sizeof(*pnj));
    pause_t *pause = malloc(sizeof(*pause));
    music_t *music = malloc(sizeof(*music));
    intro_t *intro = malloc(sizeof(*intro));
    init(game, pnj, pause, parallax);
    init_clock(intro, pnj, parallax);

    if (is_help(ac, av) == 1)
        return (0);
    create_window(game);
    load_game(intro, music, parallax, pause, pnj);
    sfMusic_play(music->music);
    sfMusic_setVolume(music->music, 5);
    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &game->Event)) {
            analyse_events(game, pnj);
        }
        sfRenderWindow_clear(game->window, sfBlack);
        game_engine(game, intro, pnj, parallax, pause, music);
        sfRenderWindow_display(game->window);
    }
    cleanup_pnj(pnj);
    sfMusic_destroy(music->music);
    sfRenderWindow_destroy(game->window);
    return (0);
}
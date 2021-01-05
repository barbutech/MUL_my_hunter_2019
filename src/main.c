/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** apprendre le CSFML
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my.h"
#include "structures.h"
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

int anime_my_sprite(superior_struct_t *main, int i, sfSprite *sprite)
{
    sfIntRect rect = (sfIntRect){i, 0, 72, 72};
    sfTime time = sfClock_getElapsedTime(main->clock);
    if (sfTime_asMilliseconds(time) > 130) {
        i = i + 72;
        sfClock_restart(main->clock);
    }
    if (i > 430)
        i = 0;
    sfSprite_setTextureRect(main->player->sprite, rect);
    sfRenderWindow_drawSprite(main->init->window, main->player->sprite, NULL);
    return (i);
}



int print_h(int ac, char **argv)
{
    char *verif = "-h";

    if (ac == 2 && my_strcmp(argv[1], verif) == 0) {
            my_putstr("for the map :\n");
            my_putstr("press 1 for a ground\n");
            my_putstr("press 2 for a box\n");
            my_putstr("press E for the end\n");
            my_putstr("press P for player\n");
            return (0);
    }
    return (1);
}

superior_struct_t *create_main()
{
    superior_struct_t *main = malloc(sizeof(superior_struct_t));
    main->the_sprite = print_ground();
    main->player = print_player();
    main->box = print_box();
    main->jump = 0;
    main->backgrnd = create_background();
    main->init = initialize_it();
    main->count = 0;
    main->column = 0;
    main->musics = set_music();
    main->clock = sfClock_create();
    return (main);
}

int loop(superior_struct_t *main, char *map)
{
    int i = 0;
    sfTime time = sfClock_getElapsedTime(main->clock);
    parallax(main);
    while (sfWindow_isOpen((sfWindow*)main->init->window)) {
        i = anime_my_sprite(main, i, main->player->sprite);
        if (print_map(map, main) == 1)
            return (1);
        sfRenderWindow_display(main->init->window);
        close_and_hitbox(&main);
    }
}

int main(int argc, char **argv)
{
    int fd = find_the_error(argc, argv[1]);

    if (fd == 84)
        return (84);
    if (print_h(argc, argv) == 0)
        return (0);
    superior_struct_t *main = create_main();
    char *map = copy_the_map(argv[1], fd);

    loop(main, map);
    sfSprite_destroy(main->the_sprite->sprite);
    sfSprite_destroy(main->backgrnd->background);
    sfClock_destroy(main->init->clock);
    sfMusic_destroy(main->musics->music);
    free(main);
    return (0);
}

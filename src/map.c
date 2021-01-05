/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** map.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my.h"
#include "structures.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

char *copy_the_map(char *file, int fd)
{
    struct stat size;
    char *map;
    char buffer[1];
    int count = 0;

    stat(file, &size);
    map = malloc(size.st_size + 1);
    read(fd, map, size.st_size);
    map[size.st_size] = '\0';
    return (map);
}

int find_the_error(int ac, char *filepath)
{
    int fd;
    char buff[1];
    if (ac != 2)
        return (84);
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (84);
    return (fd);
}

int update(superior_struct_t *main, char *map)
{
    static float player_x = 69;
    static float player_y = 351;
    int speed = 4;
    int column = 0;
    int line = 0;
    sfFloatRect player_hitbox = (sfFloatRect) {player_x, player_y - 14, 39, 72};

    for (int count = 0; map[count] != '\0'; count++) {
        if (map[count] == '\n') {
            column = column + 39;
            line = 0;
        }
        if (map[count] == 'P')
            line += 60;
        if (map[count] == '1') {
            sfFloatRect block_hitbox = (sfFloatRect) {(float) line, (float) column, 69, 39};
            if (main->jump == 0)
                if (sfFloatRect_intersects(&player_hitbox, &block_hitbox, NULL))
                player_y = column + 14 - 69;
        }
        if (map[count] == '2') {
            sfFloatRect obst_hitbox = (sfFloatRect) {(float) line, (float) column, 31, 32};
                if (sfFloatRect_intersects(&player_hitbox, &obst_hitbox, NULL))
                    return (1);
            line += -39;
        }
        if (map[count] == 'E') {
                sfFloatRect end_hitbox = (sfFloatRect) {(float) line, (float) column, 31, 32};
                if (sfFloatRect_intersects(&player_hitbox, &end_hitbox, NULL))
                    return (1);
        }
        line += 69;
    }
    player_x += speed;
    player_y += 4;
    if (main->jump != 0 && main->jump < 60) {
        player_y += - 6.5;
        main->jump++;
    }
    if (main->jump >= 39)
        main->jump = 0;
    sfSprite_setPosition(main->player->sprite, (sfVector2f) {69, player_y - 14});
}

int render(char *map, float turn, int line, superior_struct_t **main)
{
    if (map[(*main)->count] == '\n') {
        (*main)->column = (*main)->column + 39;
        line = 0;
        }
    if (map[(*main)->count] == '1') {
        sfSprite_setPosition((*main)->the_sprite->sprite, (sfVector2f){line - turn, (*main)->column});
        sfRenderWindow_drawSprite((*main)->init->window, ((*main)->the_sprite->sprite), NULL);
    }
    if (map[(*main)->count] == 'P')
        line = line + 60;
    if (map[(*main)->count] == '2') {
        sfSprite_setPosition((*main)->box->sprite, (sfVector2f){(float) line - turn, (float) (*main)->column + 18});
        sfRenderWindow_drawSprite((*main)->init->window, (*main)->box->sprite, NULL);
        line = line - 39;
    }
    line = line + 69;
    return (line);
}

int print_map(char *map, superior_struct_t *main)
{
    static int back3 = 0;
    int line = 0;
    static float turn = 0;
    main->column = 0;

    sfSprite_setPosition(main->back1->sprite, (sfVector2f){0, 0});
    sfSprite_setPosition(main->back2->sprite, (sfVector2f){0, 0});
    sfRenderWindow_drawSprite(main->init->window, main->back1->sprite, NULL);
    back3 = anime_back5(main, main->back2, back3);
    for (main->count = 0; map[main->count] != '\0'; main->count++)
        line = render(map, turn, line, &main);
    turn += 4;
    back3 += 2;
    if (back3 >= 1538)
    back3 = 0;
    if (update(main, map) == 1)
        return (1);
    sfRenderWindow_drawSprite(main->init->window, main->player->sprite, NULL);
    return (0);
}
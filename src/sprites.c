/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** sprites.c
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

int anime_back5(superior_struct_t *main, sprites_t *the_sprite, int i)
{
    sfIntRect rect = (sfIntRect){i, 0, 1538, 1538};
    if (i > 1538)
        i = 0;
    sfSprite_setTextureRect(the_sprite->sprite, rect);
    sfRenderWindow_drawSprite(main->init->window, the_sprite->sprite, NULL);
    return (i);
}

sprites_t *print_ground()
{
    sprites_t *the_sprite = malloc(sizeof(sprites_t));
    the_sprite->texture = sfTexture_createFromFile("grass_cleaned.png", NULL);
    the_sprite->sprite = sfSprite_create();
    sfSprite_setTexture(the_sprite->sprite, the_sprite->texture, sfTrue);
    return (the_sprite);
}

sprites_t *print_player()
{
    sprites_t *the_sprite = malloc(sizeof(sprites_t));
    the_sprite->texture = sfTexture_createFromFile("fma_armstrong.png", NULL);
    the_sprite->sprite = sfSprite_create();
    sfSprite_setTexture(the_sprite->sprite, the_sprite->texture, sfTrue);
    return (the_sprite);
}

sprites_t *print_box()
{
    sprites_t *the_sprite = malloc(sizeof(sprites_t));
    the_sprite->texture = sfTexture_createFromFile("box.png", NULL);
    the_sprite->sprite = sfSprite_create();
    sfSprite_setTexture(the_sprite->sprite, the_sprite->texture, sfTrue);
    return (the_sprite);
}

void parallax(superior_struct_t *main)
{
    main->back1 = create_backgr("back.jpg");
    main->back2 = create_backgr("back_5.png");
}
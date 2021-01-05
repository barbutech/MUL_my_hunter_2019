/*
** EPITECH PROJECT, 2019
** init
** File description:
** init of my_hunter
*/

#include "structures.h"
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

backgrounds_t *create_background()
{
    backgrounds_t *backgrnd = malloc(sizeof(backgrounds_t));
    backgrnd->backgr = sfTexture_createFromFile("forest.png", NULL);
    backgrnd->background = sfSprite_create();
    sfSprite_setTexture(backgrnd->background, backgrnd->backgr, sfTrue);
    sfSprite_scale(backgrnd->background, (sfVector2f){0.755, 0.9});
    return (backgrnd);
}

sprites_t *create_sprite(char *str, int line, int column)
{
    sprites_t *the_sprite = malloc(sizeof(sprites_t));
    the_sprite->texture = sfTexture_createFromFile(str, NULL);
    the_sprite->sprite = sfSprite_create();
    sfSprite_setPosition(the_sprite->sprite, (sfVector2f){line, column});
    sfSprite_setTexture(the_sprite->sprite, the_sprite->texture, sfTrue);
    return (the_sprite);
}

music_t *set_music()
{
    music_t *musics = malloc(sizeof(music_t));
    musics->music = sfMusic_createFromFile("fma_music.ogg");
    sfMusic_setLoop(musics->music, sfTrue);
    sfMusic_play(musics->music);
    return (musics);
}

init_t *initialize_it()
{
    init_t *init = malloc(sizeof(init_t));
    sfVideoMode mode = {1084, 780, 120};
    init->window = sfRenderWindow_create(mode, "My_runner", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(init->window, 60);

    init->clock = sfClock_create();
    return (init);
}

sprites_t *create_backgr(char *str)
{
    sprites_t *the_sprite = malloc(sizeof(sprites_t));
    the_sprite->texture = sfTexture_createFromFile(str, NULL);
    the_sprite->sprite = sfSprite_create();
    sfSprite_setTexture(the_sprite->sprite, the_sprite->texture, sfTrue);
    return (the_sprite);
}
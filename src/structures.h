/*
** EPITECH PROJECT, 2019
** structures
** File description:
** structures
*/

#ifndef sprites_h
#define sprites_h

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

struct sprites
{
    sfTexture *texture;
    sfSprite *sprite;
};
typedef struct sprites sprites_t;

struct backgrounds
{
    sfTexture *backgr;
    sfSprite *background;
};
typedef struct backgrounds backgrounds_t;

struct mousing
{
    sfTexture *mouse_text;
    sfSprite *mouse_curs;
};
typedef struct mousing mousing_t;
struct init
{
    sfRenderWindow *window;
    sfClock *clock;
};
typedef struct init init_t;

struct music
{
    sfMusic *music;
};
typedef struct music music_t;

struct superior_struct
{
    backgrounds_t *backgrnd;
    sprites_t *the_sprite;
    int jump;
    sprites_t *box;
    sprites_t *player;
    sprites_t *back1;
    sprites_t *back2;
    int count;
    int column;
    mousing_t cursor;
    init_t *init;
    music_t *musics;
    sfClock *clock;
};
typedef struct superior_struct superior_struct_t;
#endif

/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#include "../src/structures.h"
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

char *my_strcat(char *, char *);
char *copy_the_map(char *, int);
int find_the_error(int , char *);
sprites_t *print_ground(void);
sprites_t *print_player(void);
sprites_t *print_box(void);
void parallax(superior_struct_t *);
sprites_t *create_backgr(char *);
int ptr_function(char **, int , int, superior_struct_t *);
int print_ennemy(char **, int , int);
int print_map(char *, superior_struct_t *);
backgrounds_t *create_background();
int anime_back5(superior_struct_t *, sprites_t *, int);
mousing_t *the_mouse(mousing_t *, superior_struct_t *);
void close_and_hitbox(superior_struct_t **);
int out_of_the_screen(superior_struct_t *, mousing_t *);
int life_of_char(int , superior_struct_t *);
sprites_t *print_score(int , superior_struct_t *);
sprites_t *create_sprite(char *, int ,int);
int anime_my_sprite(superior_struct_t *, int, sfSprite *);
music_t *set_music();
init_t *initialize_it();
char *int_to_str(int, char *);
int my_strlen(char *);
int my_strcmp(char const *, char const *);
char *my_strdup(char *src);
char *my_revstr(char *str);
char *my_putstr(char *);
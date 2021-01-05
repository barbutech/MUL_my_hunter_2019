/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include "../include/my.h"

char *my_strdup(char *str)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    new_str[my_strlen(str) + 1] = '\0';
    int count = 0;

    for (; str[count] != '\0'; count++)
        new_str[count] = str[count];
    return (new_str);
}
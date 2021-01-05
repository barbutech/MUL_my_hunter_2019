/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenate 2 strings
*/

#include "../include/my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char *src)
{
    int i = my_strlen(dest);
    int j = my_strlen(src);
    char *tmp = malloc(sizeof(char) * i * j + 1);

    tmp[i + j + 1] = '\0';
    i = 0;
    while (dest[i] != '\0') {
        tmp[i] = dest[i];
        i++;
    }
    j = 0;
    while(src[j] != '\0') {
        tmp[i] = src[j];
        i++;
        j++;
    }
    return (tmp);
}

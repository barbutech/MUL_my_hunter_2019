/*
** EPITECH PROJECT, 2019
** int_to_str
** File description:
** int to str
*/

#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>

char *int_to_str(int score, char *str)
{
    char *score_str;
    int count = 1;
    int mem = 1;
    int end;

    while (score / count > 9) {
    count = count * 10;
    mem++;
    }
    score_str = malloc(sizeof(char) * mem);
    score_str[mem] = '\0';
    mem--;
    while (mem >= 0) {
        score_str[mem] = score / count + 48;
        score = score % count;
        count = count / 10;
        mem--;
    }
    score_str = my_revstr(my_strdup(score_str));
    str = my_strcat(str, score_str);
    end = my_strlen(str);
    str[end + 1] = '\0';
    return (str);
}
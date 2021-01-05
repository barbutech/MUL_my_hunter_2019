/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverse a string
*/

char *my_revstr(char *str)
{
    int i = 0;
    int b = 0;
    char c;

    while (str[i] != '\0')
        i++;
    i--;
    while (i >= b) {
        c = str[b];
        str[b] = str[i];
        str[i] = c;
        i = i - 1;
        b = b + 1;
    }
    return (str);
}

/*
** EPITECH PROJECT, 2020
** get.c
** File description:
** get source file
*/

#include "../include/lemin.h"

char *get_line(char *pos)
{
    pos = get_next_line(0);
    if (pos && is_skipper(pos) == 1)
        pos = get_line(pos);
    return pos;
}

int get_name(char *src, char *dest, char c)
{
    int i = 0;
    for (i = 0; src[i] != c; i++) {
        if (is_printable(src[i]) == -1)
            return 84;
        if (src[i] == '#')
            break;
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return 0;
}

int get_disp_line(char *src, char *dest)
{
    int i = 0;
    for (i = 0; src[i] != '\0'; i++) {
        if (is_printable(src[i]) == -1)
            return 84;
        if (src[i] == '#')
            break;
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return 0;
}
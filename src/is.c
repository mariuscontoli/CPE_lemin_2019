/*
** EPITECH PROJECT, 2020
** is.c
** File description:
** is... something source file
*/

#include "../include/lemin.h"

int is_printable(char c)
{
    if (c >= 32 && c <= 126) {
        return 0;
    } else {
        return -1;
    }
}

int is_start_and_end(lemin_t *lemin)
{
    if (lemin->int_start != 1 || lemin->int_end != 1) {
        return 84;
    }
    return 0;
}

int is_enough_spaces(char *pos)
{
    int spaces = 0;
    for (int i = 0; pos[i]; i++) {
        if (pos[i] == ' ')
            spaces += 1;
    }
    if (spaces < 2) {
        return 84;
    }
}

int is_room_tunnel(char *pos)
{
    for (int i = 0; pos[i]; i++) {
        if (pos[i] == '-')
            return 1;
    }
    return 0;
}

int is_skipper(char *pos)
{
    if (pos[0] == '#' && pos[1] != '#')
        return 1;
    if (pos[0] == '\0')
        return 1;
    return 0;
}
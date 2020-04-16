/*
** EPITECH PROJECT, 2020
** ants.c
** File description:
** ants source file
*/

#include "../include/lemin.h"

int is_line_numeric(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < 48 || str[i] > 57)
            return 84;
    }
    return 1;
}

int how_many_ants(lemin_t *lemin, char *pos)
{
    int number = 0;
    my_printf("#number_of_ants\n");
    if (is_line_numeric(pos) != 1)
        return 84;
    number = my_getnbr(pos);
    if (number != 0)
        lemin->ants = number;
    else
        return 84;
    lemin->map[lemin->i] = my_strdup(pos);
    my_printf("%s\n", lemin->map[lemin->i]);
    lemin->i += 1;
    return 0;
}
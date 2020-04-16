/*
** EPITECH PROJECT, 2020
** lemin.c
** File description:
** lemin source file
*/

#include "../include/lemin.h"

int parsing_file(lemin_t *lemin)
{
    char *pos = get_line(pos) ;
    if (pos == NULL)
        return 84;
    if (how_many_ants(lemin, pos) == 84)
        return 84;
    while (pos) {
        pos = get_line(pos);
        if (pos == NULL)
            break;
        if (check_if_start_end(lemin, pos) == 84)
            return 84;
        if (parsing_rooms(lemin, pos) == 84)
            return 84;
        lemin->i += 1;
    }
    lemin->map[lemin->i + 1] = '\0';
    if (is_start_and_end(lemin) == 84)
        return 84;
    return (0);
}

int main(int ac)
{
    lemin_t *lemin;

    if (ac > 1)
        return 84;
    lemin = malloc(sizeof(*lemin));
    init_lemin(lemin);
    if (parsing_file(lemin) == 84)
        return 84;
    return (0);
}
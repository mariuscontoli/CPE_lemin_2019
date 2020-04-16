/*
** EPITECH PROJECT, 2020
** check.c
** File description:
** check functions source file
*/

#include "../include/lemin.h"

int check_if_end(lemin_t *lemin, char *pos)
{
    if (my_strcmp(pos, "##end") == 0) {
        lemin->next_is_end = 1;
        lemin->int_end = 1;
        lemin->rooms += 1;
        lemin->map[lemin->i] = my_strdup(pos);
        if (lemin->print_room == 1) {
            my_printf("#rooms\n");
            lemin->print_room = 0;
        }
        my_printf("%s\n", lemin->map[lemin->i]);
        return 1;
    }
    if (lemin->next_is_end == 1) {
        lemin->end = pos;
        lemin->next_is_end = 0;
        if (lemin->end == NULL)
            return 84;
    }
    return 0;
}

int check_if_start(lemin_t *lemin, char *pos)
{
    if (my_strcmp(pos, "##start") == 0) {
        lemin->next_is_start = 1;
        lemin->int_start = 1;
        lemin->rooms += 1;
        lemin->map[lemin->i] = my_strdup(pos);
        if (lemin->print_room == 1) {
            my_printf("#rooms\n");
            lemin->print_room = 0;
        }
        my_printf("%s\n", lemin->map[lemin->i]);
        return 1;
    }
    if (lemin->next_is_start == 1) {
        lemin->start = pos;
        lemin->next_is_start = 0;
        if (lemin->start == NULL)
            return 84;
    }
    return 0;
}

int check_if_start_end(lemin_t *lemin, char *pos)
{
    if (check_if_start(lemin, pos) == 84) {
        return 84;
    }
    if (check_if_end(lemin, pos) == 84) {
        return 84;
    }
    return 0;
}
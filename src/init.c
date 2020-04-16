/*
** EPITECH PROJECT, 2020
** init.c
** File description:
** init source file
*/

#include "../include/lemin.h"

void init_lemin(lemin_t *lemin)
{
    lemin->ants = 0;
    lemin->i = 0;
    lemin->end = NULL;
    lemin->int_end = 0;
    lemin->int_start = 0;
    lemin->next_is_end = 0;
    lemin->next_is_start = 0;
    lemin->rooms = 0;
    lemin->start = NULL;
    lemin->tunnels = 0;
    lemin->map = malloc(sizeof(char *) * 1000);
    lemin->print_room = 1;
    lemin->print_tunnel = 1;
}
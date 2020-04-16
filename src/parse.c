/*
** EPITECH PROJECT, 2020
** parse.c
** File description:
** parsing source file
*/

#include "../include/lemin.h"

char *parse_tunnel(lemin_t *lemin, char *pos)
{
    char *name;
    char *name2;
    int size1, size2 = 0;
    size1 = my_strlen_tname(pos);
    size2 = my_strlen_tname2(pos, size1 + 1);
    name = malloc(sizeof(char) * size1 + 1);
    name2 = malloc(sizeof(char) * size2 + 1);
    if (get_name(pos, name, '-') == 84)
        return NULL;
    if (get_disp_line(pos, name2) == 84)
        return NULL;
    lemin->map[lemin->i] = my_strdup(name2);
    my_printf("%s\n", lemin->map[lemin->i]);
    lemin->tunnels += 1;
    return "good";
}

char *parse_room(lemin_t *lemin, char *pos)
{
    char *name;
    char *line;
    int size1, size2 = 0;
    size1 = my_strlen_name(pos);
    size2 = my_strlen(pos);
    name = malloc(sizeof(char) * size1 + 1);
    line = malloc(sizeof(char) * size2 + 1);
    if (get_name(pos, name, ' ') == 84)
        return NULL;
    if (get_disp_line(pos, line) == 84)
        return NULL;
    if (my_strlen(name) != 0) {
        lemin->map[lemin->i] = my_strdup(line);
        my_printf("%s\n", lemin->map[lemin->i]);
        lemin->rooms += 1;
    }
    return "good";
}

int what_room(lemin_t *lemin, char *pos)
{
    if (lemin->next_is_end == 1 || lemin->next_is_start == 1)
        return 0;
    if (is_room_tunnel(pos) == 1) {
        if (lemin->print_tunnel == 1) {
            my_printf("#tunnels\n");
            lemin->print_tunnel = 0;
        }
        if (parse_tunnel(lemin, pos) == NULL)
            return 84;
    } else {
        if (is_enough_spaces(pos) == 84)
            return 84;
        if (parse_room(lemin, pos) == NULL)
            return 84;
    }
    return 0;
}

int parsing_rooms(lemin_t *lemin, char *pos)
{
    if (what_room(lemin, pos) == 84) {
        return 84;
    }
    return 0;
}
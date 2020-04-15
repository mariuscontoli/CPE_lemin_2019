/*
** EPITECH PROJECT, 2020
** lemin.c
** File description:
** lemin source file
*/

#include "../include/lemin.h"

char *get_line(char *pos)
{
    pos = get_next_line(0);
    if (pos && skipper(pos) == 1)
        pos = get_line(pos);
    return pos;
}

int is_printable(char c)
{
    if (c >= 32 && c <= 126) {
        return 0;
    } else {
        return -1;
    }
}

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
    if (number != 0) {
        lemin->ants = number;
    } else {
        return 84;
    }
    lemin->map[lemin->i] = my_strdup(pos);
    my_printf("%s\n", lemin->map[lemin->i]);
    lemin->i += 1;
    return 0;
}

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

char *parse_room(lemin_t *lemin, char *pos)
{
    char *name;
    char *line;
    int size1, size2 = 0;
    size1 = my_strlen_name(pos);
    size2 = my_strlen(pos);
    name = malloc(sizeof(char) * size1 + 1);
    line = malloc(sizeof(char) * size2 + 1);
    if (is_enough_spaces(pos) == 84) {
        my_printf("NO ENOUGH SPACE on %s\n", pos);
        return NULL;
    }
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

int is_room_tunnel(char *pos)
{
    for (int i = 0; pos[i]; i++) {
        if (pos[i] == '-')
            return 1;
    }
    return 0;
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

int skipper(char *pos)
{
    if (pos[0] == '#' && pos[1] != '#')
        return 1;
    if (pos[0] == '\0')
        return 1;
    return 0;
}

int parsing_map(lemin_t *lemin)
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

void print_tunnels(lemin_t *lemin)
{
    int i = lemin->rooms + 1;
    int y = 0;
    
    for (; y != lemin->tunnels; y++) {
        my_printf("%s\n", lemin->map[i]);
        i++;
    }
}

int main(int ac)
{
    lemin_t *lemin;

    if (ac > 1)
        return 84;
    lemin = malloc(sizeof(*lemin));
    init_lemin(lemin);
    if (parsing_map(lemin) == 84)
        return 84;
    return (0);
}
/*
** EPITECH PROJECT, 2020
** lemin.h
** File description:
** lemin header
*/

#ifndef LEMIN_H_
#define LEMIN_H_

#define READ_SIZE (1)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../my_printf/include/my_printf.h"

typedef struct lemin
{
    char **map;
    char *start;
    char *end;
    int int_start;
    int int_end;
    int rooms;
    int tunnels;
    int ants;
    int next_is_start;
    int next_is_end;
    int i;
    int print_room;
} lemin_t;

char *get_next_line(const int fd);
char *get_line(char *pos);
int my_strlen(char const *str);
int my_strlen_name(char const *str);
int my_strlen_line(char const *str);
int my_strlen_tname(char const *str);
int my_strlen_tname2(char const *str, int start);
int get_name(char *src, char *dest, char c);
int get_disp_line(char *src, char *dest);
int my_atoi(char c);
int my_getnbr(char *str);
int my_strcmp(char const *s1, char const *s2);
int is_room_tunnel(char *pos);
int is_enough_spaces(char *pos);
int is_line_numeric(char *str);
int is_printable(char c);
int skipper(char *pos);
int how_many_ants(lemin_t *lemin, char *pos);
int what_room(lemin_t *lemin, char *pos);
int parsing_rooms(lemin_t *lemin, char *pos);
int is_start_and_end(lemin_t *lemin);
int check_if_start_end(lemin_t *lemin, char *pos);
int check_if_start(lemin_t *lemin, char *pos);
int check_if_end(lemin_t *lemin, char *pos);
int parsing_map(lemin_t *lemin);
char *my_strdup(char const *src);
char *parse_room(lemin_t *lemin, char *pos);
char *parse_tunnel(lemin_t *lemin, char *pos);

#endif /* !LEMIN_H_ */

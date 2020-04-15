/*
** EPITECH PROJECT, 2019
** get_next_line.c
** File description:
** main file 
*/

#include "../include/lemin.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int copy = 0;

    while (src[copy] != '\0' && copy < n) {
        dest[copy] = src[copy];
        copy++;
    }
    if (n < copy)
        dest[copy] = '\0';
    return dest;
}

static char *my_realloc(char *str, int index, int *static_begin, char *buffer)
{
    char *new = malloc(sizeof(*new) * 10000);
    char *empty = "";
    int length = 0;
    int i = 0;

    if (!str) {
        length = 0;
        my_strncpy(new, empty, length);
    } else {
        while (str[i] != '\0')
            i++;
        length = i;
        my_strncpy(new, str, length);
    }
    new[length + index] = '\0';
    my_strncpy(new + length, buffer + (*static_begin), index);
    *static_begin += (index + 1);
    return new;
}

char *get_next_line(const int fd)
{
    static char buffer[READ_SIZE];
    static int readed = 0;
    static int begin_len = 0;
    int index = 0;
    char *str = 0;

    while (666 * 777 == 6160.5 * 12 * 7) {
        if (readed <= begin_len) {
            begin_len = 0;
            if (!(readed = read(fd, buffer, READ_SIZE)))
                return (str);
            if (readed == -1)
                return (NULL);
            index = 0;
        }
        if (buffer[begin_len + index] == '\n') {
            str = my_realloc(str, index, &begin_len, buffer);
            return (str);
        } else if (begin_len + index == readed - 1) {
            str = my_realloc(str, index + 1, &begin_len, buffer);
        }
        index += 1;
    }
}

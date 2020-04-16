/*
** EPITECH PROJECT, 2020
** utils.c
** File description:
** utilitary source file
*/

#include "../include/lemin.h"

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int my_strlen_tname(char const *str)
{
    int i = 0;
    while(str[i] != '-') {
        i += 1;
    }
    return i;
}

int my_strlen_tname2(char const *str, int start)
{
    int i = 0;
    while(str[start] != '\0') {
        i += 1;
        start += 1;
    }
    return i;
}

int my_strlen_name(char const *str)
{
    int i = 0;
    while(str[i] != ' ') {
        i += 1;
    }
    return i;
}

int my_strlen_line(char const *str)
{
    int i = 0;
    while(str[i] != '#' || str[i] != '\0') {
        i += 1;
    }
    return i;
}
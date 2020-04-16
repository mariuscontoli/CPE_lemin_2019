/*
** EPITECH PROJECT, 2020
** utils2.c
** File description:
** second utilitary source file
*/

#include "../include/lemin.h"

int my_atoi(char c)
{
    int number;
    number = c - 48;
    return number;
}

int my_getnbr(char *str)
{
    int i = 0;
    int sign = 1;
    int	tmp = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    for (; str[i] != '\0'; ++i) {
        tmp = tmp * 10 + str[i] - '0';
    }
    return (tmp * sign);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    return s1[i] - s2[i];
}

char *my_strdup(char const *src)
{
    char *str;
    int copy = 0;
    str = malloc(10000);
    while (src[copy] != '\0') {
        str[copy] = src[copy];
        copy++;
    }
    str[copy] = '\0';
    return (str);
}
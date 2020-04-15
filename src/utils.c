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
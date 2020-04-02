/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** usefull
*/

#include "my.h"

void my_putchar(char r)
{
    write(1, &r, 1);
}

void my_putstr(char *str)
{
    int r = 0;

    while (str[r] != '\0') {
        my_putchar(str[r]);
        r++;
    }
}

size_t get_file_size(const char *filename)
{
    struct stat st;
    if (stat(filename, &st) != 0)
        return 0;
    return st.st_size;
}

int	my_getnbr(char *str)
{
    int i;
    int n;

    i = 0;
    n = 0;
    if (str[0] == '-' && str[1] != '\0')
        i++;
    while (str[i] != '\0') {
        if ((str[i] < '0' || str[i] > '9'))
            return -1;
    n = n + str[i] - 48;
    n = n * 10;
    i++;
    }
    n /= 10;
    if (str[0] == '-')
        return (-1 * n);
    else
        return (n);
}

void my_putnbr(int nb)
{
    int modulo;

    modulo = 0;
    if (nb <= 9 && nb >= 0)
        my_putchar(nb + '0');
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (- 1);
        if (nb <= 9 && nb >= 0)
        my_putnbr(nb);
    }
    if (nb > 9)
    {
        modulo = nb % 10;
        my_putnbr(nb / 10);
        my_putchar(modulo + '0');
    }
}
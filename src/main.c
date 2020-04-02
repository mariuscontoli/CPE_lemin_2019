/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main
*/

#include "my.h"

char *make_cleanfile(file_t *st)
{
    int only = 0;
    st = pre_set(st, "#number_of_ants", "#rooms");
    while (st->init_file[st->i] != '\0') {
        if (st->init_file[st->i] == '#' && st->init_file[st->i + 1] == '#') {
            st = no_comment(st);
        }
        if (st->init_file[st->i] == '#' && st->init_file[st->i + 1] != '#') {
            st = comment(st);
        }
        if (st->init_file[st->i] == '\n' && st->init_file[st->i + 2] == '-' &&
        only == 0) {
            st = set_room(st);
            only += 1;
        }
        st->new_file[st->j] = st->init_file[st->i];
        st->i++, st->j++;
    }
    st->new_file[st->j] = '\n';
    return st->new_file;
}

file_t *define_struct(char **av, char *file, char *new_file)
{
    file_t *st = malloc(sizeof(*st));
    st->i = 0;
    st->j = 0;
    st->init_file = file;
    st->new_file = new_file;
    return st;
}

int make_file(char **av)
{
    int fd = open(av[1], O_RDONLY), file_size;
    if (fd == -1)
        return 84;
    char *file = malloc(sizeof(char) * (get_file_size(av[1])));
    file_size = read(fd, file, get_file_size(av[1]));
    if (file_size == -1)
        return 84;
    char *new_file = malloc(sizeof(char) * (get_file_size(av[1]) + 1));
    file_t *st = define_struct(av, file, new_file);
    st->new_file = make_cleanfile(st);
    my_putstr(st->new_file);
    free(st);
    free(new_file);
    free(file);
}

int main(int ac, char **av)
{
    int back = 0;
    back = make_file(av);
    if (back == 64)
        return 84;
    return 0;
}
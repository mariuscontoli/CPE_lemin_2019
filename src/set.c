/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** pre_set
*/

#include "my.h"

file_t *pre_set(file_t *st, char *wyw, char *wyw2)
{
    int i = 0;
    while (wyw[i] != '\0') {
        st->new_file[st->j] = wyw[i];
        i++, st->j++; }
    i = 0;
    st->new_file[st->j] = '\n';
    st->j += 1;
    while (st->init_file[st->i] != '\n') {
        st->new_file[st->j] = st->init_file[st->i];
        st->i++, st->j++; }
    st->new_file[st->j] = '\n';
    st->j += 1;
    while (wyw2[i] != '\0') {
        st->new_file[st->j] = wyw2[i];
        i++, st->j++; }
    return st;
}

file_t *no_comment(file_t *st)
{
    while (st->init_file[st->i] != '\n') {
        st->new_file[st->j] = st->init_file[st->i];
        st->i++, st->j++;
    }
    return st;
}

file_t *comment(file_t *st)
{
    while (st->init_file[st->i] != '\n') st->i++;
    st->i += 1;
    return st;
}

file_t *set_room(file_t *st)
{
    char *str = "#tunnels";
    st->new_file[st->j] = '\n';
    st->j += 1;
    int i = 0;
    while (str[i] != '\0') {
        st->new_file[st->j] = str[i];
        i++, st->j++; }
    return st;
}
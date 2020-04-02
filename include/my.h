/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

size_t get_file_size(const char *filename);

typedef struct file_s {
    int i;
    int j;
    char *init_file;
    char *new_file;
} file_t;

file_t *pre_set(file_t *st, char *wyw, char *wyw2);
file_t *no_comment(file_t *st);
file_t *comment(file_t *st);
file_t *set_room(file_t *st);
void my_putstr(char *str);

#endif /* !MY_H_ */

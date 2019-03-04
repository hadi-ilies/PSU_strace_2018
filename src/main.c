/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** main.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "prototype.h"
#include "strace.h"

static bool isanum(const char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i]) != 0)
            return (false);
    }
    return (true);
}

static bool check_arg(int argc, char **argv, strace_t *strace)
{
    char flag;

    for (int i = 1; i < argc; i++) {
        if ((flag = getopt(argc, argv, "sp")) == '?')
            return (false);
        if ((i + 1 >= argc && flag == 'p') || (i + 1 >= argc && flag == 's'))
            return (false);
        if (flag == 'p' && isanum(argv[i + 1]) == false)
            return (false);
        if (flag == 'p')
            strace->mode = P_MODE;
        if (flag == 's')
            strace->mode = S_MODE;
    }
    return (true);
}

static int usage(int status)
{
    fprintf(stdout, "USAGE: ./strace [-s] [-p <pid>|<command>]\n");
    return (status);
}

int main(int argc, char **argv)
{
    strace_t strace;

    strace.mode = DEFAULT_MODE;
    if (argc < 2)
        return (usage(EXIT_ERROR));
    if (strcmp(argv[1], "--help") == 0)
        return (usage(EXIT_SUCCESS));
    if (check_arg(argc, argv, &strace) == false)
        return (usage(EXIT_ERROR));
    //get pid looking for the flag entred
    return (0);
}

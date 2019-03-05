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
#include <getopt.h>
#include <ctype.h>
#include <string.h>
#include "prototype.h"
#include "strace.h"

static bool isanum(const char *str)
{
    if (!str)
        return (false);
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

static bool check_arg(int argc, char **argv, strace_t *strace)
{
    char flag;

    while ((flag = getopt(argc, argv, "sp:")) != -1) {
        if (flag == '?')
            return (false);
        if (flag == 'p' && !isanum(optarg))
            return (false);
        if (flag == 'p') {
            strace->mode |= P_MODE;
            strace->pid = atoi(optarg);
        } if (flag == 's')
            strace->mode |= S_MODE;
    }
    strace->parms = argv + optind;
    return (true);
}

//if (mode & (S_MODE | D_MODE)) == both of the flags are present
//if (mode & S_MODE) // s flag present ...etc

static int usage(int status)
{
    fprintf(stdout, "USAGE: ./strace [-s] [-p <pid>|<command>]\n");
    return (status);
}

int main(int argc, char **argv)
{
    strace_t strace = {DEFAULT_MODE, 0, NULL};

    if (argc < 2)
        return (usage(EXIT_ERROR));
    if (strcmp(argv[1], "--help") == 0)
        return (usage(EXIT_SUCCESS));
    if (check_arg(argc, argv, &strace) == false)
        return (usage(EXIT_ERROR));
    get_pid_process(&strace);
    //get pid looking for the flag entred
    return (0);
}

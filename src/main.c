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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "prototype.h"
#include "strace.h"

static int usage(int status)
{
    fprintf(stdout, "USAGE\n" );
    fprintf(stdout, "\t./strace [-s] [-p <pid>|<command>]\n");
    fprintf(stdout, "OPTIONS\n");
    fprintf(stdout, "\t-s <command>\n");
    fprintf(stdout, "\t\tDisplay the detailled arguments. This option allow to display integers in decimal form, pointers on a character string in the form of a character string\n");
    fprintf(stdout, "\t-p <pid>\n");
    fprintf(stdout, "\t\tForce a specific PID instead of executing a command\n");
    fprintf(stdout, "\t-h, --help\n");
    fprintf(stdout, "\t\tDisplay the program usage\n");
    return status;
}

static bool isanum(const char *str)
{
    if (!str)
        return false;
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

static bool check_arg(int argc, char **argv, strace_t *strace)
{
    char flag;

    while ((flag = getopt(argc, argv, "sp:")) != -1) {
        if (flag == '?') {
            usage(EXIT_ERROR);
            return false;
        } if (flag == 'p' && !isanum(optarg)) {
            printf("./strace: Invalid process id: '%s'\n", optarg);
            return false;
        } if (flag == 'p') {
            strace->mode |= P_MODE;
            strace->pid = atoi(optarg);
        } if (flag == 's')
            strace->mode |= S_MODE;
    }
    strace->parms = argv + optind;
    return true;
}

int main(int argc, char **argv)
{
    strace_t strace = {DEFAULT_MODE, 0, NULL};

    if (argc < 2)
         usage(EXIT_ERROR);
    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
        return usage(EXIT_SUCCESS);
    if (check_arg(argc, argv, &strace) == false)
        return EXIT_ERROR;
    if (get_pid_process(&strace) == false)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

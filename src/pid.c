/*
** EPITECH PROJECT, 2019
** pid
** File description:
** pid
*/

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <getopt.h>
#include <errno.h>
#include <sys/types.h>
#include "strace.h"

static pid_t exec_param(char *exec)
{
    pid_t pid = fork();

    while (pid == -1 && errno == EAGAIN)
        pid = fork();
    if (pid == 0) {
        if (execvp(exec, &exec) == -1)
            exit(84);
    }
    return (pid);
}

pid_t *get_pid_process(strace_t *strace)
{
    if (strace->mode & P_MODE) {
        printf("%d\n", strace->pid);//call ptrace with the pid
    } else {
        for (size_t i = 0; strace->parms[i] != NULL; i++) {
            pid_t pid = exec_param(strace->parms[i]);
            printf("%d\n", pid);
        }
        //fork and exec receive pid
    }

    return (NULL);
}
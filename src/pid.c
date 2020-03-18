/*
** EPITECH PROJECT, 2019
** pid
** File description:
** pid
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <getopt.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include "strace.h"
#include "prototype.h"

static pid_t exec_param(char *exec, int *status)
{
    pid_t pid = fork();

    while (pid == -1 && errno == EAGAIN)
        exit(84);
    if (pid == 0) {
        if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
            exit(84);
        (void)execvp(exec, &exec);
        printf("./strace: No such file or directory\n");
        exit(84);
    } else {
        if (waitpid(pid, status, 0) == -1) {
            printf("waitpid funtion error\n");
            return false;
        }
        return pid;
    }
    return pid;
}

bool get_pid_process(strace_t *strace)
{
    if (strace->mode & P_MODE) {
        int status = 0;

        if (ptrace(PTRACE_ATTACH, strace->pid, NULL, NULL) == -1) {
            perror("./strace");
            return false;
        } if (waitpid(strace->pid, &status, 0) == -1) {
            printf("waitpid funtion error\n");
            return false;
        }
        exec_strace(strace, &status, strace->pid);
    } else {
        for (size_t i = 0; strace->parms[i] != NULL; i++) {
            int status = 0;
            pid_t pid = exec_param(strace->parms[i], &status);

            exec_strace(strace, &status, pid);
        }
    }
    return true;
}

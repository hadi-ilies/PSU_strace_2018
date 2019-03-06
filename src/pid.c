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
        pid = fork();
    if (pid == 0) {
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        (void)raise(SIGSTOP);
        (void)execvp(exec, &exec);
        //warn("execvp error");
        exit(84);
    } else {
        if (waitpid(pid, status, 0) == -1) {
            fprintf(stderr, "waitpid funtion error\n");
            return (false);
        }
        return (pid);
        //exec_strace(strace, pid);
        //waitpid(pid, &status, 0);
    }
    return (pid);
}

pid_t *get_pid_process(strace_t *strace)
{
    if (strace->mode & P_MODE) {
        int status = 0;

        if (ptrace(PTRACE_ATTACH, strace->pid, NULL, NULL) == -1)
            fprintf(stderr, "ptrace PTRACE_ATTACK\n");
        if (waitpid(strace->pid, &status, 0) == -1)
            fprintf(stderr, "waitpid funtion error\n");
        exec_strace(strace, &status, strace->pid);
    } else {
        //printf("WITHOUT P\n"); // when you remove that there is comflict with p mode
        for (size_t i = 0; strace->parms[i] != NULL; i++) {
            int status = 0;
            pid_t pid = exec_param(strace->parms[i], &status);

            exec_strace(strace, &status, pid);
        }
        //fork and exec receive pid
    }
    return (NULL);
}
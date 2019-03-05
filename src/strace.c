/*
** EPITECH PROJECT, 2019
** PSU_strace_2018
** File description:
** strace
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <err.h>
#include "strace.h"

static bool isasyscall(pid_t pid, struct user_regs_struct *rgt, long rip)
{
    rip &= 0xffff;
    if (rip == SYSCALL_OPCODE)
        return (true); // syscall corespondance in register
    return (false);
}

bool exec_strace(strace_t *strace, int status, pid_t pid)
{
    struct user_regs_struct registers;

    while (1) {
        ptrace(PTRACE_GETREGS, pid, NULL, &registers);
        long rip_pointed_data = ptrace(PTRACE_PEEKDATA, pid, registers.rip, NULL);

        if (isasyscall(pid, &registers, rip_pointed_data))
            printf("is a syscall : %ld\n", registers.rax);
        if (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1) {
            fprintf(stderr, "trace PTRACE_SINGLESTEP error\n");
            return (false);
        } if (waitpid(pid, &status, 0) == -1) {
            fprintf(stderr, "wait error\n");
            return (false);
        }
    }
    return (true);
}
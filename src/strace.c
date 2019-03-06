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
#include <string.h>
#include <sys/ptrace.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <err.h>
#include "strace.h"

static bool isasyscall(long rip)
{
    rip &= 0xffff;
    if (rip == SYSCALL_OPCODE)
        return (true); // syscall corespondance in register
    return (false);
}

static bool display_args(struct user_regs_struct *rgt)
{
    for (size_t i = 0; i < S_NB_PARMS; i++) {
        char *isapointer = index(syscalls_g[rgt->rax].params[i], '*');

        if ((isapointer != NULL && strcmp(isapointer, "*") == 0)
        || (isapointer != NULL && strcmp(isapointer, "**") == 0))
            i + 1 == S_NB_PARMS ? printf("%p", (void*) FIND_PARMS(i)) : printf("%p, ", (void*) FIND_PARMS(i));
        else {
            i + 1 == S_NB_PARMS ? printf("0x%llx", FIND_PARMS(i)) : (printf("0x%llx, ", FIND_PARMS(i)));
        }
    }
    printf(")");
    return (true);
}

static void display_ret(struct user_regs_struct *rgt)
{
    if (rgt->rax == __NR_exit || rgt->rax == __NR_pkey_free) {
        printf("= ?\n");
    } else {
        //if ((long)rgt->rax < 0)
        //    fprintf(stderr, "-1 (%s)", strerror(rgt->rax));
        //else {
            //if (strcmp(syscalls_g[rgt->rax].ret_type, "ssize_t") == 0)
            printf("= 0x%lx\n", (long) rgt->rax);
        //}
    }
}

/*rgt->rax is the id of the syscall*/

static void display_syscall(pid_t pid, int *status, struct user_regs_struct *rgt)
{
    //printf("is a syscall : %lld\n", rgt->rax);
    if (rgt->rax > NB_SYSCALLS) {
        fprintf(stderr, "UNKNOWN SYSCALL\n");
        exit(84);
    }
    printf("%s(", syscalls_g[rgt->rax].name);
    if (display_args(rgt) == false)
        exit(84);

    if (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1) {
        fprintf(stderr, "trace PTRACE_SINGLESTEP error\n");
    } if (waitpid(pid, status, 0) == -1) {
        fprintf(stderr, "wait error\n");
    }
    if (ptrace(PTRACE_GETREGS, pid, NULL, rgt) == -1) {
        fprintf(stderr, "trace PTRACE_GETREGS error\n");
        //return;
    }
    display_ret(rgt);
}

bool exec_strace(strace_t *strace, int *status, pid_t pid)
{
    (void) strace;
    struct user_regs_struct registers;

    while (1) {
        if (ptrace(PTRACE_GETREGS, pid, NULL, &registers) == -1) {
            fprintf(stderr, "trace PTRACE_GETREGS error\n");
            return (false);
        }
        long rip_pointed_data = ptrace(PTRACE_PEEKDATA, pid, registers.rip, NULL);

        if (isasyscall(rip_pointed_data) && registers.rax < NB_SYSCALLS) {
            display_syscall(pid, status, &registers);
        } if (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1) {
            fprintf(stderr, "trace PTRACE_SINGLESTEP error\n");
            return (false);
        } if (waitpid(pid, status, 0) == -1) {
            fprintf(stderr, "wait error\n");
            return (false);
        }
    }
    return (true);
}
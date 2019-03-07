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
#include "prototype.h"
#include "strace.h"

static bool isasyscall(long rip)
{
    rip &= 0xffff;
    if (rip == SYSCALL_OPCODE)
        return (true); // syscall corespondance in register
    return (false);
}

static bool display_args(strace_t *strace, struct user_regs_struct *rgt)
{
    if (strace->mode & S_MODE) {
        for (size_t i = 0; i < S_NB_PARMS; i++) {
            char *isapointer = strchr(syscalls_g[rgt->rax].params[i], '*');

            if (strcmp(syscalls_g[rgt->rax].params[i], "char *") == 0)
                display_types(strace, rgt, i);
            else if (IS_A_POINTER)
                display_pointer(rgt, i);
            else
                display_types(strace, rgt, i);
                //i + 1 == S_NB_PARMS ? printf("0x%llx", FIND_PARMS(i)) : (printf("0x%llx, ", FIND_PARMS(i)));
        }
        fprintf(stderr, ")");
    } else {
        for (size_t i = 0; i < S_NB_PARMS; i++)
            i + 1 == S_NB_PARMS ? fprintf(stderr, "0x%llx", FIND_PARMS(i)) : (fprintf(stderr, "0x%llx, ", FIND_PARMS(i)));
        fprintf(stderr, ")");
    }
    return (true);
}

static void display_ret(struct user_regs_struct *rgt)
{
    if (rgt->rax == __NR_exit_group || rgt->rax == __NR_exit || rgt->rax == __NR_pkey_free) {
        fprintf(stderr, " = ?\n");
    } else {
        fprintf(stderr, " = 0x%llx\n", rgt->rax);
    }
}

/*rgt->rax is the id of the syscall*/

static void display_syscall(strace_t *strace, pid_t pid, int *status, struct user_regs_struct *rgt)
{
    if (rgt->rax > NB_SYSCALLS) {
        fprintf(stderr, "UNKNOWN SYSCALL\n");
        exit(84);
    }
    fprintf(stderr, "%s(", syscalls_g[rgt->rax].name);
    if (display_args(strace, rgt) == false)
        return;
    if (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1) {
        return;
    } if (waitpid(pid, status, 0) == -1) {
        return;
    }
    ptrace(PTRACE_GETREGS, pid, NULL, rgt);
    display_ret(rgt);
}

bool exec_strace(strace_t *strace, int *status, pid_t pid)
{
    strace->pid = pid;
    struct user_regs_struct registers;

    while (1) {
        if (ptrace(PTRACE_GETREGS, pid, NULL, &registers) == -1) {
            //fprintf(stderr, "trace PTRACE_GETREGS error\n");
            return (false);
        }
        long rip_pointed_data = ptrace(PTRACE_PEEKDATA, pid, registers.rip, NULL);

        if (isasyscall(rip_pointed_data) && registers.rax < NB_SYSCALLS) {
            display_syscall(strace, pid, status, &registers);
        } if (WIFEXITED(*status) || WIFSIGNALED(*status)) {
            (void)printf("+++ exited with %d +++\n", WEXITSTATUS(*status));
            exit(EXIT_SUCCESS);
        } if (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1) {
            fprintf(stderr, "trace PTRACE_SINGLESTEP error\n");
            return (false);
        } if (waitpid(pid, status, 0) == -1) {
            fprintf(stderr, "wait error\n");
            return (false);
        }
    }
    //WEXITSTATUS(status);
    return (true);
}
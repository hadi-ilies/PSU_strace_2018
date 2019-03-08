/*
** EPITECH PROJECT, 2019
** PSU_strace_2018
** File description:
** display_args
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/ptrace.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <err.h>
#include <ctype.h>
#include "strace.h"

void display_char(struct user_regs_struct *rgt, size_t i)
{
    char c = (char) FIND_PARMS(i);

    if (IS_PRINTABLE(c))
        i + 1 == S_NB_PARMS ? printf("%c", c) : printf("%c, ", c);
    else
        i + 1 == S_NB_PARMS ? printf("\\%o", c) : printf("\\%o, ", c);
}

void display_string(strace_t *strace, struct user_regs_struct *rgt, size_t i)
{
    long  c = -1;
    unsigned long long int register_value = FIND_PARMS(i);

    (void)printf("\"");
    for (size_t j = 0; (char)c != '\0' && j < 42; j++, register_value++) {
        if ((c = ptrace(PTRACE_PEEKDATA, strace->pid,
                        register_value, NULL)) == -1) {
            printf("\033[36mptrace PTRACE_PEEK_DATA error: ");
            printf("%s\033[33m\"", strerror(errno));
            return;
        }
        char ch = (char) c;

        if (isprint(ch) || ch == '\t')
            printf("%c", ch);
    }
    i + 1 == S_NB_PARMS ? (void)printf("\"") : (void)printf("\", ");
}

void display_int(struct user_regs_struct *rgt, size_t i)
{
    int param = (int) FIND_PARMS(i);

    i + 1 == S_NB_PARMS ? printf("%d", param) : printf("%d, ", param);
}

void display_long(struct user_regs_struct *rgt, size_t i)
{
    long param = (long) FIND_PARMS(i);

    i + 1 == S_NB_PARMS ? printf("%ld", param) : printf("%ld, ", param);
}
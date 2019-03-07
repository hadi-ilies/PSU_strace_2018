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
        i + 1 == S_NB_PARMS ? fprintf(stderr, "%c", c) : fprintf(stderr, "%c, ", c);
    else
        i + 1 == S_NB_PARMS ? fprintf(stderr, "\\%o", c) : fprintf(stderr, "\\%o, ", c);
}

void display_string(strace_t *strace, struct user_regs_struct *rgt, size_t i)
{
    long  c = -1;
    unsigned long long int register_value = FIND_PARMS(i);

    (void)fprintf(stderr, "\"");
    for (size_t j = 0; (char)c != '\0' && j < 42; j++, register_value++) {
        if ((c = ptrace(PTRACE_PEEKDATA, strace->pid,
                        register_value, NULL)) == -1) {
            fprintf(stderr, "\033[36mptrace PTRACE_PEEK_DATA error: ");
            fprintf(stderr, "%s\033[33m\"", strerror(errno));
            return;
        }
        char ch = (char) c;

        if (ch == '\t')
            fprintf(stderr, "\\t");
        if (isprint(ch))
            fprintf(stderr, "%c", ch);
       // else
       //     fprintf(stderr, "\\%o", ch);
    }
    i + 1 == S_NB_PARMS ? (void)fprintf(stderr, "\"") : (void)fprintf(stderr, "\", ");
}

void display_int(struct user_regs_struct *rgt, size_t i)
{
    int param = (int) FIND_PARMS(i);

    i + 1 == S_NB_PARMS ? fprintf(stderr, "%d", param) : fprintf(stderr, "%d, ", param);
}

void display_long(struct user_regs_struct *rgt, size_t i)
{
    long param = (long) FIND_PARMS(i);

    i + 1 == S_NB_PARMS ? fprintf(stderr, "%ld", param) : fprintf(stderr, "%ld, ", param);
}

void display_uint(struct user_regs_struct *rgt, size_t i)
{
    unsigned int param = (unsigned int) FIND_PARMS(i);

    i + 1 == S_NB_PARMS ? fprintf(stderr, "%u", param) : fprintf(stderr, "%u, ", param);
}

void display_ulong(struct user_regs_struct *rgt, size_t i)
{
    unsigned long param = (unsigned long) FIND_PARMS(i);

    i + 1 == S_NB_PARMS ? fprintf(stderr, "%lu", param) : fprintf(stderr, "%lu, ", param);
}

void display_pointer(struct user_regs_struct *rgt, size_t i)
{
    void* param = (void*) FIND_PARMS(i);

    if (param == NULL)
        i + 1 == S_NB_PARMS ? fprintf(stderr, "NULL") : fprintf(stderr, "NULL, ");
    else
        i + 1 == S_NB_PARMS ? fprintf(stderr, "%p", param) : fprintf(stderr, "%p, ", param);
}

void display_unimplemented(struct user_regs_struct *rgt, size_t i)
{
    ;
}

void display_nothing(struct user_regs_struct *rgt, size_t i)
{
    ;
}


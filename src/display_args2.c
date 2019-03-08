/*
** EPITECH PROJECT, 2019
** OTTO
** File description:
** TOTO
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

void display_uint(struct user_regs_struct *rgt, size_t i)
{
    unsigned int param = (unsigned int) FIND_PARMS(i);

    i + 1 == S_NB_PARMS ? printf("%u", param) : printf("%u, ", param);
}

void display_ulong(struct user_regs_struct *rgt, size_t i)
{
    unsigned long param = (unsigned long) FIND_PARMS(i);

    i + 1 == S_NB_PARMS ? printf("%lu", param) : printf("%lu, ", param);
}

void display_pointer(struct user_regs_struct *rgt, size_t i)
{
    void *param = (void*) FIND_PARMS(i);

    if (param == NULL)
        i + 1 == S_NB_PARMS ? printf("NULL") : printf("NULL, ");
    else
        i + 1 == S_NB_PARMS ? printf("%p", param) : printf("%p, ", param);
}

void display_unimplemented(struct user_regs_struct *rgt, size_t i)
{
    (void) rgt, (void) i;
}

void display_nothing(struct user_regs_struct *rgt, size_t i)
{
    (void) rgt, (void) i;
}

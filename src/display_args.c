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
#include <sys/ptrace.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <err.h>
#include "strace.h"


void display_pointer(struct user_regs_struct *rgt, size_t i)
{
    void* param = (void*) FIND_PARMS(i);

    if (param == NULL)
        i + 1 == S_NB_PARMS ? printf("NULL") : printf("NULL, ");
    else
        i + 1 == S_NB_PARMS ? printf("%p", param) : printf("%p, ", param);
}
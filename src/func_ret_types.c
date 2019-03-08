/*
** EPITECH PROJECT, 2019
** PSU_strace_2018
** File description:
** func_ret_types
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

void ret_display_char(unsigned long long int value)
{
    if (IS_PRINTABLE((char) value))
        printf("%c\n", (char) value);
}

void ret_display_string(unsigned long long int value)
{
    printf("%s\n", (char *) value);
}

void ret_display_int(unsigned long long int value)
{
    printf("%d\n", (int) value);
}

void ret_display_long(unsigned long long int value)
{
    printf("%ld\n", (long) value);
}

void ret_display_uint(unsigned long long int value)
{
    printf("%u\n", (unsigned int) value);
}

void ret_display_ulong(unsigned long long int value)
{
    printf("%lu\n", (unsigned long) value);
}

void ret_display_pointer(unsigned long long int value)
{
    printf("%p\n", (void *) value);
}

void ret_display_unimplemented(unsigned long long int value)
{
    (void) value;
}

void ret_display_nothing(unsigned long long int value)
{
    (void) value;
}
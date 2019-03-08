/*
** func_ret_types2.c for PSU_strace_2018 in /Users/hadibereksi/
**
** Made by test
** Login   <>
**
** Started on  Fri Mar 8 6:12:22 PM 2019 test
** Last update Fri Mar 8 6:12:22 PM 2019 test
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
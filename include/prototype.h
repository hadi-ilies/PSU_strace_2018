/*
** EPITECH PROJECT, 2019
** for_norme
** File description:
** prototype.h
*/

#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/user.h>
#include "strace.h"

pid_t *get_pid_process(strace_t *strace);
bool exec_strace(strace_t *strace, int *status, pid_t pid);
void display_pointer(struct user_regs_struct *rgt, size_t i);
void display_types(struct user_regs_struct *rgt, size_t i);

#endif

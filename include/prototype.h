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

bool get_pid_process(strace_t *strace);
bool exec_strace(strace_t *strace, int *status, pid_t pid);
void display_pointer(struct user_regs_struct *rgt, size_t i);
void display_types(strace_t *strace, struct user_regs_struct *rgt, size_t i);
void display_int(struct user_regs_struct *rgt, size_t i);
void display_uint(struct user_regs_struct *rgt, size_t i);
void display_long(struct user_regs_struct *rgt, size_t i);
void display_ulong(struct user_regs_struct *rgt, size_t i);
void display_string(strace_t *strace, struct user_regs_struct *rgt, size_t i);
void display_unimplemented(struct user_regs_struct *rgt, size_t i);
void display_nothing(struct user_regs_struct *rgt, size_t i);

void display_ret_type(unsigned long long int value, char *type);
void ret_display_char(unsigned long long int value);
void ret_display_string(unsigned long long int value);
void ret_display_int(unsigned long long int value);
void ret_display_long(unsigned long long int value);
void ret_display_uint(unsigned long long int value);
void ret_display_ulong(unsigned long long int value);
void ret_display_pointer(unsigned long long int value);
void ret_display_unimplemented(unsigned long long int value);
void ret_display_nothing(unsigned long long int value);

#endif

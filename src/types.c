/*
** EPITECH PROJECT, 2019
** PSU_strace_2018
** File description:
** types
*/

#include <string.h>
#include "strace.h"
#include "prototype.h"

void display_types(struct user_regs_struct *rgt, size_t i) {

    if (strcmp(syscalls_g[rgt->rax].params[i], "char") == 0)
        display_char(rgt, i);
    //if (strcmp(syscalls_g[rgt->rax].params[i], "char *") == 0)
     //   ;
    //if (strcmp(syscalls_g[rgt->rax].params[i], "char **") == 0)
     //   ;
    if (strcmp(syscalls_g[rgt->rax].params[i], "int") == 0)
        display_int(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "int[2]") == 0)
        display_pointer(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "uint32_t") == 0)
        display_uint(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "unsigned int") == 0)
        display_uint(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "long") == 0)
        display_long(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "unsigned long") == 0)
        display_ulong(rgt, i);;
    if (strcmp(syscalls_g[rgt->rax].params[i], "u64") == 0)
        display_ulong(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "size_t") == 0)
        display_ulong(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "ssize_t") == 0)
        display_long(rgt, i);
    //if (strcmp(syscalls_g[rgt->rax].params[i], "caddr_t") == 0)
     //   ;
    if (strcmp(syscalls_g[rgt->rax].params[i], "ndfs_t") == 0)
        display_int(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "off_t") == 0)
        display_ulong(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "key_t") == 0)
        display_ulong(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "pid_t") == 0)
        display_int(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "socklen_t") == 0)
        display_ulong(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "uid_t") == 0)
        display_int(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "gid_t") == 0)
        display_int(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "gid_t[]") == 0)
        display_pointer(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "clock_t") == 0)
        display_ulong(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "cap_user_header_t") == 0)
        display_pointer(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "cap_huser_data_t") == 0)
        display_pointer(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "dev_t") == 0)
        display_ulong(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "off64_t") == 0)
        display_ulong(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "cpu_set_t") == 0)
        display_ulong(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "aio_context_t") == 0)
        display_ulong(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "mqd_t") == 0)
        display_int(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "idtype_t") == 0)
        display_ulong(rgt, i);
    if (strcmp(syscalls_g[rgt->rax].params[i], "key_serial_t") == 0)
        display_long(rgt, i);
    //if (strcmp(syscalls_g[rgt->rax].params[i], "unimplemented") == 0)
     //   ;
    if (strcmp(syscalls_g[rgt->rax].params[i], "default") == 0)
        display_pointer(rgt, i);
}
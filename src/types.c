/*
** EPITECH PROJECT, 2019
** PSU_strace_2018
** File description:
** types
*/

#include <string.h>
#include "strace.h"
#include "prototype.h"

const types_t types_g[] =
    {
        {"void", &display_nothing},
        {"int", &display_int},
        {"int[2]", &display_pointer},
        {"uint32_t", &display_uint},
        {"unsigned int", &display_uint},
        {"long", &display_long},
        {"unsigned long", &display_ulong},
        {"u64", &display_ulong},
        {"size_t", &display_ulong},
        {"ssize_t", &display_long},
        {"ndfs_t", &display_int},
        {"off_t", &display_ulong},
        {"key_t", &display_ulong},
        {"pid_t", &display_int},
        {"socklen_t", &display_ulong},
        {"uid_t", &display_int},
        {"gid_t", &display_int},
        {"gid_t[]", &display_pointer},
        {"clock_t", &display_ulong},
        {"cap_user_header_t", &display_pointer},
        {"cap_huser_data_t", &display_pointer},
        {"dev_t", &display_ulong},
        {"off64_t", &display_ulong},
        {"cpu_set_t", &display_ulong},
        {"aio_context_t", &display_ulong},
        {"mqd_t", &display_int},
        {"idtype_t", &display_ulong},
        {"key_serial_t", &display_ulong},
        {"unimplemented", &display_unimplemented},
        {"default", &display_pointer},
        {NULL, NULL}
    };

void display_types(strace_t *strace, struct user_regs_struct *rgt, size_t i)
{
    if (strcmp(syscalls_g[rgt->rax].params[i], "char *") == 0)
        display_string(strace, rgt, i);
    for (size_t j = 0; types_g[j].type != NULL; j++) {
        if (strcmp(types_g[j].type, syscalls_g[rgt->rax].params[i]) == 0)
            types_g[j].display_types(rgt, i);
    }
}
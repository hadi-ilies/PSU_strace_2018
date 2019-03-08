/*
** EPITECH PROJECT, 2019
** PSU_strace_2018
** File description:
** ret_types
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "strace.h"
#include "prototype.h"

static const ret_types_t ret_types_g[] =
{
    {"void", &ret_display_nothing},
    {"int", &ret_display_int},
    {"int[2]", &ret_display_pointer},
    {"uint32_t", &ret_display_uint},
    {"unsigned int", &ret_display_uint},
    {"long", &ret_display_long},
    {"unsigned long", &ret_display_ulong},
    {"u64", &ret_display_ulong},
    {"size_t", &ret_display_ulong},
    {"ssize_t", &ret_display_long},
    {"caddr_t", &ret_display_string},
    {"ndfs_t", &ret_display_int},
    {"off_t", &ret_display_ulong},
    {"key_t", &ret_display_ulong},
    {"pid_t", &ret_display_int},
    {"socklen_t", &ret_display_ulong},
    {"uid_t", &ret_display_int},
    {"gid_t", &ret_display_int},
    {"gid_t[]", &ret_display_pointer},
    {"clock_t", &ret_display_ulong},
    {"cap_user_header_t", &ret_display_pointer},
    {"cap_huser_data_t", &ret_display_pointer},
    {"dev_t", &ret_display_ulong},
    {"off64_t", &ret_display_ulong},
    {"cpu_set_t", &ret_display_ulong},
    {"aio_context_t", &ret_display_ulong},
    {"mqd_t", &ret_display_int},
    {"idtype_t", &ret_display_ulong},
    {"key_serial_t", &ret_display_ulong},
    {"unimplemented", &ret_display_unimplemented},
    {"default", &ret_display_pointer},
    {NULL, NULL}
};


void display_ret_type(unsigned long long int value, char *type)
{
    char *is_pointer = strchr(type, '*');

    if (is_pointer != NULL && (strcmp(is_pointer, "*") == 0
    || strcmp(strchr(is_pointer, '*'), "**") == 0)
    && (strcmp(type, "char *") && strcmp(type, "char **"))) {
        ret_display_pointer(value);
        return;
    } for (size_t i = 0; ret_types_g[i].ret_type != NULL; i++) {
        if (strcmp(ret_types_g[i].ret_type, type) == 0)
            ret_types_g[i].display_ret_types(value);
    }
}

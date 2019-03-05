/*
** EPITECH PROJECT, 2019
** strace
** File description:
** strace
*/

#ifndef STRACE_H_
#define STRACE_H_

#include <sys/types.h>
#include <unistd.h>
#define EXIT_ERROR 84
#define SYSCALL_OPCODE 0x050f

typedef enum {
    DEFAULT_MODE = 0b00, //0 in binaire
    P_MODE = 0b01,
    S_MODE = 0b10
} MODE;

typedef struct {
    MODE mode;
    pid_t pid;
    char **parms;
} strace_t;

typedef struct	s_prototype
{
  char *name;
  int nb_params;
  char *params[6];
  char *ret_type;
} t_prototype;

#endif /* !STRACE_H_ */

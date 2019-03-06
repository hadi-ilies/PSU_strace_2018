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
#define NB_SYSCALLS 331
#define URS_START rgt->r15
#define FIND_PARMS(i) (unsigned long long int) *(&URS_START + (parms_g[i]))
#define S_NB_PARMS syscalls_g[rgt->rax].nb_params

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
  size_t nb_params;
  char *params[6];
  char *ret_type;
} prototype_t;

extern const prototype_t syscalls_g[];
extern const int parms_g[];

#endif /* !STRACE_H_ */

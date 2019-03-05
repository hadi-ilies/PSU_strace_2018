/*
** EPITECH PROJECT, 2019
** strace
** File description:
** strace
*/

#ifndef STRACE_H_
#define STRACE_H_

#define EXIT_ERROR 84

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

#endif /* !STRACE_H_ */

/*
** EPITECH PROJECT, 2019
** strace
** File description:
** strace
*/

#ifndef STRACE_H_
#define STRACE_H_

#define EXIT_ERROR 84

typedef enum {DEFAULT_MODE, P_MODE, S_MODE} MODE;

typedef struct {
    MODE mode;

} strace_t;

#endif /* !STRACE_H_ */

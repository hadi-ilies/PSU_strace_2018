##
## EPITECH PROJECT, 2019
## for_norme
## File description:
## Makefile
##

NAME		=	strace

CC		=	gcc

SRCDIR		=	src/
INCDIR		=	include/

SRC		=	$(SRCDIR)main.c \
			$(SRCDIR)pid.c \
			$(SRCDIR)strace.c \
			$(SRCDIR)syscalls.c \
			$(SRCDIR)display_args.c \
			$(SRCDIR)types.c \
			$(SRCDIR)ret_types.c \
			$(SRCDIR)func_ret_types.c \
			$(SRCDIR)display_args2.c \
			$(SRCDIR)func_ret_types2.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra -Werror
CFLAGS		+=	-I $(INCDIR)

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			@$(CC) -o $(NAME) $(OBJ)

clean		:
			@rm -f $(OBJ)

fclean		:	clean
			@rm -f $(NAME)

re		:	fclean all

debug		:	CFLAGS += -g3
debug		:	re

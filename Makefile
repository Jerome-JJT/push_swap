SRCS_DIR	= ./
SRCS_FILES	= main.c verify.c utils.c utils2.c basic_stack.c advanced_stack.c expert_stack.c sort_functions.c big_sort_functions.c
SRCS		= ${patsubst %, ${SRCS_DIR}%, ${SRCS_FILES}}

BONUS_DIR	= ./
BONUS_FILES	= checker.c verify.c get_next_line.c get_next_line_utils.c utils.c utils2.c basic_stack.c advanced_stack.c expert_stack.c
BONUS		= ${patsubst %, ${BONUS_DIR}%, ${BONUS_FILES}}

LIBFT		= ./libft
MAKELIB		= ${MAKE} -C ${LIBFT}

HEADS		= ./ -I./libft/

OBJS		= ${SRCS:.c=.o}
OBJSB		= ${BONUS:.c=.o}

NAME		= push_swap
NAMEB		= checker

CC			= gcc
AR			= ar rcs
CP			= cp -f
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${HEADS}

${NAME}:	${OBJS}
			${MAKELIB} all
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -I${HEADS} -L./libft/ -lft

bonus:		${OBJSB}
			${MAKELIB} all
			${CC} ${CFLAGS} -o ${NAMEB} ${OBJSB} -I${HEADS} -L./libft/ -lft

clean:
			${RM} ${OBJS} ${OBJSB}
			${MAKELIB} clean

fclean:		clean
			${RM} ${NAME} ${NAMEB}
			${MAKELIB} fclean

re:			fclean all

.PHONY:		all clean fclean re


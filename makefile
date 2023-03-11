SHELL	= /bin/sh

NAME	= push_swap

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g3

LIBFT_DIR = ./libft

LFLAGS	= -L${LIBFT_DIR} -lft

IDIR	= .
IFLAGS	= -I${IDIR} -I${LIBFT_DIR}

SRCS	= operations.c utils.c parser.c sort.c group_sort.c move_cost.c ps_utils.c
MSRCS	= main.c
BSRCS	= checker.c

RM		= rm -f

.PHONY: all clean fclean re bonus ${CHECKER}

${NAME}: ${MSRCS} ${SRCS}
		@make -C ${LIBFT_DIR}
		${CC} ${CFLAGS} ${MSRCS} ${SRCS} ${IFLAGS} ${LFLAGS} -o ${NAME}

${CHECKER}: ${SRCS} ${BSRCS}
		@make -C ${LIBFT_DIR}
		${CC} ${CFLAGS} ${BSRCS} ${SRCS} ${IFLAGS} ${LFLAGS} -o ${CHECKER}

all: ${NAME}

bonus: all ${CHECKER}

clean:
		@${RM} ${NAME} ${CHECKER}
		@make clean -C ${LIBFT_DIR}

fclean: clean
		@make fclean -C ${LIBFT_DIR}

re: fclean all

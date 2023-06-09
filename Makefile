

SRCS	= push_swap.c opers.c sort.c utils.c
NAME	= push_swap
CC	= cc -g
FLAGS	= -Wall -Werror -Wextra
RM	= rm -f
INCS	= libft/libft.a

all: ${NAME}

${NAME}: runlibft 
	${CC} ${FLAGS} -o ${NAME} ${SRCS} ${INCS}

ignore: runlibft
	${CC} ${FLAGS} -o ${NAME} ${SRCS} ${INCS}

clean:
	${RM} ${NAME}

fclean: clean
	make -C libft fclean

re: fclean all

runlibft:
	make -C libft

.PHONY: all re clean fclean
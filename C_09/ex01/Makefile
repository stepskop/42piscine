SRC 	= ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c ./srcs/ft_swap.c

OBJ 	= ${SRC:.c=.o}

HEADERS = ./includes/

CFLAGS	= -Wall -Wextra -Werror

CC		= cc

AR		= ar rcs

NAME	= libft.a

.c.o:		
	${CC} ${CFLAGS} -c -I ${HEADERS} $< -o ${<:.c=.o}

${NAME}:	${OBJ}
	${AR} ${NAME} ${OBJ}

all:	${NAME} 

clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

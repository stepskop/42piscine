NAME = do-op

SRC = ft_atoi.c ft_putnbr.c main.c

OBJ = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Werror -Wextra

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
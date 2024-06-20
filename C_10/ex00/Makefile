NAME = ft_display_file

CC = cc

CFLAGS = -Wall -Werror -Wextra

.c.o:
	${CC} ${CFLAGS} -c main.c -o main.o

${NAME}: main.o
	${CC} ${CFLAGS} main.c -o ${NAME}

all: ${NAME}

clean:
	rm -f main.o

fclean:	clean
	rm -f ${NAME}

re: fclean all
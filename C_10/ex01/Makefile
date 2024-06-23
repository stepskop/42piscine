SRC = srcs/main.c srcs/read_file.c srcs/no_file.c srcs/ft_putstro.c

OBJ = ${SRC:.c=.o}

CCF = cc -Wall -Werror -Wextra

NAME = ft_cat

INCLUDES = ./includes/

.c.o:
	${CCF} -c -I ${INCLUDES} $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${CCF} ${OBJ} -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
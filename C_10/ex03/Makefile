SRC = srcs/main.c srcs/print.c srcs/helpers.c srcs/ft_putstro.c srcs/ft_strlen.c srcs/ft_str_is_printable.c srcs/ft_strcmp.c srcs/read.c srcs/ft_strcat.c

OBJ = ${SRC:.c=.o}

CCF = cc -Wall -Werror -Wextra

NAME = ft_hexdump

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
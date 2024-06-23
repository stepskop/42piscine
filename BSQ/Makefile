SRC = ./srcs/main.c ./srcs/parse_map.c ./srcs/ft_is_printable.c ./srcs/ft_putstro.c ./srcs/ft_strlen.c

OBJ = ${SRC:.c=.o}

INCLUDES = ./includes/

CCLAGS = cc -Wall -Werror -Wextra

NAME = bsq

.c.o:
	${CCLAGS} -c -I ${INCLUDES} $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${CCLAGS} ${OBJ} -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
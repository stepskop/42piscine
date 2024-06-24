SRC_PARSE = ./srcs/parse/parse_map.c ./srcs/parse/read.c ./srcs/parse/validate.c ./srcs/parse/helpers.c

SRC_PRINT = ./srcs/print/print.c

SRC_GENERAL = ./srcs/general/ft_is_printable.c ./srcs/general/ft_strlen.c ./srcs/general/ft_putstro.c ./srcs/general/ft_freefield.c

SRC_SOLVE = ./srcs/solve/solve.c

SRC = ./srcs/main.c ${SRC_GENERAL} ${SRC_PARSE} ${SRC_PRINT} ${SRC_SOLVE}

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
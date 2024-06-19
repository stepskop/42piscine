#!/bin/bash
rm -f libft.a
find . -name "*.c" -type f -exec cc -c -Wall -Werror -Wextra {} \;
ar rc libft.a *.o
find . -name "*.o" -type f -delete
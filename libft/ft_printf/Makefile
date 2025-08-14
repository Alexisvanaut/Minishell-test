NAME = libftprintf.a

CFILES := format.c\
	input_handling.c\
	input_helpers.c\
	format_functions.c\
	print_loop.c

OBJS := $(CFILES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb

LIBFT_DIR = ..

LIBFT_AR := ${LIBFT_DIR}/libft.a

all: ${NAME}

${NAME}:  ${OBJS}
	cd ${LIBFT_DIR} && make bonus
	cp ${LIBFT_AR} ${NAME}
	ar rs ${NAME} ${OBJS}

%.o: %.c
	${CC} -I${LIBFT_DIR} -c ${CFLAGS} $< -o $@ -fPIE

clean:
	rm -f ${OBJS}
	cd ${LIBFT_DIR} && make $@

fclean: clean
	rm -f ${NAME}
	cd ${LIBFT_DIR} && make $@

re: fclean all

.PHONY: fclean clean all re bonus

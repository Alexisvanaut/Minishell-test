NAME = libft.a

CFILES = ft_atoi.c\
	ft_atod.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_itoa.c\
	ft_uitoa.c\
	ft_ultoa_16.c\
	ft_itoa_16.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_putchar_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_putstr_fd.c\
	ft_split.c\
	ft_strchr.c\
	ft_strdup.c\
	ft_striteri.c\
	ft_strjoin.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strmapi.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strtrim.c\
	ft_substr.c\
	ft_tolower.c\
	ft_toupper.c\
	get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c\
	ft_printf/format.c\
	ft_printf/format_functions.c\
	ft_printf/input_handling.c\
	ft_printf/input_helpers.c\
	ft_printf/print_loop.c
	

BONUS = ft_lstadd_back_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstmap_bonus.c\
	ft_lstnew_bonus.c\
	ft_lstsize_bonus.c\

OBJS := $(CFILES:.c=.o)

BONUS_OBJS := $(BONUS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -O3

all: ${NAME}

bonus: $(NAME) $(BONUS_OBJS)
	ar rcs libft.a ${BONUS_OBJS}

${NAME}:  ${OBJS}
	ar rcs libft.a ${OBJS}

%.o: %.c
	${CC} -c ${CFLAGS} $< -o $@

clean:
	rm -f ${OBJS}
	rm -f ${BONUS_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: fclean clean all re bonus

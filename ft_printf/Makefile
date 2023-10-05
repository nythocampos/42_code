NAME 	= libftprintf.a
CC 		= cc
LIB 	= ar rcs
CFLAGS 	= -Wall -Wextra -Werror #-g3 -fsanitize=address
INCLUDE = libftprintf.h
SRCS 	= ft_printf.c ft_putstr_fd.c ft_strdup.c ft_strlen.c tools.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(LIB) $(NAME) $(OBJS)

%.o: %.c ${INCLUDE} Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

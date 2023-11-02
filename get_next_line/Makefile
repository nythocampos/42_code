NAME		= get_next_line
CC			= cc
LIB			= ar rcs
CFLAGS	= -Wall -Wextra -Werror #-g3 -fsanitize=address
SRCS		= get_next_line.c get_next_line_utils.c
INCLUDE	= get_next_line.h

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
				@$(LIB) $(NAME) $(OBJS)

%.o: %.c ${INCLUDE} Makefile
				@$(CC) $(CFLAGS) -c $< -o $@

clean:
				@rm -rf $(OBJS)

fclean:	clean
				@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

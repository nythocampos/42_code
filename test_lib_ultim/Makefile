NAME	= libft_tester
LIBFT 	= ./libft_ulti/libft.a
LIBFTDIR= libft_ulti/
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= test_ft_printf.c
# program files
OBJS 	= $(SRCS:.c=.o)

all: makelib $(NAME)

makelib:
	@echo "COMPILING LIBFT LIBRARY"
	@make -C $(LIBFTDIR)

$(NAME): $(OBJS) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	cc test_ft_printf.c $(NAME) -o libft_teter1

%.o: %.c Makefile $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFTDIR) clean
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re

	



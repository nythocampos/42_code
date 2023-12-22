LIBFTNAME = libft.a
LIBFT 	= ./libft_ulti/libft.a
LIBFTDIR= libft_ulti/
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= test_ft_printf.c
# program files
OBJS 	= $(SRCS:.c=.o)

all: makelib build

makelib:
	@echo "---->COMPILING LIBFT LIBRARY..."
	@make -C $(LIBFTDIR)
	@echo "---->LIBFT LIBRARY COMPLIED."

build: $(OBJS) $(LIBFT)
	@echo "---->BUILDING PROGRAM..."
	@cp $(LIBFT) $(LIBFTNAME)
	@cc test_ft_printf.c $(LIBFTNAME) -o libft_tester
	@echo "---->PROGRAM BUILD."


%.o: %.c Makefile $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIBFTDIR) clean
	@rm -f $(OBJS)
	@echo "---->OBJECTS CLEANED."
	
fclean: clean
	@rm -f $(LIBFT)
	@echo "---->ALL CLEANED."
	
re: fclean all

.PHONY: all clean fclean re

	



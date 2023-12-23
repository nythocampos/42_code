PROGRAM = program.c
CC		= cc
# basic compilation flags
# -I mlx = ?
CFLAGS	= -Wall -Wextra -Werror -Imlx
# minilibx flags to link with the required internal macOS API
# -L mlx = ?
# -l mlx = ?
# -framework = ?
# -OpenGL = ?
# -AppKit = ?
MFLAGS	= -L mlx -l mlx -framework OpenGL -framework AppKit
SRCS	= minilibx_tests.c
# program files
OBJS 	= $(SRCS:.c=.o)

build: $(OBJS)
	@echo "---->BUILDING PROGRAM..."
	@cc tests.c $(MFLAGS) -o $(PROGRAM)
	@echo "---->PROGRAM BUILD."


%.o: %.c Makefile $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "---->OBJECTS CLEANED."

fclean: clean
	@rm -f $(PROGRAM)
	@echo "---->ALL CLEANED."

re: fclean all

.PHONY: all clean fclean re

# Minilibx variables
MINILIBX		= ./libraries/mlx/libmlx.a
MINILIBXDIR		= libraries/mlx/
MINFLAGS		= -framework OpenGL -framework AppKit

# Libft_ulti variables
LIBFT			= ./libraries/libft_ulti/libft.a
LIBFTDIR		= libraries/libft_ulti/

# Program variables
PROGRAM			= fdf
LIBS			= $(LIBFT) $(MINILIBX)
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
SRCS			= fdf.c

#!TO FIX OBJS
OBJS 			= $(SRCS:.c=.o)


# Rules
all: makelib build

# TODO: fix relink

makelib:
	@echo "---->COMPILING LIBRARIES..."
	@make -C $(LIBFTDIR)
	@cp $(LIBFT) ./
	@echo "---->LIBFT LIBRARY COMPLIED."
	@make -C $(MINILIBXDIR)
	@cp $(MINILIBX) ./
	@echo "---->LIBFT LIBRARY COMPILED."
	@echo "---->MINILIBX LIBRARY COMPILED."

build: $(OBJS) $(LIBFT) $(MINILIBX)
	@echo "---->BUILDING PROGRAM..."
	@cc fdf.c $(LIBS) $(MINFLAGS) -o $(PROGRAM)
	@echo "---->PROGRAM BUILD."


%.o: %.c Makefile $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIBFTDIR) clean
	@make -C $(MINILIBXDIR) clean
	@rm -f $(OBJS)
	@echo "---->OBJECTS CLEANED."
	
fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(MINILIBX)
	@rm -f $(PROGRAM)
	@echo "---->ALL CLEANED."
	
re: fclean all

.PHONY: all clean fclean re

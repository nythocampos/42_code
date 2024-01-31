# Minilibx variables
MINILIBX		= ./libraries/mlx/libmlx.a
MINILIBXDIR		= libraries/mlx/
ifeq ($(shell uname -s), Linux)
	#MINILIBX	= ./libraries/mlx_linux/libmlx.a
	#MINILIBXDIR	= libraries/mlx_linux/
	MINFLAGS	= -lXext -lX11 -lm -lz
endif
ifeq ($(shell uname -s), Darwin)	
	MINFLAGS	= -framework OpenGL -framework AppKit
endif
# Libft_ulti variables
LIBFT			= ./libraries/libft_ulti/libft.a
LIBFTDIR		= libraries/libft_ulti/

# Program variables
PROGRAM			= fdf
LIBS			= $(LIBFT) $(MINILIBX)
CC				= cc
# IMPLEMENT FLAGS!!!!!
CFLAGS			= -Wall -Wextra -Werror -g

# C FILES ---------
# Frame builder section
FRA_SRC			= frame_builder.c
# Models manager section
#MODLS_SRC		= models_manager.c fdf_format_loader.c
# Window manager section
WIN_SRC			= window_manager.c hooks.c events_manager.c

GEN_SRC			= fdf.c #util.c

SRCS			= $(GEN_SRC) $(FRA_SRC) $(MODLS_SRC) $(WIN_SRC)
# -----------------

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

build: $(LIBFT) $(MINILIBX)
	@echo "---->BUILDING PROGRAM..."
	@cc $(CFLAGS) $(SRCS) $(LIBS) $(MINFLAGS) -o $(PROGRAM)
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

# Minilibx variables
MINILIBX		= ./libraries/mlx/libmlx.a
MINILIBXDIR		= libraries/mlx/
ifeq ($(shell uname -s), Linux)
	MINILIBX	= ./libraries/mlx_linux/libmlx.a
	MINILIBXDIR	= libraries/mlx_linux/
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
CC			= cc
# IMPLEMENT FLAGS!!!!!
CFLAGS			= -Wall -Wextra -Werror -g
INCLUDE			= fdf.h structs.h

# C FILES ---------
# Image builder section
GRPDIR			= ./src/graphic_module/
GRAPHIC_MODULE		= $(GRPDIR)img_builder.c
# Models manager section
FLSDIR			=./src/files_module/
FILES_MODULE		= $(FLSDIR)models_manager.c $(FLSDIR)fdf_format_loader.c $(FLSDIR)fdf_format_utils.c
# Window manager section
WINDIR			= ./src/window_module/
WINDOW_MODULE		= $(WINDIR)window_manager.c $(WINDIR)hooks.c $(WINDIR)events_manager.c
# Utils
UTLDIR			= ./src/utils/
UTILS			= $(UTLDIR)calculates.c #util.c

SRCS			= fdf.c $(UTILS) $(WINDOW_MODULE) $(FILES_MODULE) \
			  $(GRAPHIC_MODULE)
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


%.o: %.c $(INCLUDE) Makefile $(LIBFT)
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

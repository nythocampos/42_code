NAME 	= libft.a
CC 		= cc
LIB 	= ar rcs
CFLAGS 	= -Wall -Wextra -Werror #-g3 -fsanitize=address
INCLUDE = libft.h
# libft files
SRC_LIBFT	= ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
 	ft_bzero.c ft_memcpy.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcat.c \
 	ft_strlcpy.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_memmove.c
# get_next_line files
SRC_GNL = get_next_line.c get_next_line_utils.c
# ft_printf files
SRC_PRN = ft_printf.c numbers_writer.c pointers_writer.c writers_selector.c
# libft bonus files
SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ftdflstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS_LIBFT = $(SRC_LIBFT:.c=.o)
OBJS_GNL = $(SRC_GNL:.c=.o)
OBJS_PRN = $(SRC_PRN:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_BONUS) $(OBJS_LIBFT) $(OBJS_GNL) $(OBJS_PRN)
	@$(LIB) $(NAME) $(OBJS_BONUS) $(OBJS_LIBFT) $(OBJS_GNL) $(OBJS_PRN)

%.o: %.c ${INCLUDE} Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_BONUS) $(OBJS_LIBFT) $(OBJS_GNL) $(OBJS_PRN)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

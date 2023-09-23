NAME 	= libft.a
CC 		= cc
LIB 	= ar rcs
CFLAGS 	= -Wall -Wextra -Werror #-g3 -fsanitize=address
INCLUDE = libft.h
SRCS 	= ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
 	ft_bzero.c ft_memcpy.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcat.c \
 	ft_strlcpy.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c

TEMP = temp/

OBJS = ${addprefix ${TEMP}, $(SRCS:.c=.o)}

all: temp $(NAME)

temp:
	@mkdir -p ${TEMP}
	@echo "Temp directory created."

$(NAME): $(OBJS)
	@$(LIB) $(NAME) $(OBJS)

$(TEMP)%.o: %.c ${INCLUDE} Makefile
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "Compiling" $< ...

clean:
	@rm -rf $(TEMP)

fclean: clean
	@rm -f $(NAME) $(TEMP)

re: fclean all
.PHONY: all clean fclean

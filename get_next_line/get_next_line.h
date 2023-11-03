#ifndef GET_NEXT_LINE
#define	GET_NEXT_LINE

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#include <unistd.h>
#include <stdlib.h>
# include <string.h>


char	  *get_next_line(int fd);
char    *mod_strjoin(char const *s1, char const *s2);
void    *ft_memcpy(void *dst, const void *src, size_t n);
size_t  ft_strlen(const char *s);
//void    ft_bzero(void *s, size_t n);
char    *ft_strdup(const char *s);
char    *ft_strchr(const char *s, int c);


#endif

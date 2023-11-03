#include "get_next_line.h"

char    *ft_strdup(const char *s)
{
  char  *str;
  int   index;

  str = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
  if (str == 0)
    return (0);
  index = 0;
  while (s[index] != '\0')
  {
    str[index] = s[index];
    index++;
  }
  str[index] = '\0';
  return (str);
}


void    ft_bzero(void *s, size_t n)
{
  int   index;
  char  *a;

  index = 0;
  a = (char *) s;
  while (n != 0)
  {
    a[index] = 0;
    index++;
    n--;
  }
}

size_t  ft_strlen(const char *s)
{
  int     index;

  index = 0;
  while (s[index] != '\0')
    index++;
  return (index);
}

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
  int             index;
  char    *a;

  index = 0;
  a = (char *) dst;
  if (dst == (void *) '\0' && src == (void *) '\0')
    return (dst);
  while (n != 0)
  {
    a[index] = *(char *)src;
    n--;
    index++;
    src++;
  }
  dst = a;
  return (dst);
}

char  *mod_strjoin(char const *s1, char const *s2)
{
  size_t          str_size;
  char            *str;
  
  if (s2 == 0)
    return (NULL);
  str_size = ft_strlen(s1) + ft_strlen(s2);
  str = (char *)malloc((str_size + 1) * sizeof(char));
  if (!str)
    return (NULL);
  ft_bzero(str, str_size);
  if (str == 0)
    return (NULL);
  if (s1[0] != 0)
    ft_memcpy(str, (const char *)s1, ft_strlen(s1));
  if (s2[0] != 0)
    ft_memcpy(&str[ft_strlen(s1)], (const char *)s2, ft_strlen(s2));
  free((char *)(s1));
  return (str);
}

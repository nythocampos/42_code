#include "get_next_line.h"

void    ft_bzero(void *s, size_t n)
{
        int             index;
        char    *a;

        index = 0;
        a = (char *) s;
        while (n != 0)
        {
                a[index] = 0;
                index++;
                n--;
        }
}


void    *ft_calloc(size_t nmemb, size_t size)
{
        void    *result;

        result = malloc(nmemb * size);
        if (!result)
                return (0);
        ft_bzero(result, nmemb * size);
        return (result);
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


char    *ft_strjoin(char const *s1, char const *s2)
{
  size_t          str_size;
  char            *str;

  if (s1 == 0 || s2 == 0)
          return (0);
  if ((ft_strlen(s1) <= 0 && ft_strlen(s2) <= 0))
          return ((char *)ft_calloc(1, sizeof(char)));
  str_size = ft_strlen(s1) + ft_strlen(s2);
  str = (char *)ft_calloc(str_size + 1, sizeof(char));
  if (str == 0)
          return (0);
  if (s1[0] != 0)
          ft_memcpy(str, (const char *)s1, ft_strlen(s1));
  if (s2[0] != 0)
          ft_memcpy(&str[ft_strlen(s1)], (const char *)s2, ft_strlen(s2));
  return (str);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:06:48 by antcampo          #+#    #+#             */
/*   Updated: 2023/11/14 09:00:56 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *args, ...);
void		select_writer(char type, va_list valist, int *len);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		count_nums(int num);

int		ft_putchar(char c, int *total_len);
int		ft_putstr(char *s, int *total_len);
int		ft_putnbr(int n, int *total_len);
int		ft_putunbr(unsigned int n, int *total_len);
int		ft_puthex(long long num, char *hex, int *total_len);
int		ft_putptr(void *ptr, int *total_len);

#endif

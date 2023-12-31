/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:06:48 by antcampo          #+#    #+#             */
/*   Updated: 2023/11/17 07:57:59 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *args, ...);
void	select_writer(char type, va_list valist, int *len);
size_t	ft_strlen(const char *s);

void	ft_putchar(char c, int *total_len);
void	ft_putstr(char *s, int *total_len);
void	ft_putnbr(int n, int *total_len);
void	ft_putunbr(unsigned int n, int *total_len);
void	ft_puthex(unsigned long long num, char *hex, int *total_len);
void	ft_putptr(unsigned long long ptr, int *total_len);

#endif

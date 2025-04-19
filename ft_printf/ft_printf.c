/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:15:56 by alortiz-          #+#    #+#             */
/*   Updated: 2025/01/17 10:16:01 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putall(va_list va, char *str, size_t *count)
{
	if (*str == 'c')
		ft_putc(va_arg(va, int), count);
	else if (*str == 's')
		ft_puts(va_arg(va, char *), count);
	else if (*str == 'p')
		ft_putp(va_arg(va, void *), count);
	else if (*str == 'i' || *str == 'd')
		ft_putid(va_arg(va, int), count);
	else if (*str == 'u')
		ft_putu(va_arg(va, unsigned int), count);
	else if (*str == 'x')
		ft_puthex(va_arg(va, unsigned int), count, "0123456789abcdef");
	else if (*str == 'X')
		ft_puthex(va_arg(va, unsigned int), count, "0123456789ABCDEF");
	else if (*str == '%')
		ft_putc(*str, count);
}

int	ft_printf(char const *str, ...)
{
	va_list	print;
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	va_start(print, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_putall(print, (char *)str, &count);
		}
		else
			ft_putc(*str, &count);
		str++;
	}
	va_end(print);
	return (count);
}

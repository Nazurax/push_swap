/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:17:40 by alortiz-          #+#    #+#             */
/*   Updated: 2025/01/17 10:17:45 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putp(void *ptr, size_t *count)
{
	unsigned long long	ptr2;
	char				*str;

	if (!ptr)
	{
		ft_puts("(nil)", count);
		return ;
	}
	ptr2 = (unsigned long long)ptr;
	ft_puts("0x", count);
	str = ft_utoa_base(ptr2, "0123456789abcdef");
	if (str)
	{
		ft_puts(str, count);
		free(str);
	}
}

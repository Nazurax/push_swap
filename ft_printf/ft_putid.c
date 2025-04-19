/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:17:23 by alortiz-          #+#    #+#             */
/*   Updated: 2025/01/17 10:17:27 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putid(int nb, size_t *count)
{
	if (nb == -2147483648)
	{
		ft_puts("-2147483648", count);
		return ;
	}
	if (nb < 0)
	{
		ft_putc('-', count);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putid(nb / 10, count);
		ft_putc((nb % 10 + '0'), count);
	}
	else
		ft_putc((nb + '0'), count);
}

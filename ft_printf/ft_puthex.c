/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:17:09 by alortiz-          #+#    #+#             */
/*   Updated: 2025/01/17 10:17:14 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int num, size_t *count, char *base)
{
	char	*str;

	str = ft_utoa_base(num, base);
	if (str)
	{
		ft_puts(str, count);
		free(str);
	}
}

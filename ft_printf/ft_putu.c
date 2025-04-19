/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:18:27 by alortiz-          #+#    #+#             */
/*   Updated: 2025/01/17 10:18:31 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putu(unsigned int num, size_t *count)
{
	char	*str;

	str = ft_utoa(num);
	if (str)
	{
		ft_puts(str, count);
		free(str);
	}
}

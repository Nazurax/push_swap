/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:18:43 by alortiz-          #+#    #+#             */
/*   Updated: 2025/01/17 10:18:47 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa(unsigned int num)
{
	char			*str;
	size_t			len;
	unsigned int	temp;

	len = 0;
	temp = num;
	if (num == 0)
		return (ft_handlezero());
	while (temp)
	{
		temp /= 10;
		len++;
	}
	str = calloc_p(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len)
	{
		--len;
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

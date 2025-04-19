/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:19:00 by alortiz-          #+#    #+#             */
/*   Updated: 2025/01/17 10:19:04 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa_base(unsigned long long num, char *base)
{
	char				*str;
	size_t				len;
	unsigned long long	temp;
	size_t				base_len;

	len = 0;
	temp = num;
	base_len = 16;
	if (num == 0)
		return (ft_handlezero());
	while (temp)
	{
		temp /= base_len;
		len++;
	}
	str = calloc_p(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (len > 0)
	{
		--len;
		str[len] = base[num % base_len];
		num /= base_len;
	}
	return (str);
}

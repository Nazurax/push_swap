/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:14:47 by alortiz-          #+#    #+#             */
/*   Updated: 2025/01/17 10:14:54 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*calloc_p(size_t num, size_t size)
{
	char	*str;

	str = (char *)malloc(num * size);
	if (!str)
		return (NULL);
	bzero_p(str, num * size);
	return (str);
}

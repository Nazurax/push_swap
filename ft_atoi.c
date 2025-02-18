/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:00:31 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/17 17:00:35 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atoi(const char *str, int *error)
{
    int i = 0;
    int sign = 1;
    long num = 0;

    *error = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    if (str[i] < '0' || str[i] > '9') // Verifica que haya al menos un número
    {
        *error = 1;
        return (0);
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + (str[i] - '0');
        if ((num > 2147483647 && sign == 1) || (num > 2147483648 && sign == -1))
        {
            *error = 1;
            return (0);
        }
        i++;
    }
    if (str[i] != '\0') // Verifica que no haya caracteres extra después del número
    {
        *error = 1;
        return (0);
    }
    return ((int)(num * sign));
}


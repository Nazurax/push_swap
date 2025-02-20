/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:55:16 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/20 12:55:11 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función auxiliar para obtener la posición de un valor
int get_position(t_stack *stack, int value)
{
    int pos = 0;
    while (stack)
    {
        if (stack->value == value)
            return pos;
        pos++;
        stack = stack->next;
    }
    return -1;
}

int get_min_value(t_stack *stack)
{
    int min;
    t_stack *current;

    if (!stack)
        return (0);
    min = stack->value;
    current = stack->next;
    while (current)
    {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    return (min);
}

int ft_atoi(const char *str, int *error)
{
    long long   result;
    int         sign;
    int         i;

    result = 0;
    sign = 1;
    i = 0;

    // Manejar espacios iniciales
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;

    // Manejar signo
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }

    // Convertir dígitos
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        // Verificar overflow
        if ((sign == 1 && result > INT_MAX) || 
            (sign == -1 && result * sign < INT_MIN))
        {
            *error = 1;
            return (0);
        }
        i++;
    }

    // Verificar caracteres inválidos después del número
    if (str[i] != '\0')
    {
        *error = 1;
        return (0);
    }

    return ((int)(result * sign));
}

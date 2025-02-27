/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:55:16 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/17 18:55:18 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// Función auxiliar para obtener el número de bits necesarios
int get_max_bits(t_stack *stack)
{
    int max;
    int bits;

    max = get_max_value(stack);
    bits = 0;
    while (max > 0)
    {
        bits++;
        max >>= 1;
    }
    return (bits);
}

// Función para obtener el valor máximo en la pila
int get_max_value(t_stack *stack)
{
    int max;
    t_stack *current;

    if (!stack)
        return (0);
    max = stack->value;
    current = stack->next;
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return (max);
}

int is_valid_number(char *str)
{
    int i;
    int has_digits;

    i = 0;
    has_digits = 0;

    // Manejar el signo
    if (str[i] == '-' || str[i] == '+')
        i++;

    // Verificar que haya al menos un dígito y que todos sean dígitos
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        has_digits = 1;
        i++;
    }

    return (has_digits);
}

int is_duplicate(t_stack *stack, int num)
{
    t_stack *tmp = stack;

    while (tmp)
    {
        if (tmp->value == num)
            return 1;  // Encontrado un duplicado
        tmp = tmp->next;
    }
    return 0;  // No hay duplicados
}


int push_back(t_stack **a, int value)
{
    t_stack *new_node;
    t_stack *last;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
        return (0);
    new_node->value = value;
    new_node->next = NULL;
    if (*a == NULL)
    {
        *a = new_node;
    }
    else
    {
        last = *a;
        while (last->next)
            last = last->next;
        last->next = new_node;
    }
    return (1);
}

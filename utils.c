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
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;  // Saltar el signo

    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;  // No es un número válido
        i++;
    }
    return 1;  // Es un número válido
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


void push_back(t_stack **a, int value)
{
    t_stack *new_node;
    t_stack *last;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
        return;  // Manejo de error en caso de fallo de malloc
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
}

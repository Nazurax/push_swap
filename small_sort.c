/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_short.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:01:32 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/15 12:06:51 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función auxiliar para mover el máximo número al top
void move_max_to_top(t_stack **stack)
{
    int max = get_max_value(*stack);
    int pos = get_position(*stack, max);
    int size = stack_size(*stack);

    if (pos <= size / 2)
        while ((*stack)->value != max)
            rb(stack);
    else
        while ((*stack)->value != max)
            rrb(stack);
}

void move_min_to_top(t_stack **a)
{
    t_stack *current;
    int min;
    int pos;
    int min_pos;
    int size;

    current = *a;
    min = current->value;
    pos = 0;
    min_pos = 0;
    while (current)
    {
        if (current->value < min)
        {
            min = current->value;
            min_pos = pos;
        }
        pos++;
        current = current->next;
    }
    size = pos;
    if (min_pos <= size / 2)
        while (min_pos--)
            ra(a);
    else
        while (min_pos++ < size)
            rra(a);
}

void sort_five(t_stack **a, t_stack **b)
{
    int size;

    size = stack_size(*a);
    while (size > 3)
    {
        move_min_to_top(a);
        pb(a, b);
        size--;
    }
    optimized_sort_three(a);
    while (*b)
        pa(a, b);
}

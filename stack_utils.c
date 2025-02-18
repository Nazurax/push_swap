/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:25:35 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/18 16:25:39 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(t_stack *stack)
{
	t_stack *temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

int stack_size(t_stack *stack)
{
    int count = 0;

    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}

int is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void swap(t_stack *stack)
{
    int temp;

    if (!stack || !stack->next)
        return;
    temp = stack->value;
    stack->value = stack->next->value;
    stack->next->value = temp;
}

void push(t_stack **src, t_stack **dest)
{
    t_stack *temp;

    if (!*src)
        return;
    temp = *src;
    *src = (*src)->next;
    temp->next = *dest;
    *dest = temp;
}

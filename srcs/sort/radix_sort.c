/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:26:12 by alortiz-          #+#    #+#             */
/*   Updated: 2025/04/05 18:29:50 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	get_position(t_stack *stack, int value)
{
	int	pos;

	pos = 0;
	if (!stack)
		return (-1);
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

static void	process_bit(t_stack **a, t_stack **b, int bit, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (((*a)->value >> bit) & 1)
			ra(a);
		else
			pb(a, b);
		j++;
	}
	while (*b)
		pa(a, b);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	max_bits;
	int	i;

	if (!a || !*a)
		return ;
	normalize_stack(a);
	size = stack_size(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		process_bit(a, b, i, size);
		i++;
	}
}

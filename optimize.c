/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:26:12 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/20 17:32:51 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		*normalized;
	int		size;
	int		i;

	size = stack_size(*stack);
	normalized = (int *)malloc(sizeof(int) * size);
	if (!normalized)
		handle_error(stack, NULL, ERROR_MALLOC);
	current = *stack;
	i = 0;
	while (current)
	{
		normalized[i] = 0;
		compare = *stack;
		while (compare)
		{
			if (current->value > compare->value)
				normalized[i]++;
			compare = compare->next;
		}
		current = current->next;
		i++;
	}
	i = 0;
	current = *stack;
	while (current)
	{
		current->value = normalized[i++];
		current = current->next;
	}
	free(normalized);
}

void    sort_four(t_stack **a, t_stack **b)
{
    int min;

    min = get_min_value(*a);
    while ((*a)->value != min)
        ra(a);
    pb(a, b);
    optimized_sort_three(a);  // Cambio aquí
    pa(a, b);
}

void	optimized_sort_three(t_stack **a)
{
	int	values[3];

	values[0] = (*a)->value;
	values[1] = (*a)->next->value;
	values[2] = (*a)->next->next->value;
	if (values[0] > values[1] && values[1] < values[2] && values[0] < values[2])
		sa(a);
	else if (values[0] > values[1] && values[1] > values[2])
	{
		sa(a);
		rra(a);
	}
	else if (values[0] > values[1] && values[1] < values[2] && values[0] > values[2])
		ra(a);
	else if (values[0] < values[1] && values[1] > values[2] && values[0] < values[2])
	{
		sa(a);
		ra(a);
	}
	else if (values[0] < values[1] && values[1] > values[2])
		rra(a);
}

void	optimized_radix(t_stack **a, t_stack **b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;
	int	num;

	normalize_stack(a);
	size = stack_size(*a);
	max_bits = 0;
	i = size - 1;
	while ((i >> max_bits) != 0)
		++max_bits;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			num = (*a)->value;
			if ((num >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (stack_size(*b))
			pa(a, b);
		i++;
	}
}

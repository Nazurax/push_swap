/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:32:33 by alortiz-          #+#    #+#             */
/*   Updated: 2025/04/06 20:32:38 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_ints(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	pass_bubble(int *arr, int size)
{
	int	i;
	int	sorted;

	i = 0;
	sorted = 1;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			swap_ints(&arr[i], &arr[i + 1]);
			sorted = 0;
		}
		i++;
	}
	return (sorted);
}

void	bubble_sort(int *arr, int size)
{
	int	i;

	if (!arr || size < 2)
		return ;
	i = 0;
	while (i < size - 1)
	{
		if (pass_bubble(arr, size - i))
			break ;
		i++;
	}
}

int	get_max_value(t_stack *stack)
{
	int		max;
	t_stack	*current;

	if (!stack)
		return (INT_MIN);
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

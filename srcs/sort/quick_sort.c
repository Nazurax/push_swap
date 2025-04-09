/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:01:32 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/22 06:49:05 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Encuentra el pivote como la mediana de tres valores (inicio, medio, fin)
int	get_pivot(t_stack *a)
{
	int	size;
	int	values[3];

	if (!a || !a->next)
		return (0);
	size = stack_size(a);
	values[0] = a->value;
	values[1] = get_nth_value(a, size / 2);
	values[2] = get_nth_value(a, size - 1);
	return (median(values[0], values[1], values[2]));
}

int	get_nth_value(t_stack *stack, int n)
{
	int	i;

	if (!stack || n < 0)
		return (0);
	i = 0;
	while (stack && i < n)
	{
		stack = stack->next;
		i++;
	}
	if (!stack)
		return (0);
	return (stack->value);
}

int	median(int a, int b, int c)
{
	if ((a > b && a < c) || (a > c && a < b))
		return (a);
	else if ((b > a && b < c) || (b > c && b < a))
		return (b);
	return (c);
}

// Mueve los elementos menores al pivote a la pila B
void	partition_stack(t_stack **a, t_stack **b, int pivot)
{
	int	size;
	int	i;

	if (!a || !(*a) || !b)
		return ;
	size = stack_size(*a);
	i = 0;
	while (i < size)
	{
		if ((*a)->value < pivot)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

void	quick_sort(t_stack **a, t_stack **b)
{
	int	pivot;
	int	size;

	if (!a || !(*a) || !b)
		return ;
	size = stack_size(*a);
	if (size <= 5)
		return ;
	pivot = get_pivot(*a);
	partition_stack(a, b, pivot);
	quick_sort(a, b);
	while (*b)
		pa(a, b);
}

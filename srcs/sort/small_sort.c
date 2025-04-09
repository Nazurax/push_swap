/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:01:32 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/22 07:01:51 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static	void	move_max_to_top(t_stack **stack)
{
	int	max;
	int	pos;
	int	size;

	max = get_max_value(*stack);
	pos = get_position(*stack, max);
	if (pos <= size / 2)
	{
		while ((*stack)->value != max)
			ra(stack);
	}
	else
	{
		while ((*stack)->value != max)
			rra(stack);
	}
}

static	void	move_min_to_top(t_stack **a)
{
	int	min;
	int	pos;
	int	size;

	if (!a || !*a)
		return ;
	min = get_min_value(*a);
	pos = get_position(*a, min);
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while ((*a)->value != min)
			ra(a);
	}
	else
	{
		while ((*a)->value != min)
			rra(a);
	}
}*/
int	get_min_value(t_stack *stack)
{
	int		min;
	t_stack	*current;

	if (!stack)
		return (INT_MAX);
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

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_ff(t_stack **a, t_stack **b)
{
	int	min;
	int	pos;
	int	size;

	if (!a || !(*a) || !b)
		return ;
	size = stack_size(*a);
	if (size != 4 && size != 5)
		return ;
	while (size > 3)
	{
		min = get_min_value(*a);
		pos = get_position(*a, min);
		if (pos <= size / 2)
			while (pos-- > 0)
				ra(a);
		else
			while (pos++ < size)
				rra(a);
		pb(a, b);
		size--;
	}
	sort_three(a);
	while (stack_size(*b) > 0)
		pa(a, b);
}

int	is_sorted(t_stack *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:09:32 by alortiz-          #+#    #+#             */
/*   Updated: 2025/04/07 17:09:34 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	fill_array(t_stack *stack, int *arr)
{
	int	i;

	i = 0;
	while (stack)
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}
}

int	get_position_arr(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static void	assign_positions(t_stack *stack, int *arr, int size)
{
	while (stack)
	{
		stack->value = get_position_arr(arr, size, stack->value);
		stack = stack->next;
	}
}

void	normalize_stack(t_stack **stack)
{
	int		*arr;
	int		size;

	if (!stack || !*stack)
		return ;
	size = stack_size(*stack);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		handle_error(stack, NULL, "Error\n", ERROR_MALLOC);
	fill_array(*stack, arr);
	bubble_sort(arr, size);
	assign_positions(*stack, arr, size);
	free(arr);
}

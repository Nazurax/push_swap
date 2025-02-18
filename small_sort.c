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

void sort_three(t_stack **a)
{
    int first, second, third;

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
    else if (first < second && second > third)
        rra(a);
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
    sort_three(a);
    while (*b)
        pa(a, b);
}

void	small_sort (t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
}

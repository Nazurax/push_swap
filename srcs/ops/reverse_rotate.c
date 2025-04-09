/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:49:02 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/22 04:43:24 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función genérica para rotaciones inversas
void	reverse_rotate(t_stack **stack, char *op)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = *stack;
	*stack = last;
	if (op)
		write(1, op, 4);
}

void	rra(t_stack **a)
{
	reverse_rotate(a, "rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b, "rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a, "");
	reverse_rotate(b, "");
	write(1, "rrr\n", 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:49:02 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/22 04:47:49 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función genérica para rotar la pila
void	rotate(t_stack **stack, char *op)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = tmp;
	if (op)
		write(1, op, 3);
}

void	ra(t_stack **a)
{
	rotate(a, "ra\n");
}

void	rb(t_stack **b)
{
	rotate(b, "rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, "");
	rotate(b, "");
	write(1, "rr\n", 3);
}

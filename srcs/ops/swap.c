/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:24:16 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/22 04:43:33 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char *op)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	if (op)
		write(1, op, 3);
}

void	sa(t_stack **a)
{
	swap(a, "sa\n");
}

void	sb(t_stack **b)
{
	swap(b, "sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a, "");
	swap(b, "");
	write(1, "ss\n", 3);
}

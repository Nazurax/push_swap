/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:21:55 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/22 04:43:12 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función genérica para mover el primer elemento de `src` a `dst`
void	push(t_stack **src, t_stack **dst, char *op)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
	if (op)
		write(1, op, 3);
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a, "pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b, "pb\n");
}

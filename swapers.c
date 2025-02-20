/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:24:16 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/20 12:52:42 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack **a)
{
    t_stack *tmp;

    if (*a && (*a)->next)
    {
        tmp = (*a)->next;
        (*a)->next = tmp->next;
        tmp->next = *a;
        *a = tmp;
	write(1, "sa\n", 3);
    }
}

void sb(t_stack **b)
{
    t_stack *tmp;

    if (*b && (*b)->next)
    {
        tmp = (*b)->next;
        (*b)->next = tmp->next;
        tmp->next = *b;
        *b = tmp;
	write(1, "sb\n", 3);
    }
}

void ss(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (*a && (*a)->next)
    {
        tmp = (*a)->next;
        (*a)->next = tmp->next;
        tmp->next = *a;
        *a = tmp;
    }
    if (*b && (*b)->next)
    {
        tmp = (*b)->next;
        (*b)->next = tmp->next;
        tmp->next = *b;
        *b = tmp;
    }
    if ((*a && (*a)->next) || (*b && (*b)->next))
        write(1, "ss\n", 3);
}

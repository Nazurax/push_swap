/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:21:55 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/20 12:53:48 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (*b)
    {
        tmp = *b;
        *b = (*b)->next;
        tmp->next = *a;
        *a = tmp;
        write(1, "pa\n", 3);
    }
}

void pb(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (*a)
    {
        tmp = *a;
        *a = (*a)->next;
        tmp->next = *b;
        *b = tmp;
        write(1, "pb\n", 3);
    }
}

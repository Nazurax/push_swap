/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotaters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:49:02 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/20 12:53:11 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack **a)
{
    t_stack *tmp;
    t_stack *last;

    if (*a && (*a)->next)
    {
        tmp = *a;
        *a = (*a)->next;
        tmp->next = NULL;
        last = *a;
        while (last->next)
            last = last->next;
        last->next = tmp;
        write(1, "ra\n", 3);
    }
}

void rb(t_stack **b)
{
    t_stack *tmp;
    t_stack *last;

    if (*b && (*b)->next)
    {
        tmp = *b;
        *b = (*b)->next;
        tmp->next = NULL;
        last = *b;
        while (last->next)
            last = last->next;
        last->next = tmp;
        write(1, "rb\n", 3);
    }
}

void rr(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    t_stack *last;
    int performed = 0;

    if (*a && (*a)->next)
    {
        tmp = *a;
        *a = (*a)->next;
        tmp->next = NULL;
        last = *a;
        while (last->next)
            last = last->next;
        last->next = tmp;
        performed = 1;
    }
    if (*b && (*b)->next)
    {
        tmp = *b;
        *b = (*b)->next;
        tmp->next = NULL;
        last = *b;
        while (last->next)
            last = last->next;
        last->next = tmp;
        performed = 1;
    }
    if (performed)
        write(1, "rr\n", 3);
}

void rra(t_stack **a)
{
    t_stack *tmp;

    if (*a && (*a)->next)
    {
        tmp = *a;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = *a;
        *a = (*a)->next;
        tmp->next->next = NULL;
        write(1, "rra\n", 3);
    }
}

void rrb(t_stack **b)
{
    t_stack *tmp;

    if (*b && (*b)->next)
    {
        tmp = *b;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = *b;
        *b = (*b)->next;
        tmp->next->next = NULL;
        write(1, "rrb\n", 3);
    }
}

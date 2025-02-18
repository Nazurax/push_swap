/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:21:55 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/17 18:21:59 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void rrr(t_stack **a, t_stack **b)
{
    rra(a);
    rrb(b);
    write(1, "rrr\n", 3);
}*/
void rrr(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    int performed = 0;

    if (*a && (*a)->next)
    {
        tmp = *a;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = *a;
        *a = (*a)->next;
        tmp->next->next = NULL;
        performed = 1;
    }
    if (*b && (*b)->next)
    {
        tmp = *b;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = *b;
        *b = (*b)->next;
        tmp->next->next = NULL;
        performed = 1;
    }
    if (performed)
        write(1, "rrr\n", 4);
}

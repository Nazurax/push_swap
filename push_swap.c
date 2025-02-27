/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:27:03 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/18 16:27:06 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_swap(t_stack **a, t_stack **b)
{
    int size;

    if (!*a || is_sorted(*a))
        return ;
    size = stack_size(*a);
    if (size == 2 && (*a)->value > (*a)->next->value)
        sa(a);
    else if (size == 3)
        optimized_sort_three(a);
    else if (size == 4)
        sort_four(a, b);
    else if (size <= 6)
        sort_five(a, b);
    else
        optimized_radix(a, b);
}

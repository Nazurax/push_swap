/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:26:12 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/18 16:26:15 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void radix_sort(t_stack **a, t_stack **b)
{
    int max_bits;
    int size;
    int i;
    int j;
    int num;

    size = stack_size(*a);
    max_bits = get_max_bits(*a);
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            num = (*a)->value;
            if ((num >> i) & 1)
                ra(a);
            else
                pb(a, b);
            j++;
        }
        while (*b)
            pa(a, b);
        i++;
    }
}

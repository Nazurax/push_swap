/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:38:48 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/19 15:38:51 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void handle_error(t_stack **a, t_stack **b, int error_code)
{
    if (a)
        free_stack(*a);
    if (b)
        free_stack(*b);
    write(2, "Error\n", 6);
    exit(error_code);
}

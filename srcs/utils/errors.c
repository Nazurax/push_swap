/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:38:48 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/22 04:44:11 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Maneja los errores con un mensaje y libera las pilas
void	handle_error(t_stack **a, t_stack **b, const char *errm, int errc)
{
	if (errm)
		ft_putstr_fd((char *)errm, 2);
	else
		ft_putstr_fd("Error\n", 2);
	free_stacks(a, b);
	exit(errc);
}

// Maneja un error simple de entrada con un mensaje estándar
void	handle_input_error_simple(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	free_stacks(t_stack **a, t_stack **b)
{
	if (a && *a)
		free_stack(*a);
	if (b && *b)
		free_stack(*b);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

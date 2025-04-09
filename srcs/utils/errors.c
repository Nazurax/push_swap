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
#include "libft.h"

// Manejo flexible de errores con mensaje personalizado
void	handle_error(t_stack **a, t_stack **b, const char *errm, int errc)
{
	if (errm)
		write(2, errm, ft_strlen(errm));
	else
		write(2, "Error\n", 6);
	free_stacks(a, b);
	exit(errc);
}

void	free_stacks(t_stack **a, t_stack **b)
{
	if (a && *a)
	{
		free_stack(*a);
		*a = NULL;
	}
	if (b && *b)
	{
		free_stack(*b);
		*b = NULL;
	}
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

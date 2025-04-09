/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:58:38 by alortiz-          #+#    #+#             */
/*   Updated: 2025/04/05 20:41:05 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Comprueba si la cadena está vacía o solo contiene espacios/tabulaciones
static	int	is_empty_or_space(const char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (1);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

// Comprueba si el número ya existe en la pila
bool	is_duplicate_in_stack(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->value == num)
			return (true);
		stack = stack->next;
	}
	return (false);
}

// Valida el número y lo empuja a la pila
static void	validate_and_push(t_stack **stack, const char *str)
{
	int	num;
	int	error;

	error = 0;
	if (is_empty_or_space(str))
		handle_error(stack, NULL, "Error: string\n", ERROR_INVALID_INPUT);
	num = ft_atoi_push(str, &error);
	if (error || is_duplicate_in_stack(*stack, num))
		handle_error(stack, NULL, "Error: Duplicate\n", ERROR_INVALID_INPUT);
	if (!push_back(stack, num))
		handle_error(stack, NULL, "Error: Memory\n", ERROR_MALLOC);
}

static	void	process_arg(t_stack **stack, char *arg)
{
	char	**split_args;
	int		j;

	split_args = split_args_func(arg);
	if (!split_args)
		handle_error(stack, NULL, "Error: Split arg\n", ERROR_MALLOC);
	j = 0;
	while (split_args[j])
	{
		validate_and_push(stack, split_args[j]);
		free(split_args[j]);
		j++;
	}
	free(split_args);
}

t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		process_arg(&stack, argv[i]);
		i++;
	}
	if (!stack)
		handle_error(&stack, NULL, "Error: Inv. input\n", ERROR_INVALID_INPUT);
	return (stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:58:38 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/12 12:58:44 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parse_input(int argc, char **argv)
{
    t_stack	*stack;
    int		i;
    int		num;
    int		error;

    stack = NULL;
    i = 1;
    while (i < argc)
    {
        if (!is_valid_number(argv[i]))
        {
            free_stack(stack);
            write(2, "Error\n", 6);
            return (NULL);
        }
        error = 0;
        num = ft_atoi(argv[i], &error);
        if (error || is_duplicate(stack, num))
        {
            free_stack(stack);
            write(2, "Error\n", 6);
            return (NULL);
        }
        push_back(&stack, num);
        i++;
    }
    return (stack);
}

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

t_stack *parse_input(int argc, char **argv)
{
    t_stack *stack;
    int     i;
    int     num;
    int     error;

    stack = NULL;
    i = 1;
    while (i < argc)
    {
        if (!is_valid_number(argv[i]))
            handle_error(&stack, NULL, ERROR_INVALID_INPUT);
        
        error = 0;
        num = ft_atoi(argv[i], &error);
        if (error)
            handle_error(&stack, NULL, ERROR_OVERFLOW);
            
        if (is_duplicate(stack, num))
            handle_error(&stack, NULL, ERROR_DUPLICATE);
            
        if (!push_back(&stack, num))
            handle_error(&stack, NULL, ERROR_MALLOC);
            
        i++;
    }
    return (stack);
}

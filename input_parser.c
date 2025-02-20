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

static int is_empty_or_space(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '\t')
            return (0);
        i++;
    }
    return (1);
}

t_stack *parse_input(int argc, char **argv)
{
    t_stack *stack;
    int     i;
    int     num;
    int     error;
    char    *str;

    stack = NULL;
    i = 1;
    while (i < argc)
    {
        str = argv[i];
        if (is_empty_or_space(str))
            handle_error(&stack, NULL, ERROR_INVALID_INPUT);
            
        if (!is_valid_number(str))
            handle_error(&stack, NULL, ERROR_INVALID_INPUT);
        
        error = 0;
        num = ft_atoi(str, &error);
        if (error)
            handle_error(&stack, NULL, ERROR_OVERFLOW);
            
        if (is_duplicate(stack, num))
            handle_error(&stack, NULL, ERROR_DUPLICATE);
            
        if (!push_back(&stack, num))
            handle_error(&stack, NULL, ERROR_MALLOC);
            
        i++;
    }
    
    if (!stack)
        handle_error(&stack, NULL, ERROR_INVALID_INPUT);
        
    return (stack);
}

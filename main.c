/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:24:52 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/18 16:24:58 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        return (0);
    a = parse_input(argc, argv);
    if (!a)
        return (write(2, "Error\n", 6), 1);
    b = NULL;
    push_swap(&a, &b);
    free_stack(a);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:24:52 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/22 04:35:02 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "stdio.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	a = parse_input(argc, argv);
	if (!a)
	{
		fprintf(stderr, "Error: entrada no válida\n");
		return (1);
	}
	push_swap(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}

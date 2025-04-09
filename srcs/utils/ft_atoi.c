/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:55:16 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/22 04:44:38 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

char	**split_args_func(char *arg)
{
	if (!arg || !*arg)
		return (NULL);
	return (ft_split(arg, ' '));
}

int	push_back(t_stack **a, int value)
{
	t_stack	*new_node;
	t_stack	*temp;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->next = NULL;
	if (!*a)
		*a = new_node;
	else
	{
		temp = *a;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
	return (1);
}

static int	process_sign_and_check(const char *nptr, int *i)
{
	int	sign;

	sign = 1;
	while ((nptr[*i] >= 9 && nptr[*i] <= 13) || nptr[*i] == 32)
		(*i)++;
	if (nptr[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	else if (nptr[*i] == '+')
		(*i)++;
	return (sign);
}

static int	validate_and_convert(const char *nptr, int *i, int sign, int *error)
{
	long	res;

	res = 0;
	while (nptr[*i] >= '0' && nptr[*i] <= '9')
	{
		res = res * 10 + (nptr[*i] - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && (-res) < INT_MIN))
		{
			*error = 1;
			return (0);
		}
		(*i)++;
	}
	return ((int)(res * sign));
}

int	ft_atoi_push(const char *nptr, int *error)
{
	int	i;
	int	sign;
	int	result;

	*error = 0;
	i = 0;
	if (!nptr || !*nptr)
	{
		*error = 1;
		return (0);
	}
	sign = process_sign_and_check(nptr, &i);
	if (nptr[i] < '0' || nptr[i] > '9')
	{
		*error = 1;
		return (0);
	}
	result = validate_and_convert(nptr, &i, sign, error);
	return (result);
}

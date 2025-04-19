/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:26:34 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/21 18:15:29 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ERROR_INVALID_INPUT 1
# define ERROR_MALLOC 2
# define ERROR_OVERFLOW 3

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

/* ==== STRUCT === */
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

/* ==== CORE ==== */
void	push_swap(t_stack **a, t_stack **b);
t_stack	*parse_input(int argc, char **argv);
int		is_sorted(t_stack *stack);

/* ==== ALGORITHMS ==== */
void	quick_sort(t_stack **a, t_stack **b);
void	partition_stack(t_stack **a, t_stack **b, int pivot);
int		get_pivot(t_stack *a);
int		get_nth_value(t_stack *stack, int n);
int		median(int a, int b, int c);
void	radix_sort(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_ff(t_stack **a, t_stack **b);
void	normalize_stack(t_stack **stack);
void	bubble_sort(int *arr, int size);

/* ==== STACK UTILS ==== */
int		stack_size(t_stack *stack);
int		get_position(t_stack *stack, int value);
int		get_position_arr(int *arr, int size, int value);
int		push_back(t_stack **a, int value);
bool	is_duplicate_in_stack(t_stack *stack, int num);

/* ==== STACK OPERATIONS ==== */
void	push(t_stack **src, t_stack **dst, char *op);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	swap(t_stack **stack, char *op);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	rotate(t_stack **stack, char *op);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **stack, char *op);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* ==== ERROR & MEMORY MANAGEMENT ==== */
void	handle_error(t_stack **a, t_stack **b, const char *errm, int errc);
void	handle_input_error_simple(void);
void	free_stack(t_stack *stack);
void	free_stacks(t_stack **a, t_stack **b);

/* ==== PARSE & VALIDATION ==== */
int		ft_atoi_push(const char *nptr, int *error);
char	**split_args_func(char *arg);

#endif

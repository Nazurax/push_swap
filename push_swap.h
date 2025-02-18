/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:26:34 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/18 16:26:45 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
    int value;
    struct s_stack *next;
} t_stack;

// Función principal
void push_swap(t_stack **a, t_stack **b);

// Algoritmos de ordenamiento
void radix_sort(t_stack **a, t_stack **b);
void small_sort(t_stack **a, t_stack **b);
void sort_three(t_stack **a);
void sort_five(t_stack **a, t_stack **b);
void move_min_to_top(t_stack **a);

// Operaciones de pila
void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);
void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a, t_stack **b);

// Funciones auxiliares
int stack_size(t_stack *stack);
int is_sorted(t_stack *stack);
t_stack *parse_input(int argc, char **argv);
void push_back(t_stack **stack, int value);
int get_max_bits(t_stack *stack);
int get_max_value(t_stack *stack);
int is_valid_number(char *str);
int is_duplicate(t_stack *stack, int num);
void free_stack(t_stack *stack);
void swap(t_stack *stack);
void push(t_stack **src, t_stack **dest);
int ft_atoi(const char *str, int *error);

#endif
/*#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
    int value;
    struct s_stack *next;
} t_stack;

void push_swap(t_stack **a, t_stack **b);
void radix_sort(t_stack **a, t_stack **b);
void sa(t_stack **a);
void pb(t_stack **a, t_stack **b);
void ra(t_stack **a);
void pa(t_stack **a, t_stack **b);
int stack_size(t_stack *stack);
int is_sorted(t_stack *stack);
t_stack *parse_input(int argc, char **argv);
void push_back(t_stack **stack, int value);
int get_max_bits(t_stack *stack);
int is_valid_number(char *str);
int is_duplicate(t_stack *stack, int num);
void free_stack(t_stack *stack);
void small_sort(t_stack **a, t_stack **b);
void swap(t_stack *stack);
void push(t_stack **src, t_stack **dest);
int ft_atoi(const char *str);

#endif
*/

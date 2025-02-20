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
# include <limits.h>

// Definición de códigos de error
# define ERROR_MALLOC 1
# define ERROR_INVALID_INPUT 2
# define ERROR_DUPLICATE 3
# define ERROR_OVERFLOW 4

typedef struct s_stack
{
    int value;
    struct s_stack *next;
} t_stack;

// Función principal
void push_swap(t_stack **a, t_stack **b);

// Manejo de errores
void handle_error(t_stack **a, t_stack **b, int error_code);

// Algoritmos de ordenamiento
void radix_sort(t_stack **a, t_stack **b);
void small_sort(t_stack **a, t_stack **b);
void sort_three(t_stack **a);
void sort_five(t_stack **a, t_stack **b);
void move_min_to_top(t_stack **a);
void move_max_to_top(t_stack **stack);
void chunk_sort(t_stack **a, t_stack **b, int n_chunks);
void bubble_sort(int *arr, int size);
void sort_six(t_stack **a, t_stack **b);
void    normalize_stack(t_stack **stack);
void    sort_four(t_stack **a, t_stack **b);
void    optimized_sort_three(t_stack **a);
void    optimized_radix(t_stack **a, t_stack **b);

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
int find_median(t_stack *stack);
int stack_size(t_stack *stack);
int is_sorted(t_stack *stack);
int push_back(t_stack **stack, int value);
int get_max_bits(t_stack *stack);
int get_max_value(t_stack *stack);
int is_valid_number(char *str);
int is_duplicate(t_stack *stack, int num);
void free_stack(t_stack *stack);
void swap(t_stack *stack);
void push(t_stack **src, t_stack **dest);
int ft_atoi(const char *str, int *error);
int get_position(t_stack *stack, int value);
int has_numbers_in_range(t_stack *stack, int min, int max);
int get_min_value(t_stack *stack);
t_stack *parse_input(int argc, char **argv);

#endif

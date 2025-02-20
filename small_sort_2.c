/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alortiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:01:32 by alortiz-          #+#    #+#             */
/*   Updated: 2025/02/20 13:10:54 by alortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_six(t_stack **a, t_stack **b)
{
    int median;
    
    median = find_median(*a);
    
    // Dividir la pila en dos partes basadas en la mediana
    while (stack_size(*a) > 3)
    {
        if ((*a)->value <= median)
            pb(a, b);
        else
            ra(a);
    }
    
    // Ordenar los tres números en la pila A
    if (!is_sorted(*a))
        optimized_sort_three(a);  // Cambio aquí
        
    // Ordenar los números en la pila B si es necesario
    if (*b && (*b)->next && (*b)->value < (*b)->next->value)
        sb(b);
        
    // Devolver los números a la pila A
    while (*b)
        pa(a, b);
}

int find_median(t_stack *stack)
{
    int *arr;
    int size;
    int i;
    int median;
    t_stack *tmp;
    
    size = stack_size(stack);
    arr = (int *)malloc(sizeof(int) * size);
    if (!arr)
        return (0);
    
    // Copiar valores al array
    i = 0;
    tmp = stack;
    while (tmp)
    {
        arr[i++] = tmp->value;
        tmp = tmp->next;
    }
    
    // Ordenar array
    bubble_sort(arr, size);
    
    // Encontrar mediana
    median = arr[size / 2];
    free(arr);
    
    return (median);
}

void bubble_sort(int *arr, int size)
{
    int i;
    int j;
    int temp;
    
    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

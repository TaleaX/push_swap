/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:05:04 by tdehne            #+#    #+#             */
/*   Updated: 2022/06/06 14:32:21 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_elem_index(int *a, int elem)
{
	int	i;

	i = 0;
	while (a[i] != elem)
		i++;
	return (i);
}

void ccsort(int a[], int n, int shift, t_list **stack_a, t_list **stack_b, int *counter) {

    int count[16] = { 0 };
    int output[n];
    int i, last;
	t_list **stack;
	t_list **push_to;
	t_list	*tmp;

	stack = stack_a;
	push_to = stack_b;
	if (!*stack_a)
	{
		stack = stack_b;
		push_to = stack_a;
	}
    for (i = 0; i < n; i++) {
        ++count[(a[i] >> shift) & 15];
    }
    for (i = last = 0; i < 16; i++) {
        last += count[i];
        count[i] = last - count[i];
    }
    for (i = 0; i < n; i++) {
        output[count[(a[i] >> shift) & 15]++] = a[i];
    }
    for (i = n - 1; i >= 0; i--) {
		//a[i] = output[i];
		while ((*stack)->content != output[i])
		{
			int index = find_node_by_content(*stack, output[i]);
			if (index > n / 2)
				shift_down(stack);
			else
				shift_up(stack);
			(*counter)++;
			printf("counter %d\n", *counter);
		}
		push_b(stack, push_to);
		(*counter)++;
    }
	i = 0;
	tmp = *push_to;
	while (tmp)
	{
		a[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
}

void rsort(int a[], int n, t_list **stack_a, t_list **stack_b, int *counter) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    for (int shift = 0; (max >> shift) > 0; shift += 4) {   
        ccsort(a, n, shift, stack_a, stack_b, counter);
    }
	//ccsort(a, n, 0, stack_a, stack_b);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:37:15 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/07 11:12:34 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static void	sort(t_data *data, operation operations[3], int *c)
{
	if (data->size_a == 2 || (data->head_a->index < data->head_a->next->index && data->head_a->index  < data->head_a->next->next->index))
	{
		operations[SWAP](&data->head_a);
		print_stack_dev(data->head_a, data->head_b, CONST_A);
		(*c)++;
	}
	if ((data->head_a->index > data->head_a->next->index && data->head_a->index < data->head_a->next->next->index))
	{
		operations[SWAP](&data->head_a);
		print_stack_dev(data->head_a, data->head_b, CONST_A);
		(*c)++;
	}
	if (data->head_a->index > data->head_a->next->index && data->head_a->index > data->head_a->next->next->index)
	{
		operations[SHIFT_UP](&data->head_a);
		print_stack_dev(data->head_a, data->head_b, CONST_A + SHIFT_UP * 2);
		(*c)++;
	}
	if (data->head_a->index < data->head_a->next->index && data->head_a->index > data->head_a->next->next->index)
	{
		operations[SHIFT_DOWN](&data->head_a);
		print_stack_dev(data->head_a, data->head_b, CONST_A + SHIFT_DOWN * 2);
		(*c)++;
	}
}

void	sort_small(t_data *data, operation operations[3], int *c)
{
	while (!stack_a_sorted(data->head_a))
	{
		sort(data, operations, c);
	}
}

void sort_semi_small(t_data	*data, operation operations[3], int *c)
{
	t_list		*first;
	t_list		*second;
	t_list		*last;
	t_min_op	OP;

	first = data->head_a;
	second = data->head_a->next;
	last = 	lst_getlast(data->head_a);

	if (first->index < second->index && first->index > second->index)
	{
		if (last->index < data->size_a / 2)
			OP = SHIFT_DOWN;
		else
			OP = SHIFT_UP;
		operations[OP];
		print_stack_dev(data->head_a, data->head_b, CONST_A + OP * 2);
	}
}*/

void	sort_small(t_data *data, operation operations[3], int *c)
{
	while (!stack_a_sorted(data->head_a))
	{
		//sort(data, operations, c);
		printf("lol");
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:37:15 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/18 17:53:20 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	algo(t_data *data, t_operation operations[11])
{
	t_op	op;

	op = ZERO;
	if (data->size_a == 2 || (data->head_a->index < data->head_a->next->index
			&& data->head_a->index < data->head_a->next->next->index))
		op = SWAP_A;
	else if ((data->head_a->index > data->head_a->next->index
			&& data->head_a->index < data->head_a->next->next->index))
		op = SWAP_A;
	else if (data->head_a->index > data->head_a->next->index
		&& data->head_a->index > data->head_a->next->next->index)
		op = SHIFT_UP_A;
	else if (data->head_a->index < data->head_a->next->index
		&& data->head_a->index > data->head_a->next->next->index)
		op = SHIFT_DOWN_A;
	operations[op](data);
	print_stack_dev(op);
}

static t_op	ra_or_rra(t_data data, int max_real_i)
{
	int	actual_i;

	actual_i = 0;
	while (data.head_a)
	{
		if (data.head_a->index <= max_real_i)
			break ;
		data.head_a = data.head_a->next;
		actual_i++;
	}
	if (actual_i < data.head_a->index / 2)
		return (SHIFT_UP_A);
	return (SHIFT_DOWN_A);
}

void	sort_three(t_data *data, t_operation operations[11])
{
	while (!stack_a_sorted(data->head_a))
		algo(data, operations);
}

void	sort_smaller_six(t_data *data, t_operation operations[11])
{
	t_op	op;

	while (data->size_a > 3)
	{
		op = ra_or_rra(*data, 1);
		if (data->head_a->index == 0 || data->head_a->index == 1)
			op = PUSH_B;
		operations[op](data);
		print_stack_dev(op);
	}
	sort_three(data, operations);
	if (data->head_b->next && data->head_b->index < data->head_b->next->index)
	{
		operations[SWAP_B](data);
		print_stack_dev(SWAP_B);
	}
	operations[PUSH_A](data);
	print_stack_dev(PUSH_A);
	if (data->head_b)
	{
		operations[PUSH_A](data);
		print_stack_dev(PUSH_A);
	}
}

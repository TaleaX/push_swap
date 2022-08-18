/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:08:00 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/18 16:59:34 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*t_op	rotate_b(t_data *data, int min_i)
{
	t_list	*last;

	last = lst_getlast(data->head_b);
	if (last->index >= min_i)
		return (SHIFT_DOWN_B);
	return (ZERO);
}*/

void	ready_to_push(t_data *data, t_operation operations[11], t_op op, int m_i)
{
	while (data->head_b->index < m_i)
	{
		operations[op](data);
		print_stack_dev(op);
	}
}

t_op	get_ops(t_data data, int min_index)
{
	int		index;
	t_list	*tmp;

	index = 0;
	tmp = data.head_b;
	while (tmp->index < min_index)
	{
		if (!tmp->next)
			break ;
		tmp = tmp->next;
		index++;
	}
	if (index > data.size_b / 2)
	{
		return (SHIFT_DOWN_B);
	}
	return (SHIFT_UP_B);
}

void	sort(t_data *data, t_operation operations[11], int min_i, int reverse)
{
	t_op	op;

	if (!data->head_a || !data->head_a->next)
		return ;
	if (reverse)
	{
		op = SHIFT_DOWN_A;
		if (data->head_b && get_ops(*data, min_i) == SHIFT_DOWN_B)
			op = RRR;
	}
	else if (data->head_a->index == min_i)
	{
		op = SHIFT_UP_A;
		if (data->head_b && get_ops(*data, min_i) == SHIFT_UP_B)
			op = RR;
	}
	else if (data->head_a->index > data->head_a->next->index)
		op = SWAP_A;
	else
		return ;
	operations[op](data);
	print_stack_dev(op);
}

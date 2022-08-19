/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 07:03:18 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/19 15:01:09 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_data *data, t_operation operations[11])
{
	int			min_index;
	int			counter;
	t_op		op;
	t_list		*last;

	min_index = data->size_b - 3;
	counter = data->size_b - 1;
	while (data->size_b)
	{
		op = get_ops(*data, min_index);
		ready_to_push(data, operations, op, min_index);
		operations[PUSH_A](data);
		print_stack_dev(PUSH_A);
		counter--;
		sort(data, operations, min_index, 0);
		if (counter < min_index)
		{
			last = lst_getlast(data->head_a);
			if (last->index == min_index)
				sort(data, operations, min_index, 1);
			min_index -= 3;
		}
	}
}

void	pre_sort_helper(t_data *data, t_operation operations[11], t_vars vars)
{
	while (data->size_a > 3)
	{
		if (data->head_a->index <= vars.max_index
			&& data->head_a->index < (vars.stack_len - 3))
		{
			(vars.counter)++;
			if (vars.counter > vars.max_index)
				(vars.max_index) += (vars.group_size - 1) * 2;
			operations[PUSH_B](data);
			print_stack_dev(PUSH_B);
			if (data->head_b && data->head_b->index \
				<= (vars.max_index - vars.group_size - 1))
			{
				operations[SHIFT_UP_B](data);
				print_stack_dev(SHIFT_UP_B);
			}
		}
		else
		{
			operations[SHIFT_UP_A](data);
			print_stack_dev(SHIFT_UP_A);
		}
	}
}

void	pre_sort_b(t_data *data, t_operation operations[11], t_vars vars)
{
	vars.max_index = (vars.group_size - 1) * 2;
	vars.counter = 0;
	vars.stack_len = data->size_a;
	pre_sort_helper(data, operations, vars);
}

void	sort_big(t_data *data, t_operation operations[11], t_vars vars)
{
	if (!data->head_a)
		return ;
	pre_sort_b(data, operations, vars);
	sort_three(data, operations);
	sort_a(data, operations);
}

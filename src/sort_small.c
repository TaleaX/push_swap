/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:37:15 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/05 15:24:54 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_data *data, operation operations[3], int *c)
{
	if (data->size_a == 2 || (data->head_a->index < data->head_a->next->index && data->head_a->index  < data->head_a->next->next->index))
	{
		operations[0](&data->head_a);
		print_stack_dev(data->head_a, data->head_b, CONST_B);
		(*c)++;
	}
	if ((data->head_a->index > data->head_a->next->index && data->head_a->index < data->head_a->next->next->index))
	{
		operations[0](&data->head_a);
		print_stack_dev(data->head_a, data->head_b, CONST_B);
		(*c)++;
	}
	if (data->head_a->index > data->head_a->next->index && data->head_a->index > data->head_a->next->next->index)
	{
		operations[1](&data->head_a);
		print_stack_dev(data->head_a, data->head_b, CONST_B + 2);
		(*c)++;
	}
	if (data->head_a->index < data->head_a->next->index && data->head_a->index > data->head_a->next->next->index)
	{
		operations[2](&data->head_a);
		print_stack_dev(data->head_a, data->head_b, CONST_B + 2);
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
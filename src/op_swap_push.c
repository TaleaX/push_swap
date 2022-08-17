/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:04:46 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/17 15:05:25 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_data *data)
{
	t_list	*tmp_next_next;
	t_list	*tmp_next;

	if (!(data->head_a))
		return ;
	tmp_next_next = data->head_a->next->next;
	tmp_next = data->head_a->next;
	data->head_a->next->next = data->head_a;
	data->head_a->next = tmp_next_next;
	data->head_a = tmp_next;
}

void	swap_b(t_data *data)
{
	t_list	*tmp_next_next;
	t_list	*tmp_next;

	if (!(data->head_b))
		return ;
	tmp_next_next = data->head_b->next->next;
	tmp_next = data->head_b->next;
	data->head_b->next->next = data->head_b;
	data->head_b->next = tmp_next_next;
	data->head_b = tmp_next;
}

void	push_b(t_data *data)
{
	t_list	*first;

	first = data->head_a;
	lst_rm(&data->head_a, data->head_a);
	lst_add_front(&data->head_b, first);
}

void	push_a(t_data *data)
{
	t_list	*first;

	first = data->head_b;
	lst_rm(&data->head_b, data->head_b);
	lst_add_front(&data->head_a, first);
}

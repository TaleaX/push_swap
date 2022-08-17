/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_shifts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:18:28 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/17 15:05:50 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_up_a(t_data *data)
{
	t_list	*first;

	first = data->head_a;
	lst_rm(&data->head_a, data->head_a);
	first->next = NULL;
	lst_add_back(&data->head_a, first);
}

void	shift_up_b(t_data *data)
{
	t_list	*first;

	first = data->head_b;
	lst_rm(&data->head_b, data->head_b);
	first->next = NULL;
	lst_add_back(&data->head_b, first);
}

void	shift_down_a(t_data *data)
{
	t_list	*last;

	last = lst_getlast(data->head_a);
	lst_rm(&data->head_a, last);
	lst_add_front(&data->head_a, last);
}

void	shift_down_b(t_data *data)
{
	t_list	*last;

	last = lst_getlast(data->head_b);
	lst_rm(&data->head_b, last);
	lst_add_front(&data->head_b, last);
}

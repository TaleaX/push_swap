/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 07:01:50 by tdehne            #+#    #+#             */
/*   Updated: 2022/06/09 12:21:30 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void opt_sort(t_list **head_a, t_list **head_b, operation operation_arr[5], int start_len, t_min_op *OP)
{
	while (!is_sorted(*head_a) || lst_size(*head_a) != start_len)
	{
		while (*(++OP))
		{
			opt_sort(head_a, head_b, operation_arr, start_len, OP);
		}
		operation_arr[*OP] (head_a, head_b);
	}
} 
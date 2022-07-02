/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 07:03:18 by tdehne            #+#    #+#             */
/*   Updated: 2022/06/27 15:27:36 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	sort_b(t_list **head_b, operation operations[3])
{
	while (!is_rev_sorted(*head_b))
	{
		
	}
	return ;
}*/

void	sort_big(t_data data, operation operations[3], int max_index)
{
	t_min_op	OP;
	t_list		*tmp;
	int			counter;

	if (!(*data.head_a) || !data.head_a)
		return ;
	tmp = *data.head_a;
	while (data.size_a > 1)
	{
		OP = smallest_dist_head(tmp, max_index) < smallest_dist_tail(tmp, max_index) ? 1 : 2;
		while ((*data.head_a)->index > max_index)
			operations[OP](data.head_a);
		push_b(data.head_a, data.head_b);
		counter++;
		data.size_a--;
		if (counter >= max_index)
			max_index += max_index;
		print_stack(*data.head_a, *data.head_b, OP);
	}
}
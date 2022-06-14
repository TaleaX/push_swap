/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 07:01:50 by tdehne            #+#    #+#             */
/*   Updated: 2022/06/11 09:37:56 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_min_op	*get_possible_op(t_list *head_a, t_list *head_b)
{
	t_list		*last;
	t_list		*first;
	t_list		*sec;
	t_min_op	*op;

	last = lst_getlast(head_a);
	first = head_a;
	sec = head_a->next;
	op = (t_min_op *)ft_calloc(3, sizeof(t_min_op));
	if (first->content > sec->content && first->content > last->content && sec->content > last->content)
	{
		op[0] = SWAP_A;
		op[1] = SHIFT_DOWN_A;
	}
	else if (first->content > sec->content && first->content > last->content && sec->content < last->content)
		op[0] = SHIFT_DOWN_A;
	else if (first->content > sec->content && first->content < last->content)
		op[0] = SWAP_A;
	else if (first->content < sec->content && first->content < last->content &&sec->content < last->content)
	{
		op[0] = PUSH_B;
		op[1] = SHIFT_UP_A;
	}
	else if (first->content < sec->content && first->content < last->content &&sec->content > last->content)
		op[0] = SWAP_A;
	else if (first->content < sec->content && first->content > last->content)
		op[0] = SHIFT_UP_A;
	return (op);
}

void opt_sort(t_list **head_a, t_list **head_b, operation operation_arr[5], int start_len, t_min_op *OP, t_list	**lst[], int counter)
{
	int	j;

	j = 0;
	while (!is_sorted(*head_a) || lst_size(*head_a) != start_len)
	{
		OP = get_possible_op(*head_a, *head_b);
		operation_arr[*OP] (head_a, head_b);
		while (*(++OP))
		{
			opt_sort(head_a, head_b, operation_arr, start_len, OP, lst, counter++);
		}
		lst[counter][j] = head_a;
		j++;
	}
}

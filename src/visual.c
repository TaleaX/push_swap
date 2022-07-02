/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:17:11 by tdehne            #+#    #+#             */
/*   Updated: 2022/06/27 15:12:50 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *head_a, t_list *head_b, t_op OP)
{
	printf("\n-------------------------------\n");
	printf("Exec: ");
	if (OP == PUSH_A)
		printf("pa\n");
	else if (OP == PUSH_B)
		printf("pb\n");
	else if (OP == PUSH_B)
		printf("pb\n");
	else if (OP == SWAP_A)
		printf("sa\n");
	else if (OP == SWAP_B)
		printf("sb\n");
	else if (OP == SWAP_BOTH)
		printf("ss\n");
	else if (OP == SHIFT_UP_A)
		printf("ra\n");
	else if (OP == SHIFT_UP_B)
		printf("rb\n");
	else if (OP == SHIFT_UP_BOTH)
		printf("rr\n");
	else if (OP == SHIFT_DOWN_A)
		printf("rra\n");
	else if (OP == SHIFT_DOWN_B)
		printf("rrb\n");
	else if (OP == SHIFT_DOWN_BOTH)
		printf("rrr\n");
	else if (!OP)
		printf("First Print\n");
	while (head_a || head_b)
	{
		if (head_a)
		{
			printf("%d ", head_a->content);
			head_a = head_a->next;
		}
		if (head_b)
		{
			printf("%d ", head_b->content);
			head_b = head_b->next;
		}
		printf("\n");
		
	}
	printf("_ _\na b\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:17:11 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/18 09:01:29 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack_dev(t_op OP)
{
	if (OP == PUSH_A)
		write(1, "pa\n", 3);
	else if (OP == PUSH_B)
		write(1, "pb\n", 3);
	else if (OP == PUSH_B)
		write(1, "pb\n", 3);
	else if (OP == SWAP_A)
		write(1, "sa\n", 3);
	else if (OP == SWAP_B)
		write(1, "sb\n", 3);
	else if (OP == SS)
		write(1, "ss\n", 3);
	else if (OP == SHIFT_UP_A)
		write(1, "ra\n", 3);
	else if (OP == SHIFT_UP_B)
		write(1, "rb\n", 3);
	else if (OP == RR)
		write(1, "rr\n", 3);
	else if (OP == SHIFT_DOWN_A)
		write(1, "rra\n", 4);
	else if (OP == SHIFT_DOWN_B)
		write(1, "rrb\n", 4);
	else if (OP == RRR)
		write(1, "rrr\n", 4);
}

void	print_stack(t_list *head_a, t_list *head_b, t_op OP)
{
	if (OP == PUSH_A)
		write(1, "pa\n", 3);
	else if (OP == PUSH_B)
		write(1, "pb\n", 3);
	else if (OP == PUSH_B)
		write(1, "pb\n", 3);
	else if (OP == SWAP_A)
		write(1, "sa\n", 3);
	else if (OP == SWAP_B)
		write(1, "sb\n", 3);
	else if (OP == SS)
		write(1, "ss\n", 3);
	else if (OP == SHIFT_UP_A)
		write(1, "ra\n", 3);
	else if (OP == SHIFT_UP_B)
		write(1, "rb\n", 3);
	else if (OP == RR)
		write(1, "rr\n", 3);
	else if (OP == SHIFT_DOWN_A)
		write(1, "rra\n", 4);
	else if (OP == SHIFT_DOWN_B)
		write(1, "rrb\n", 4);
	else if (OP == RRR)
		write(1, "rrr\n", 4);
	printf("a: ");
	while (head_a)
	{
		printf("%d ", head_a->content);
		head_a = head_a->next;
	}
	printf("\nb: ");
	while (head_b)
	{
		printf("%d ", head_b->content);
		head_b = head_b->next;
	}
	printf("\n");
}
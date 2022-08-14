/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:17:11 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/14 12:35:27 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_digits(int num)
{
	int	counter;
	counter = 0;

	while ((num = num / 10))
		counter++;
	return (counter + 1);
}

int	highest_digit(t_list *head_a)
{
	int	max;

	if (!head_a)
		return (0);
	max = head_a->content;
	while (head_a)
	{
		if (head_a->content > max)
			max = head_a->content;
		head_a = head_a->next;
	}
	return (get_digits(max));
}

void	print_stack(t_list *head_a, t_list *head_b, t_op OP)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		max_digits;
	int		tmp_max_digits;

	tmp_a = head_a;
	tmp_b = head_b;
	max_digits = highest_digit(head_a);
	tmp_max_digits = max_digits;
	printf("\n-------------------------------\n");
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
	else if (OP == SS)
		printf("ss\n");
	else if (OP == SHIFT_UP_A)
		printf("ra\n");
	else if (OP == SHIFT_UP_B)
		printf("rb\n");
	else if (OP == RR)
		printf("rr\n");
	else if (OP == SHIFT_DOWN_A)
		printf("rra\n");
	else if (OP == SHIFT_DOWN_B)
		printf("rrb\n");
	else if (OP == RRR)
		printf("rrr\n");
	else if (OP == ZERO_ALL)
		printf("First Print\n");
	while (tmp_a || tmp_b)
	{
		if (tmp_a)
		{
			printf("%d[%d]  ", tmp_a->content, tmp_a->index);
			//printf("%d  ", tmp_a->content);
			while (max_digits-- > get_digits(tmp_a->content))
				printf(" ");
			tmp_a = tmp_a->next;
		}
		else
		{
			while (max_digits--)
				printf(" ");
			printf("  ");
		}
		if (tmp_b)
		{
			//printf("%d", tmp_b->content);
			printf("%d ", tmp_b->content);
			tmp_b = tmp_b->next;
		}
		printf("\n");
		max_digits = tmp_max_digits;
	}
	printf("_ ");
	while (max_digits-- > 1)
		printf(" ");
	printf("_\na ");
	max_digits = tmp_max_digits;
	while (max_digits-- > 1)
		printf(" ");
	printf("b\n");
}

void	print_stack_dev(t_list *head_a, t_list *head_b, t_op OP)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = head_a;
	tmp_b = head_b;
	//printf("\n-------------------------------\n");
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
	else if (OP == SS)
		printf("ss\n");
	else if (OP == SHIFT_UP_A)
		printf("ra\n");
	else if (OP == SHIFT_UP_B)
		printf("rb\n");
	else if (OP == RR)
		printf("rr\n");
	else if (OP == SHIFT_DOWN_A)
		printf("rra\n");
	else if (OP == SHIFT_DOWN_B)
		printf("rrb\n");
	else if (OP == RRR)
		printf("rrr\n");
	else if (OP == ZERO_ALL)
		printf("First Print\n");
	printf("a : ");
	while (tmp_a)
	{
		printf("%d ", tmp_a->content);
		tmp_a = tmp_a->next;
	}
	printf("\nb : ");
	while (tmp_b)
	{
		printf("%d ", tmp_b->content);
		tmp_b = tmp_b->next;
	}
	printf("\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:08:53 by tdehne            #+#    #+#             */
/*   Updated: 2022/06/14 13:32:12 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **head_a, t_list **head_b, t_list *prev_smallest, int *counter)
{
	print_stack(*head_a, *head_b, 0);
	sort_stacks(head_a, head_b, prev_smallest, counter);
	while (*head_b)
	{
		push_a(head_a, head_b);
		print_stack(*head_a, *head_b, PUSH_A);
		(*counter)++;
	}
	printf("counter = %d\n", *counter);
}

int	main(int argc, char **argv)
{
	t_list			*head_a;
	t_list			*head_b;
	t_list			*smallest;
	int				counter;
	//int				*stack;
	//int				i;
	//operation		operation_arr[5] = {swap, shift_up, shift_down, push_b, push_a};

	head_a = create_stack_lst(argc, argv);
	head_b = NULL;
	counter = 0;
	smallest = NULL;
	//push_swap(&head_a, &head_b, smallest, &counter);
	while (head_a)
	{
		printf("content = %d index = %d\n", head_a->content, head_a->index);
		head_a = head_a->next;
	}
	//printf("counter = %d\n", counter);
	//printf("%d\n", head_a->content);
	/*
	counter = 0;
	//swap(&head_a);
	//shift_up(&head_a);
	//shift_down(&head_a);
	//push_b(&head_a, &head_b);
	push_swap(&head_a, &head_b, smallest, &counter);
	while (head_a)
	{
		printf("%d\n", head_a->content);
		head_a = head_a->next;
	}
	while (head_b)
	{
		printf("stack b %d\n", head_b->content);
		head_b = head_b->next;
	}*/
	/*stack = create_stack_arr(argc, argv, 1);
	rsort(stack, argc - 1, &head_a, &head_b, &counter);
	//shift_up_arr(stack, argc - 1);
	while (head_b)
	{
		printf("stack b %d\n", head_b->content);
		head_b = head_b->next;
	}
	printf("counter = %d\n", counter);*/
	/*i = 0;
	while (i < argc - 1)
	{
		printf("%d\n", stack[i]);
		i++;
	}*/
	return (0);
}
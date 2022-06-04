/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:08:53 by tdehne            #+#    #+#             */
/*   Updated: 2022/06/01 20:26:17 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_smallest(t_list *head_a)
{
	t_list	*smallest;

	smallest = head_a;
	while (head_a)
	{
		if (smallest->content > head_a->content)
			smallest = head_a;
		head_a = head_a->next;
	}
	return (smallest);
}

t_list	*get_next_smallest_node(t_list *head_a, t_list *prev_smallest)
{
	if (!prev_smallest)
		return (get_smallest(head_a));
	while (head_a)
	{
		if (head_a->content > prev_smallest->content)
		{
			prev_smallest = head_a;
			break ;
		}
		head_a = head_a->next;
	}
	while (head_a)
	{
		if (prev_smallest->content > head_a->content)
			prev_smallest = head_a;
		head_a = head_a->next;
	}
	return (prev_smallest);
}

void	sort_stacks(t_list **head_a, t_list **head_b, t_list *prev_smallest, int *counter)
{
	t_list	*smallest;
	int		size;

	if (lst_size(*head_a) == 1)
		return ;
	size = lst_size(*head_a);
	smallest = get_next_smallest_node(*head_a, prev_smallest);
	//printf("%p\n", smallest);
	while (smallest != *head_a)
	{
		if (find_node_spot(*head_a, smallest) <= size / 2)
			shift_up(head_a);
		else
			shift_down(head_a);
		(*counter)++;
	}
	push_b(head_a, head_b);
	(*counter)++;
	sort_stacks(head_a, head_b, smallest, counter);
}

void	push_swap(t_list **head_a, t_list **head_b, t_list *prev_smallest, int *counter)
{
	sort_stacks(head_a, head_b, prev_smallest, counter);
	while (*head_b)
	{
		push_a(head_a, head_b);
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

	head_a = create_stack(argc, argv);
	head_b = NULL;
	smallest = NULL;
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
	}
	return (0);
}
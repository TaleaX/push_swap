/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:50:38 by tdehne            #+#    #+#             */
/*   Updated: 2022/06/01 20:58:43 by tdehne           ###   ########.fr       */
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

t_chosen	*pushable(t_list **head, t_list	*prev_smallest)
{
	t_chosen	*chosen;
	int			i;

	chosen = (t_chosen *)malloc(sizeof(t_chosen) * 5);
	i = 5;
	while (i < 5)
	{
		prev_smallest = get_next_smallest_node(*head, prev_smallest);
		chosen[i].pos = find_node_spot(*head, prev_smallest);
		chosen[i].node = prev_smallest;
		i++;
	}
	return (chosen);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:52:09 by tdehne            #+#    #+#             */
/*   Updated: 2022/06/26 07:09:09 by tdehne           ###   ########.fr       */
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

t_list	*get_greatest(t_list *head_a)
{
	t_list	*greatest;

	greatest = head_a;
	while (head_a)
	{
		if (greatest->content < head_a->content)
			greatest = head_a;
		head_a = head_a->next;
	}
	return (greatest);
}

int	get_greatest_num(int *arr, int end)
{
	int	greatest;
	int	i;

	greatest = arr[0];
	i = 0;
	while (arr[i] != end)
	{
		if (greatest < arr[i])
			greatest = arr[i];
		i++;
	}
	return (greatest);
}

t_list	*get_next_smallest_node(t_list *head_a, t_list *prev_smallest)
{
	int	prev_val;

	if (!prev_smallest)
		return (get_smallest(head_a));
	prev_val = prev_smallest->content;
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
		if (prev_smallest->content > head_a->content && prev_val < head_a->content)
			prev_smallest = head_a;
		head_a = head_a->next;
	}
	return (prev_smallest);
}

int	smallest_dist_head(t_list *head, int max_index)
{
	int	counter;

	counter = 0;
	while (head)
	{
		if (head->index <= max_index)
			break ;
		counter++;
		head = head->next;
	}
	return (counter);
}

int	smallest_dist_tail(t_list *head, int max_index)
{
	int	counter;
	int	last_sel_i;

	counter = 0;
	while (head)
	{
		if (head->index <= max_index)
			last_sel_i = counter;
		counter++;
		head = head->next;
	}
	return (counter - last_sel_i);
}
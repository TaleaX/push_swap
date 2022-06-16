/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:52:09 by tdehne            #+#    #+#             */
/*   Updated: 2022/06/14 17:20:30 by tdehne           ###   ########.fr       */
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
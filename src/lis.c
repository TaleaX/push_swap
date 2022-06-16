/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:32:15 by tdehne            #+#    #+#             */
/*   Updated: 2022/06/16 15:00:48 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_dist_head(t_list *head, t_list *node)
{
	int	counter;

	counter = 0;
	while (head && head != node)
	{
		counter++;
		head = head->next;
	}
	return (counter);
}

int	smallest_dist_tail(t_list *head, t_list *node)
{
	int	counter;
	int	last_sel_i;

	counter = 0;
	while (head)
	{
		if (head == node)
			last_sel_i = counter;
		counter++;
		head = head->next;
	}
	return (counter - last_sel_i);
}

void decide_for_seq(t_list	*stack)
{
	int	spot;
	int	sm_head;
	int	sm_tail;
	int	sm_dist;
	int	prev_dist;
	t_list	*tmp;
	t_list	*prev_seq;

	tmp = stack;
	prev_dist = lst_size(stack);
	prev_seq = NULL;
	while (stack)
	{
		if (stack->selected == 2)
		{
			sm_head = smallest_dist_head(tmp, stack);
			sm_tail = smallest_dist_tail(tmp, stack);
			sm_dist = sm_head >  sm_tail ? sm_tail : sm_head;
			if (prev_dist > sm_dist)
			{
				prev_dist = sm_dist;
				if (!prev_seq)
					prev_seq = stack;
				else
				{
					prev_seq->selected = 0;
					prev_seq = stack;
				}
			}
		}
		stack = stack->next;
	}
}

void	lis(t_list *stack, int len)
{
		t_list	*tmp;
		t_list	*tmp_tmp;
		int		save_seq[len];
		int		maybe_seq[len];
		int		prev;
		int		counter;
		int		i;
	
		if (!stack)
			return ;
		prev = stack->content;
		tmp = stack;
		counter = 0;
		i = 0;
		while(tmp)
		{
			tmp_tmp = tmp;
			while(tmp_tmp)
			{
				if (tmp_tmp->content > prev)
				{
					prev = tmp_tmp->content;
					counter++;
				}
				tmp_tmp = tmp_tmp->next;
			}
			maybe_seq[i++] = counter;
			tmp = tmp->next;
		}
		i = 0;
		prev = 0;
		while (i < len)
		{
			if (prev < maybe_seq[i])
			{
				prev = maybe_seq[i++];
			}
		}
}

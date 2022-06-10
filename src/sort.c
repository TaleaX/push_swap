/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:50:38 by tdehne            #+#    #+#             */
/*   Updated: 2022/06/08 18:21:04 by tdehne           ###   ########.fr       */
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
		{
			shift_up(head_a);
			print_stack(*head_a, *head_b, SHIFT_UP_A);
		}
		else
		{
			shift_down(head_a);
			print_stack(*head_a, *head_b, SHIFT_DOWN_A);
		}
		(*counter)++;
	}
	push_b(head_a, head_b);
	print_stack(*head_a, *head_b, PUSH_B);
	(*counter)++;
	sort_stacks(head_a, head_b, smallest, counter);
}

/*int	smallest_dist_head(t_list *head)
{
	int	counter;

	counter = 0;
	while (head && !head->selected)
	{
		counter++;
		head = head->next;
	}
	return (counter);
}

int	smallest_dist_tail(t_list *head)
{
	int	counter;
	int	last_sel_i;

	counter = 0;
	while (head)
	{
		if (head->selected)
			last_sel_i = counter;
		counter++;
		head = head->next;
	}
	return (counter - last_sel_i);
}

t_list	*select_nodes(t_list **head, t_list *prev_smallest, int num_chosen)
{
	if (!prev_smallest)
	{
		while (num_chosen--)
		{
			prev_smallest = get_next_smallest_node(*head, prev_smallest);
			prev_smallest->selected = 1;
		}
		return (prev_smallest);
	}
	prev_smallest = get_next_smallest_node(*head, prev_smallest);
	prev_smallest->selected = 1;
	return (prev_smallest);
}

void	sort_b(t_list **head_b)
{
	t_list	*last;

	if (!*head_b || !(*head_b)->next)
		return ;
	last = lst_getlast(*head_b);
	if ((*head_b)->content < last->content)
		shift_up(head_b);
	else if ((*head_b)->content < (*head_b)->next->content)
		swap(head_b);
}

void	sort_stacks(t_list **head_a, t_list **head_b, t_list *prev_smallest, int *counter)
{
	t_list	*smallest;
	int		size;

	if (lst_size(*head_a) == 1)
		return ;
	size = lst_size(*head_a);
	//smallest = get_next_smallest_node(*head_a, prev_smallest);
	prev_smallest = select_nodes(head_a, prev_smallest, 3);
	//printf("%p\n", smallest);
	while (!(*head_a)->selected)
	{
		if (smallest_dist_head(*head_a) < smallest_dist_tail(*head_a))
			shift_up(head_a);
		else
			shift_down(head_a);
		(*counter)++;
	}
	push_b(head_a, head_b);
	sort_b(head_b);
	(*counter)++;
	sort_stacks(head_a, head_b, smallest, counter);
}*/
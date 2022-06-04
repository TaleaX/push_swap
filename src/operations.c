/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:18:28 by tdehne            #+#    #+#             */
/*   Updated: 2022/05/31 23:35:01 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **head)
{
	t_list	*tmp_next_next;
	t_list	*tmp_next;

	if (!(*head) || !head)
		return ;
	tmp_next_next = (*head)->next->next;
	tmp_next = (*head)->next;
	(*head)->next->next = *head;
	(*head)->next = tmp_next_next;
	*head = tmp_next;
}

void	shift_up(t_list **head)
{
	t_list *first;

	first = *head;
	lst_rm(head, *head);
	first->next = NULL;
	lst_add_back(head, first);
	
}

void	shift_down(t_list **head)
{
	t_list *last;

	last = lst_getlast(*head);
	lst_rm(head, last);
	lst_add_front(head, last);
	
}

void	push_b(t_list **head_a, t_list **head_b)
{
	t_list *first;

	first = *head_a;
	lst_rm(head_a, *head_a);
	lst_add_front(head_b, first);
}

void	push_a(t_list **head_a, t_list **head_b)
{
	t_list *first;

	first = *head_b;
	lst_rm(head_b, *head_b);
	lst_add_front(head_a, first);
}
/*void	shift_up(int *stack, int argc)
{
	int	first_elem;
	int	i;

	first_elem = stack[0];
	i = 0;
	while (i < argc - 2)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[argc - 2] = first_elem;
}

void	shift_down(int *stack, int argc)
{
	int	last_elem;

	last_elem = stack[argc - 2];
	while ((argc--) - 1)
		stack[argc - 1] = stack[argc - 2];
	stack[0] = last_elem;
}
*/
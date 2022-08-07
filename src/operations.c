/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:18:28 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/07 11:10:22 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_data *data)
{
	t_list	*tmp_next_next;
	t_list	*tmp_next;

	if (!(data->head_a))
		return ;
	tmp_next_next = data->head_a->next->next;
	tmp_next = data->head_a->next;
	data->head_a->next->next = data->head_a;
	data->head_a->next = tmp_next_next;
	data->head_a = tmp_next;
}

void	swap_b(t_data *data)
{
	t_list	*tmp_next_next;
	t_list	*tmp_next;

	if (!(data->head_b))
		return ;
	tmp_next_next = data->head_b->next->next;
	tmp_next = data->head_b->next;
	data->head_b->next->next = data->head_b;
	data->head_b->next = tmp_next_next;
	data->head_b = tmp_next;
}

void	shift_up_a(t_data *data)
{
	t_list *first;

	first = data->head_a;
	lst_rm(&data->head_a, data->head_a);
	first->next = NULL;
	lst_add_back(&data->head_a, first);
}

void	shift_up_b(t_data *data)
{
	t_list *first;

	first = data->head_b;
	lst_rm(&data->head_b, data->head_b);
	first->next = NULL;
	lst_add_back(&data->head_b, first);
}

void	shift_down_a(t_data *data)
{
	t_list *last;

	last = lst_getlast(data->head_a);
	lst_rm(&data->head_a, last);
	lst_add_front(&data->head_a, last);
}

void	shift_down_b(t_data *data)
{
	t_list *last;

	last = lst_getlast(data->head_b);
	lst_rm(&data->head_b, last);
	lst_add_front(&data->head_b, last);
}

void	push_b(t_data *data)
{
	t_list *first;

	first = data->head_a;
	lst_rm(&data->head_a, data->head_a);
	lst_add_front(&data->head_b, first);
}

void	push_a(t_data *data)
{
	t_list *first;

	first = data->head_b;
	lst_rm(&data->head_b, data->head_b);
	lst_add_front(&data->head_a, first);
}

/*void	push_a(t_list **head_a, t_list **head_b)
{
	t_list *first;

	first = *head_b;
	lst_rm(head_b, *head_b);
	lst_add_front(head_a, first);
}*/
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
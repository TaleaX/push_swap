/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:49:29 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/17 16:30:26 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_index(t_list *head)
{
	t_list	*greatest;
	t_list	*smallest;
	int		i;

	greatest = get_greatest(head);
	i = 0;
	smallest = NULL;
	while (greatest->index == -1)
	{
		smallest = get_next_smallest_node(head, smallest);
		smallest->index = i++;
	}
}

t_data	create_stack_lst(int len, char **parsed_argv)
{
	t_list	*stack;
	t_list	*head_a;
	t_list	*head_b;
	t_data	data;
	int		num;

	head_a = NULL;
	head_b = NULL;
	data.head_a = head_a;
	data.head_b = head_b;
	data.size_a = 0;
	while (len-- > 0)
	{
		num = ft_atoi(*(parsed_argv + len));
		stack = lst_new(num, 0, -1);
		lst_add_front(&data.head_a, stack);
	}
	add_index(data.head_a);
	data.size_a = lst_size(data.head_a);
	data.size_b = 0;
	return (data);
}

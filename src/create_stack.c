/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:49:29 by tdehne            #+#    #+#             */
/*   Updated: 2022/06/14 17:40:58 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_index(t_list *head)
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

t_list	*create_stack_lst(int argc, char **argv)
{
	t_list	*stack;
	t_list	*head;
	int		num;

	head = NULL;
	while (argc-- > 1)
	{
		num = ft_atoi(*(argv + argc));
		stack = lst_new(num, 0, -1);
		lst_add_front(&head, stack);
	}
	add_index(head);
	return (head);
}

/*int	*create_stack_arr(int argc, char **argv)
{
	int	*stack;
	int	num;
	int	i;

	stack = (int *)malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (i < argc - 1)
	{
		stack[i] = ft_atoi(*(argv + i + 1));
		i++;
	}
	return (stack);
}*/

int	*create_stack_arr(int argc, char **argv, int stack_a)
{
	int	*stack;
	int	num;

	stack = (int *)malloc(sizeof(int) * argc - 1);
	if (stack_a)
	{
		while (argc-- > 1)
		{
			num = ft_atoi(*(argv + argc));
			stack[argc - 1] = num;
		}
	}
	return (stack);
}

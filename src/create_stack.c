/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:49:29 by tdehne            #+#    #+#             */
/*   Updated: 2022/06/14 13:49:40 by tdehne           ###   ########.fr       */
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
		printf("index %d content %d", smallest->index, smallest->content);
		smallest->index = i++;
	}
}

t_list	*create_stack_lst(int argc, char **argv)
{
	t_list	*smallest;
	t_list	*stack;
	t_list	*head;
	//t_list	*greatest;
	int		num;
	//int		i;

	head = NULL;
	smallest = NULL;
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

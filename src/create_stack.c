/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:49:29 by tdehne            #+#    #+#             */
/*   Updated: 2022/06/09 06:59:30 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_stack_lst(int argc, char **argv)
{
	t_list	*stack;
	t_list	*head;
	int	num;

	head = NULL;
	while (argc-- > 1)
	{
		num = ft_atoi(*(argv + argc));
		stack = lst_new(num, 0);
		lst_add_front(&head, stack);
	}
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

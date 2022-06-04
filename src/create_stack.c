/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:49:29 by tdehne            #+#    #+#             */
/*   Updated: 2022/06/01 20:35:46 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_stack(int argc, char **argv)
{
	t_list	*stack;
	t_list	*head;
	int	num;

	head = NULL;
	while (argc-- > 1)
	{
		num = ft_atoi(*(argv + argc));
		stack = ft_lstnew(num);
		ft_lstadd_front(&head, stack);
	}
	return (head);
}

/*int	*create_stack(int argc, char **argv, int stack_a)
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
}*/

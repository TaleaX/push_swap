/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:49:29 by tdehne            #+#    #+#             */
/*   Updated: 2022/04/21 20:05:16 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_stack(int argc, char **argv)
{
	t_list	*stack;
	t_list	*head;
	int	num;
	int	len;

	len = argc - 1;
	head = NULL;
	while (len--)
	{
		num = ft_atoi(*(argv + len));
		stack = ft_lstnew(num);
		ft_lstadd_front(&head, stack);
	}
	return (head);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:08:53 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/03 11:50:39 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	push_swap(t_list **head_a, t_list **head_b, t_list *prev_smallest, int *counter)
{
	print_stack(*head_a, *head_b, 0);
	//sort_stacks(head_a, head_b, prev_smallest, counter);
	while (*head_b)
	{
		push_a(head_a, head_b);
		print_stack(*head_a, *head_b, PUSH_A);
		(*counter)++;
	}
	printf("counter = %d\n", *counter);
}*/

int	main(int argc, char **argv)
{
	//t_list			*head_a;
	//t_list			*head_b;
	//t_list			*smallest;
	//int				counter;
	//int				*stack;
	//int				i;
	t_data	data;
	int		group_size;
	int		c;
	operation		operations[3] = {swap, shift_up, shift_down};

	data = create_stack_lst(argc, argv);
	//head_b = NULL;
	c = 0;
	if (stack_a_sorted(data.head_a))
	{
		print_stack(data.head_a, data.head_b, 1);
		printf("It's sorted congrats!\n");
		return (1);
	}
	group_size = data.size_a / GROUPS;
	sort_big(data, operations, group_size, &c);
	printf("c = %d\n", c);
	//counter = 0;
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:08:53 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/16 14:03:49 by tdehne           ###   ########.fr       */
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

int check_limits(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > 10)
		return (0);
	while (*str)
	{
		
		str++;
	}
}

int error(int argc, char **argv)
{
	int	j;
	int	num;
	int	num2;

	while (argc-- > 1)
	{
		num = ft_atoi(*(argv + argc));
		if ((num == 0 && ft_strlen(*(argv + argc)) > 2) || (num == 0 && ft_strlen(*(argv + argc)) != 2 && (**(argv + argc) > '9' || **(argv + argc) < '0')))
			return (1);
		j = argc - 1;
		while (j-- > 1)
		{
			num2 = ft_atoi(*(argv + j));
			if (num == num2)
				return (1);
		}
	}
	return (0);
}

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
	int		groups;
	int		c;
	operation		operations[8] = {swap_a, swap_b, shift_up_a, shift_up_b, shift_down_a, shift_down_b, push_a, push_b};

	if (argc == 1)
		return (0);
	if (error(argc, argv))
	{
		printf("ERROR\n");
		return (0);
	}
	data = create_stack_lst(argc, argv);
	//head_b = NULL;
	c = 0;
	groups = 1;
	if (stack_a_sorted(data.head_a))
	{
		print_stack(data.head_a, data.head_b, ZERO_ALL);
		printf("It's sorted congrats!\n");
		return (0);
	}
	if(argc <= 4)
	{
		sort_three(&data, operations, &c);
		return (1);
	}
	if(argc <= 11)
	{
		sort_small(&data, operations, &c);
		return (1);
	}
	if (argc >= 500)
		groups = 17;
	else if (argc > 100)
		groups = 9;
	else if (argc > 50)
		groups = 9;
	else
		groups = 2;
	group_size = data.size_a / groups;
	sort_big(data, operations, group_size, &c);
	//counter = 0;
	return (0);
}
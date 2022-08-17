/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:08:53 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/17 15:21:54 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(int argc, char **argv)
{
	int	j;
	int	num;
	int	num2;

	while (argc-- > 1)
	{
		num = ft_atoi(*(argv + argc));
		if ((num == 0 && ft_strlen(*(argv + argc)) > 2)
			|| (num == 0 && ft_strlen(*(argv + argc)) != 2
				&& (**(argv + argc) > '9' || **(argv + argc) < '0')))
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

void	init_operations(t_operation operations[8], int *groups, int argc)
{
	operations[0] = swap_a;
	operations[1] = swap_b;
	operations[2] = shift_up_a;
	operations[3] = shift_up_b;
	operations[4] = shift_down_a;
	operations[5] = shift_down_b;
	operations[6] = push_a;
	operations[7] = push_b;
	if (argc >= 500)
		*groups = 17;
	else if (argc >= 100)
		*groups = 9;
	else if (argc > 50)
		*groups = 5;
	else
		*groups = 1;
}

void	decide_algo(t_data *data, t_operation operations[8], int argc, t_vars v)
{
	if (stack_a_sorted(data->head_a))
		return ;
	if (argc <= 4)
		sort_three(data, operations);
	else if (argc <= 6)
		sort_smaller_six(data, operations);
	else
		sort_big(data, operations, v);
}

int	main(int argc, char **argv)
{
	t_data		data;
	int			groups;
	t_vars		vars;
	t_operation	operations[8];

	if (argc == 1)
		return (0);
	if (error(argc, argv))
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	init_operations(operations, &groups, argc);
	data = create_stack_lst(argc, argv);
	vars.group_size = data.size_a / groups;
	decide_algo(&data, operations, argc, vars);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:32:58 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/18 09:01:12 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int	error(int len, char **argv)
{
	int			j;
	long long	num;
	long long	num2;

	while (len--)
	{
		num = ft_atoi(*(argv + len));
		if (num == GT_MAX_INT)
		{
			return (1);
		}
		j = len;
		while (j-- > 0)
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

void	decide_algo(t_data *data, t_operation operations[8], int len, t_vars v)
{
	if (stack_a_sorted(data->head_a))
		return ;
	if (len <= 3)
		sort_three(data, operations);
	else if (len <= 5)
		sort_smaller_six(data, operations);
	else
		sort_big(data, operations, v);
}

static void	free_all(char **arr, size_t i)
{
	while (i > 0)
		free(arr[i--]);
	free(arr[i]);
	free(arr);
}

int	main(int argc, char **argv)
{
	t_data			data;
	int				groups;
	t_vars			vars;
	t_operation		operations[8];
	t_vars_parse	vars_p;
	char			*str;

	vars_p.len = 0;
	if (argc <= 1)
		return (0);
	vars_p.nums = parse(argc, argv);
	vars_p.argv_parsed = ft_split(vars_p.nums, ' ');
	str = get_next_line(1);
	printf("%s\n", str);
	//vars_p.exec_push_swap = ft_strjoin_better(NULL, "../push_swap");
	while (vars_p.argv_parsed[vars_p.len])
	{
		vars_p.exec_push_swap = ft_strjoin_better(vars_p.exec_push_swap, vars_p.argv_parsed[vars_p.len]);
		vars_p.len++;	
	}
	if (error(vars_p.len, vars_p.argv_parsed))
	{
		write(3, "ERROR\n", 6);
		free_all(vars_p.argv_parsed, vars_p.len);
		return (0);
	}
	
	init_operations(operations, &groups, argc);
	data = create_stack_lst(vars_p.len, vars_p.argv_parsed);
	vars.group_size = data.size_a / groups;
	decide_algo(&data, operations, vars_p.len, vars);
	ft_lstclear2(&data.head_a);
	free(data.head_b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:32:58 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/18 13:53:01 by tdehne           ###   ########.fr       */
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

t_op	get_inp_op(char *input)
{
	printf("input = %s\n", input);
	if (ft_strncmp(input, "sa\n", 3) == 0)
		return (SWAP_A);
	if (ft_strncmp(input, "sb\n", 3) == 0)
		return (SWAP_B);
	if (ft_strncmp(input, "ss\n", 3) == 0)
		return (SS);
	if (ft_strncmp(input, "ra\n", 3) == 0)
		return (SHIFT_UP_A);
	if (ft_strncmp(input, "rb\n", 3) == 0)
		return (SHIFT_UP_B);
	if (ft_strncmp(input, "rr\n", 3) == 0)
		return (RR);
	if (ft_strncmp(input, "rra\n", 4) == 0)
		return (SHIFT_DOWN_A);
	if (ft_strncmp(input, "rrb\n", 4) == 0)
		return (SHIFT_DOWN_B);
	if (ft_strncmp(input, "rrr\n", 4) == 0)
		return (RRR);
	if (ft_strncmp(input, "pa\n", 3) == 0)
		return (PUSH_A);
	if (ft_strncmp(input, "pb\n", 3) == 0)
		return (PUSH_B);
	if (ft_strncmp(input, "\n", 1) == 0)
		return (EXEC);
	return (ZERO);
}

int	check_special_ops(t_data *data, t_operation operations[8], t_op op)
{
	if (op == SS)
	{
		operations[SWAP_A](data);
		operations[SWAP_B](data);
		return (1);
	}
	if (op == RR)
	{
		operations[SHIFT_UP_A](data);
		operations[SHIFT_UP_B](data);
		return (1);
	}
	if (op == RRR)
	{
		operations[SHIFT_DOWN_A](data);
		operations[SHIFT_DOWN_B](data);
		return (1);
	}
	return (0);
}

int	check_for_errors(t_data *data, t_op op)
{
	if (data->size_b == 0 && (op == SS || op == RR || op == RRR || op == SWAP_B
			|| op == SHIFT_DOWN_B || op == SHIFT_UP_B || op == PUSH_A))
		return (1);
	if (data->size_a == 0 && (op == SS || op == RR || op == RRR || op == SWAP_A
			|| op == SHIFT_DOWN_A || op == SHIFT_UP_A || op == PUSH_B))
		return (1);
	return (0);
}

int	exec(t_data *data, t_operation operations[8])
{
	char	*input;
	t_op	op;

	input = get_next_line(0);
	exit(0);
	while (input != NULL)
	{
		//write(1, "lol", 3);
		op = get_inp_op(input);
		write(1, "lol", 3);
		if (op == ZERO || check_for_errors(data, op))
			return (ERROR);
		if (op == EXEC)
			return (EXEC);
		/*if (check_special_ops(data, operations, op))
		{
			input = get_next_line(1);
			continue ;
		}*/
		if (op == PUSH_B)
		{
			data->size_a--;
			data->size_b++;
		}
		if (op == PUSH_A)
		{
			data->size_b--;
			data->size_a++;
		}
		operations[op](data);
		free(input);
		input = get_next_line(0);
	}
	return (1);
}

void	print_result(t_data data)
{
	if (stack_a_sorted(data.head_a) && data.size_b == 0)
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
}

int	main(int argc, char **argv)
{
	t_data			data;
	int				groups;
	//t_vars			vars;
	t_operation		operations[8];
	t_vars_parse	vars_p;
	//char			*str;

	vars_p.len = 0;
	if (argc <= 1)
		return (0);
	vars_p.nums = parse(argc, argv);
	vars_p.argv_parsed = ft_split(vars_p.nums, ' ');
	free(vars_p.nums);
	while (vars_p.argv_parsed[vars_p.len])
		vars_p.len++;
	if (error(vars_p.len, vars_p.argv_parsed))
	{
		write(3, "ERROR\n", 6);
		free_all(vars_p.argv_parsed, vars_p.len);
		return (0);
	}
	init_operations(operations, &groups, argc);
	data = create_stack_lst(vars_p.len, vars_p.argv_parsed);
	free_all(vars_p.argv_parsed, vars_p.len);
	if (exec(&data, operations) == ERROR)
	{
		write(1, "ERROR\n", 6);
		ft_lstclear2(&data.head_a);
		free(data.head_b);
		return (0);
	}
	print_result(data);
	//vars.group_size = data.size_a / groups;
	//decide_algo(&data, operations, vars_p.len, vars);
	ft_lstclear2(&data.head_a);
	free(data.head_b);
	return (0);
}

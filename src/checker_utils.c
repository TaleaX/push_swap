/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:27:20 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/18 18:34:01 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_op	get_inp_op(char *input)
{
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
	return (ZERO);
}

int	check_special_ops(t_data *data, t_operation operations[11], t_op op)
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

int	exec(t_data *data, t_operation operations[11])
{
	char	*input;
	t_op	op;

	input = get_next_line(0);
	while (input != NULL)
	{
		op = get_inp_op(input);
		if (op == ZERO)
		{
			write(2, "ERROR\n", 6);
			ft_lstclear2(&data->head_a);
			ft_lstclear2(&data->head_b);
			return (ERROR);
		}
		if (check_special_ops(data, operations, op))
		{
			input = get_next_line(0);
			continue ;
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
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

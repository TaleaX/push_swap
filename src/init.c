/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:11:48 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/22 13:54:00 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_operations(t_operation operations[11], int *groups, int argc)
{
	operations[0] = swap_a;
	operations[1] = swap_b;
	operations[2] = shift_up_a;
	operations[3] = shift_up_b;
	operations[4] = shift_down_a;
	operations[5] = shift_down_b;
	operations[6] = push_a;
	operations[7] = push_b;
	operations[8] = swap_both;
	operations[9] = shift_up_both;
	operations[10] = shift_down_both;
	if (argc >= 500)
		*groups = 17;
	else if (argc >= 100)
		*groups = 9;
	else if (argc > 50)
		*groups = 5;
	else
		*groups = 1;
}

void	decide_algo(t_data *data, t_operation operations[11], int len, t_vars v)
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

void	parse(int argc, char **argv, t_vars_parse *vars_p)
{
	char	*nums;
	int		i;

	i = 1;
	nums = ft_strjoin_better(NULL, *(argv + i));
	while (++i < argc)
		nums = ft_strjoin_better(nums, *(argv + i));
	vars_p->argv_parsed = ft_split(nums, ' ');
	free(nums);
}

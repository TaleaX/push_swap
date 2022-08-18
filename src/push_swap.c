/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:08:53 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/18 16:59:02 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	write_error(void)
{
	write(2, "ERROR\n", 6);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			data;
	int				groups;
	t_vars			vars;
	t_operation		operations[11];
	t_vars_parse	vars_p;

	vars_p.len = 0;
	if (argc <= 1)
		return (0);
	vars_p.nums = parse(argc, argv);
	if (!vars_p.nums)
		return (write_error());
	vars_p.argv_parsed = ft_split(vars_p.nums, ' ');
	free(vars_p.nums);
	while (vars_p.argv_parsed[vars_p.len])
		vars_p.len++;
	if (error(vars_p.len, vars_p.argv_parsed))
		return (write_error());
	init_operations(operations, &groups, argc);
	data = create_stack_lst(vars_p.len, vars_p.argv_parsed);
	free_all(vars_p.argv_parsed, vars_p.len);
	vars.group_size = data.size_a / groups;
	decide_algo(&data, operations, vars_p.len, vars);
	ft_lstclear2(&data.head_a);
	free(data.head_b);
	return (0);
}

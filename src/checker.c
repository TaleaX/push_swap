/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:32:58 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/18 17:17:40 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	write_error(void)
{
	write(2, "ERROR\n", 6);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			data;
	int				groups;
	t_operation		operations[8];
	t_vars_parse	vars_p;

	vars_p.len = 0;
	if (argc <= 1)
		return (0);
	vars_p.nums = parse(argc, argv);
	if (only_white_space(argc, argv))
		return (write_error());
	vars_p.argv_parsed = ft_split(vars_p.nums, ' ');
	free(vars_p.nums);
	while (vars_p.argv_parsed[vars_p.len])
		vars_p.len++;
	if (error(vars_p.len, vars_p.argv_parsed))
		return (0);
	init_operations(operations, &groups, argc);
	data = create_stack_lst(vars_p.len, vars_p.argv_parsed);
	free_all(vars_p.argv_parsed, vars_p.len);
	if (exec(&data, operations) == ERROR)
		return (0);
	print_result(data);
	//print_stack(data.head_a, data.head_b, ZERO);
	ft_lstclear2(&data.head_a);
	free(data.head_b);
	return (0);
}

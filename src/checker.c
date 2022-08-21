/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:32:58 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/21 11:36:30 by tdehne           ###   ########.fr       */
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
	t_operation		operations[11];
	t_vars_parse	vars_p;

	vars_p.len = 0;
	if (argc <= 1)
		return (0);
	if (only_white_space(argc, argv))
		return (write_error());
	parse(argc, argv, &vars_p);
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
	ft_lstclear2(&data.head_a);
	free(data.head_b);
	return (0);
}

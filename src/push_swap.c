/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:08:53 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/22 14:10:34 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (only_white_space(argc, argv))
		return (write_error());
	parse(argc, argv, &vars_p);
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

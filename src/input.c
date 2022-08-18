/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 20:15:51 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/18 08:46:05 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*parse(int argc, char **argv)
{
	char	*nums;
	int		i;

	i = 1;
	nums = ft_strjoin_better(NULL, *(argv + i));
	while (++i < argc)
	{
		nums = ft_strjoin_better(nums, *(argv + i));
	}
	return (nums);
}
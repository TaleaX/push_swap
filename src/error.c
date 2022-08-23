/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:37:25 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/22 14:09:55 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	write_error(void)
{
	write(2, "ERROR\n", 6);
	return (0);
}

int	only_white_space(int argc, char **argv)
{
	int		i;
	int		j;
	int		found;

	i = 1;
	while (i < argc)
	{
		j = 0;
		found = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
				found = 1;
			j++;
		}
		if (!found)
			return (1);
		i++;
	}
	return (0);
}

int	error(int len, char **argv_parsed)
{
	int			j;
	int			error;
	int			len_tmp;
	long long	num;
	long long	num2;

	error = 0;
	len_tmp = len;
	while (len_tmp--)
	{
		num = ft_atoi(*(argv_parsed + len_tmp));
		if (num == GT_MAX_INT)
			error = 1;
		j = len_tmp;
		while (j-- > 0)
		{
			num2 = ft_atoi(*(argv_parsed + j));
			if (num == num2)
				error = 1;
		}
	}
	if (error == 1)
		free_all(argv_parsed, len);
	return (error);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:18:46 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/17 18:42:48 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static long long	pow_of_a(int base, int exp)
{
	long long	result;

	result = 1;
	while (exp > 0)
	{
		result *= base;
		exp -= 1;
	}
	return (result);
}

static int	get_log_10(const char *nptr)
{
	int	counter;

	counter = 0;
	while (*nptr)
	{
		if (*nptr < '0' || *nptr > '9')
			break ;
		nptr++;
		counter++;
	}
	return (counter - 1);
}

static int	correct_prefix(const char **nptr, int *minus)
{
	while (**nptr == '\v' || **nptr == '\t' || **nptr == '\r'
		|| **nptr == '\n' || **nptr == '\f' || **nptr == ' ')
		(*nptr)++;
	if (**nptr == '+' || **nptr == '-')
	{
		if (**nptr == '-')
			*minus = 1;
		(*nptr)++;
	}
	if (**nptr < '0' || **nptr > '9')
		return (0);
	return (1);
}

long long	ft_atoi(const char *nptr)
{
	long long	result;
	int			minus;
	int			log_10;

	result = 0;
	minus = 0;
	if (!correct_prefix(&nptr, &minus))
		return (GT_MAX_INT);
	while (*nptr)
	{
		if (*nptr < '0' || *nptr > '9')
			break ;
		log_10 = get_log_10(nptr);
		/*if (!minus && ((result > 922337203685477580)
				|| (result == 922337203685477580 && *nptr > '7')))
			return (-1);
		if (minus && ((result > 922337203685477580)
				|| (result == 922337203685477580 && *nptr > '8')))
			return (0);*/
		if (!minus && ((result > 2147483640)
				|| (result == 2147483640 && *nptr > '7')))
			return (GT_MAX_INT);
		if (minus && ((result > 2147483640)
				|| (result == 2147483640 && *nptr > '8')))
			return (GT_MAX_INT);
		result += ((*nptr) - '0') * pow_of_a(10, log_10);
		nptr++;
	}
	if (*nptr)
	{
		return (GT_MAX_INT);
	}
	if (minus)
		result = result * (-1);
	return (result);
}

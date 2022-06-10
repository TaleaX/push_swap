/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:09:06 by tdehne            #+#    #+#             */
/*   Updated: 2022/06/06 13:53:35 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_arr(int *stack)
{
	int	tmp;

	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	shift_up_arr(int *stack, int len)
{
	int	first_elem;
	int	i;

	first_elem = stack[0];
	i = 0;
	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[len - 1] = first_elem;
}

void	shift_down_arr(int *stack, int len)
{
	int	last_elem;

	last_elem = stack[len - 1];
	while ((len--))
		stack[len] = stack[len - 1];
	stack[0] = last_elem;
}

/*int	*push_b(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	int *new;
	int	i;

	new = (int *)malloc(sizeof(int) * *len_a - 1);
	shift_down_arr(stack_b, *len_b);
	stack_b[0] = stack_a[0];
	i = 0;
	while (i < len_a - 1)
	{
		new[i] = stack_a[i + 1];
		i++;
	}
	free(stack_a);
	*stack_a = NULL;
	return (new);
}

int	*push_a(int *stack_a, int *stack_b, int len_a, int len_b)
{
	int *new;
	int	i;

	new = (int *)malloc(sizeof(int) * len_b - 1);
	shift_down_arr(stack_a, len_a);
	stack_b[0] = stack_a[0];
	i = 0;
	while (i < len_a - 1)
	{
		new[i] = stack_a[i + 1];
		i++;
	}
	free(stack_a);
	*stack_a = NULL;
	return (new);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 07:03:18 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/06 12:48:25 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_spot(t_data data, t_list *to_insert)
{
	int	index;

	index = 0;
	while (index < data.size_b - 1)
	{
		//printf("find spot \t content %d index %d\n", data.head_b->content, index);
		if (data.head_b->next->content < to_insert->content)
			return (index);
		index++;
		data.head_b = data.head_b->next;
	}
	return (index);
}

static void	push_back_all(t_data data, int *c)
{
	printf("in here\n");
	while (data.head_b)
	{
		push_a(&data.head_a, &data.head_b);
		//print_stack_dev(data.head_a, data.head_b, PUSH_A);
		(*c)++;
	}
}

static int		pre_check(t_data *data, operation operations[3], int index, int *c)
{
	if (stack_b_sorted(data->head_b))
		return (1);
	if (data->size_b == 2 || (data->size_b >= 3 && index == 1))
	{
		operations[0](&data->head_b);
		print_stack_dev(data->head_a, data->head_b, CONST_B);
		(*c)++;
		return (1);
	}
	/*if (index == data->size_b - 1)
	{
		printf("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n");
		operations[1](&data->head_b);
		print_stack_dev(data->head_a, data->head_b, CONST_B + 2);
		(*c)++;
		return (1);
	}*/
	return (0);
}

static t_op	check_double_sort(t_data *data, operation operations[3], t_min_op OP)
{
	int	index;

	if (!data->head_a)
		return (ZERO_ALL);
	index = find_sel_node_spot(data->head_a);
	if (index == 0)
		return (ZERO_ALL);
	if (index == 1)
	{
		operations[0](&data->head_a);
		return (SWAP_BOTH);
	}
	if (OP == SHIFT_DOWN && index > data->size_a / 2)
	{
		operations[OP](&data->head_a);
		return (SHIFT_DOWN_BOTH);
	}
	if (OP == SHIFT_UP && index < data->size_a / 2)
	{
		operations[OP](&data->head_a);
		return (SHIFT_UP_BOTH);
	}
	return (ZERO_ALL);
}

static void	pre_sort(t_data *data, operation operations[3], int counter, t_min_op OP, int *c)
{
	t_op	ALL_OP;

	ALL_OP = ZERO_ALL;
	while (counter--)
	{
		if (OP == 2)
		{
			operations[OP](&data->head_b);
			ALL_OP = check_double_sort(data, operations, OP);
			if (ALL_OP != ZERO_ALL)
				print_stack_dev(data->head_a, data->head_b, ALL_OP);
			else
				print_stack_dev(data->head_a, data->head_b, OP + CONST_B + OP);
			//print_stack_dev(data->head_a, data->head_b, OP + CONST_B + OP);
			operations[SWAP](&data->head_b);
			ALL_OP = check_double_sort(data, operations, SWAP);
			if (ALL_OP != ZERO_ALL)
				print_stack_dev(data->head_a, data->head_b, ALL_OP);
			else
				print_stack_dev(data->head_a, data->head_b, CONST_B);
			//print_stack_dev(data->head_a, data->head_b, CONST_B);
		}
		else
		{
			operations[SWAP](&data->head_b);
			ALL_OP = check_double_sort(data, operations, SWAP);
			if (ALL_OP != ZERO_ALL)
				print_stack_dev(data->head_a, data->head_b, ALL_OP);
			else
				print_stack_dev(data->head_a, data->head_b, CONST_B);
			//print_stack_dev(data->head_a, data->head_b, CONST_B);
			operations[OP](&data->head_b);
			ALL_OP = check_double_sort(data, operations, OP);
			if (ALL_OP != ZERO_ALL)
				print_stack_dev(data->head_a, data->head_b, ALL_OP);
			else
				print_stack_dev(data->head_a, data->head_b, OP + CONST_B + OP);
			//print_stack_dev(data->head_a, data->head_b, OP + CONST_B + OP);
		}
		(*c) += 2;
		//printf("index %d < size %d counter %d node content %d\n", index, data->size_b, counter, node_content);
	}
	if (OP == 1)
	{
		operations[SWAP](&data->head_b);
		ALL_OP = check_double_sort(data, operations, SWAP);
		if (ALL_OP != ZERO_ALL)
			print_stack_dev(data->head_a, data->head_b, ALL_OP);
		else
			print_stack_dev(data->head_a, data->head_b, CONST_B);
	}
}

static void	sort_b(t_data *data, operation operations[3], int *c)
{
	t_min_op	OP;
	int			counter;
	int			index;

	index = find_spot(*data, data->head_b);
	//printf("data size b %d index %d head %d\n", data->size_b, index, data->head_b->content);
	printf("index = %d head %d\n", index, data->head_b->content);
	if (pre_check(data, operations, index, c))
		return ;
	OP = 1;
	counter = index - 1;
	if (index > (data->size_b / 2)) //if data->size_b % 2 == 0 index >= ... ; else index > ...
	{
		counter = data->size_b - index - 1;
		OP = 2;
	}
	pre_sort(data, operations, counter, OP, c);
	OP ^= 3; //OP = (OP == 1) ? 2 : 1;
	printf("\nOP = %d\n", OP);
	if (OP == 1)
		counter++;
	while (counter--)
	{
		operations[OP](&data->head_b);
		print_stack_dev(data->head_a, data->head_b, OP + CONST_B + OP);
		(*c)++;
	}
}

static void	select_next(t_data *data, int max_index)
{
	t_list	*node;

	if (!data->head_a)
		return ;
	node = smallest_dist_head(data->head_a, max_index) < smallest_dist_tail(data->head_a, max_index) ? first_node_head(data->head_a, max_index) : first_node_tail(data->head_a, max_index);
	node->selected = 1;
}

static void	sorting_alg(t_data *data, operation operations[3], int *max_index, int *counter, int group_size, int *c)
{
	t_min_op	OP;

	OP = ZERO;
	if (OP == ZERO)
		OP = smallest_dist_head(data->head_a, *max_index) < smallest_dist_tail(data->head_a, *max_index) ? SHIFT_UP : SHIFT_DOWN;
	if (data->head_a->index <= *max_index)
	{
		push_b(&data->head_a, &data->head_b);
		printf("----PUSH TO B---------\n");
		print_stack_dev(data->head_a, data->head_b, PUSH_B);
		data->size_b++;
		data->size_a--;
		(*counter)++;
		OP = ZERO;
		if (*counter > *max_index)
			(*max_index) += group_size - 1;
		select_next(data, *max_index);
		sort_b(data, operations, c);
	}
	else
	{
		operations[OP](&data->head_a);
		print_stack_dev(data->head_a, data->head_b, OP + CONST_A + OP);
	}
}

static void	sort_big(t_data data, operation operations[3], int group_size, int *c)
{
	int		counter;
	int		max_index;

	counter = 0;
	max_index = group_size - 1;
	if (!data.head_a)
		return ;
	while (data.size_a)
	{
		sorting_alg(&data, operations, &max_index, &counter, group_size, c);
		(*c)++;
	}
	if (stack_b_sorted(data.head_b))
		push_back_all(data, c);
	else
		printf("not sorted\n");
}
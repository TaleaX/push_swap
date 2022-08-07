/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 07:03:18 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/07 16:49:28 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_spot(t_data data, t_list *to_insert)
{
	int	index;

	index = 0;
	while (index < data.size_a)
	{
		//printf("find spot \t content %d index %d\n", data.head_a->content, index);
		if (data.head_a->content > to_insert->content)
			return (index);
		index++;
		data.head_a = data.head_a->next;
	}
	return (index);
}

int		pre_check(t_data *data, operation operations[8], int index, int *c)
{
	if (index == 0)
	{
		operations[PUSH_A](data);
		data->size_a++;
		data->size_b--;
		print_stack_dev(data->head_a, data->head_b, PUSH_A);
		(*c)++;
		return (1);
	}
	if (data->size_a >= 3 && index == 1)
	{
		operations[PUSH_A](data);
		data->size_a++;
		data->size_b--;
		print_stack_dev(data->head_a, data->head_b, PUSH_A);
		operations[SWAP_A](data);
		print_stack_dev(data->head_a, data->head_b, SWAP_A);
		(*c) += 2;
		return (1);
	}
	if (data->size_a == 2 && data->head_a->index == 1)
	{
		operations[SWAP_A](data);
		print_stack_dev(data->head_a, data->head_b, SWAP_A);
		(*c)++;
		return (1);
	}
	if (index == data->size_a)
	{
		operations[PUSH_A](data);
		data->size_a++;
		data->size_b--;
		print_stack_dev(data->head_a, data->head_b, PUSH_A);
		operations[SHIFT_UP_A](data);
		print_stack_dev(data->head_a, data->head_b, SHIFT_UP_A);
		(*c) += 2;
		return (1);
	}
	return (0);
}

void	adjust_a(t_data *data, operation operations[3], int counter, t_min_op OP, int *c)
{
	while(counter-- > 0)
	{
		//printf("counter %d\n", counter);
		operations[OP](data);
		print_stack_dev(data->head_a, data->head_b, OP);
		(*c)++;
	}
}

int	check_to_push(t_data *data, operation operations[8], int *c)
{
	int	index_first;
	int	index_sec;
	t_list	*last_a;

	index_first = find_spot(*data, data->head_b);
	if (!data->head_a || !data->head_b->next)
		return (1);
	index_sec = find_spot(*data, data->head_b->next);
	last_a = lst_getlast(data->head_a);
	if (index_sec == 0 && data->head_b->next->index > last_a->index)
	{
		if (index_first == 0 && data->head_b->index > last_a->index && data->head_b->index > data->head_b->next->index)
			return (1);
		operations[SWAP_B](data);
		print_stack_dev(data->head_a, data->head_b, SWAP_B);
		(*c)++;
		return (1);
	}
	if (index_first == 0 && data->head_b->index > last_a->index)
		return (1);
	return (0);
}

void	sort_a(t_data *data, operation operations[3], int *c)
{
	t_min_op	OP;
	t_min_op	AFTER_PUSH;		
	int			index;
	int			counter;
	int			first_pa;
	int			init;

	
	OP = ZERO;
	AFTER_PUSH = ZERO;
	first_pa = 0;
	init = 0;
	index = 1;
	while (data->size_b)
	{
		index = find_spot(*data, data->head_b);
		/*if (data->size_b > 1 && data->head_b->content < data->head_b->next->content)
		{
			OP = SWAP_B;
			operations[OP](data);
			print_stack_dev(data->head_a, data->head_b, OP);
			(*c)++;
			continue ;
		}*/
		if (!first_pa && pre_check(data, operations, index, c))
			continue ;
		if (!first_pa)
		{
			counter = index;
			OP = SHIFT_UP_A;
			if (index > (data->size_a / 2)) //if data->size_b % 2 == 0 index >= ... ; else index > ...
			{
				counter = data->size_a - index;
				OP = SHIFT_DOWN_A;
			}
			AFTER_PUSH = OP;
		}
		if (!first_pa)
			adjust_a(data, operations, counter, OP, c);
		if (check_to_push(data, operations, c))
		{
			OP = PUSH_A;
			if (!first_pa)
			{
				AFTER_PUSH ^= 6; //OP = (OP == 2) ? 4 : 2;
				first_pa ^= 1;
			}
			if (AFTER_PUSH == SHIFT_UP_A)
				counter++;
			data->size_a++;
			data->size_b--;
		}
		else if (first_pa)
		{
			OP = AFTER_PUSH;
			counter--;
		}
		if (counter == 0)
			first_pa ^= 1;
		operations[OP](data);
		print_stack_dev(data->head_a, data->head_b, OP);
		(*c)++;
	}
	OP = AFTER_PUSH;
	printf("OP %d counter = %d\n", OP, counter);
	while (counter--)
	{
		operations[OP](data);
		print_stack_dev(data->head_a, data->head_b, OP);
		(*c)++;
	}
}

void	pre_sort_b(t_data *data, operation operations[8], t_min_op OP, int group_size, int *c)
{
	int	max_index;
	int	counter;

	max_index = group_size - 1;
	counter = 0;
	while (data->size_a)
	{
		if (OP == PUSH_B)
			OP = smallest_dist_head(data->head_a, max_index) < smallest_dist_tail(data->head_a, max_index) ? SHIFT_UP_A : SHIFT_DOWN_A;
		if (data->head_a->index <= max_index)
		{
			OP = PUSH_B;
			printf("----PUSH TO B---------\n");
			data->size_b++;
			data->size_a--;
			(counter)++;
			if (counter > max_index)
				(max_index) += group_size - 1;
		}
		operations[OP](data);
		print_stack_dev(data->head_a, data->head_b, OP);
		(*c)++;
	}
}

void	sort_big(t_data data, operation operations[8], int group_size, int *c)
{
	t_min_op	OP;

	OP = PUSH_B;
	if (!data.head_a)
		return ;
	pre_sort_b(&data, operations, OP, group_size, c);
	sort_a(&data, operations, c);
	//print_stack(data.head_a, data.head_b, ZERO_ALL);
	/*if (stack_b_sorted(data.head_b))
		push_back_all(data, c);
	else
		printf("not sorted\n");*/
}

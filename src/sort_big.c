/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 07:03:18 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/03 12:30:24 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
/*void	sort_b(t_list **head_b, operation operations[3])
{
	while (!is_rev_sorted(*head_b))
	{
		
	}
	return ;
}*/

/*void	sort_big(t_data data, operation operations[3], int max_index)
{
	t_min_op	OP;
	t_list		*tmp;
	int			counter;

	if (!(*data.head_a) || !data.head_a)
		return ;
	tmp = *data.head_a;
	while (data.size_a > 1)
	{
		OP = smallest_dist_head(tmp, max_index) < smallest_dist_tail(tmp, max_index) ? 1 : 2;
		while ((*data.head_a)->index > max_index)
			operations[OP](data.head_a);
		push_b(data.head_a, data.head_b);
		counter++;
		data.size_a--;
		if (counter >= max_index)
			max_index += max_index;
		print_stack(*data.head_a, *data.head_b, OP);
	}
}*/

int	find_spot(t_data data, t_list *to_insert)
{
	int	index;

	index = data.size_b - 1;
	while (index && data.head_b->next)
	{
		printf("find spot \t content %d index %d\n", data.head_b->content, index);
		if (data.head_b->next->content < to_insert->content)
			return (index);
		index--;
		data.head_b = data.head_b->next;
	}
	return (index);
}

void	push_back_all(t_data data, int *c)
{
	while (data.head_b)
	{
		push_a(&data.head_a, &data.head_b);
		print_stack(data.head_a, data.head_b, 1);
		(*c)++;
	}
}

void	sort_b(t_data *data, operation operations[3], int *c)
{
	t_min_op	OP;
	int			counter;
	int			counter_cp;
	int			index;
	int			node_content;

	if (stack_b_sorted(data->head_b))
		return ;
	index = find_spot(*data, data->head_b);
	node_content = data->head_b->content;
	printf("size %d index %d head b %d\n", data->size_b, index, data->head_b->content);
	if (data->size_b == 2 || (data->size_b == 3 && index == 1))
	{
		operations[0](&data->head_b);
		return ;
	}
	if (index == 0)
	{
		operations[1](&data->head_b);
		return ;
	}
	if (index < data->size_b / 2)
	{
		counter = index;
		OP = 2;
	}
	else
	{
		counter = data->size_b - index - 1;
		OP = 1;
	}
	counter_cp = counter;
	printf("index %d < size %d counter %d\n", index, data->size_b, counter);
	//printf("size %d index %d\n", data->size_b, data->head_b->index);
	while (counter--)
	{
		if (OP == 2)
		{
			operations[OP](&data->head_b);
			operations[0](&data->head_b);
			
		}
		else
		{
			operations[0](&data->head_b);
			operations[OP](&data->head_b);
		}
		(*c) += 2;
		printf("index %d < size %d counter %d node content %d\n", index, data->size_b, counter, node_content);
		print_stack(data->head_a, data->head_b, 1);
	}
	//print_stack(data->head_a, data->head_b, 1);
	OP = (OP == 1) ? 2 : 1;
	while (counter_cp--)
	{
		operations[OP](&data->head_b);
		(*c)++;
	}
	printf("index %d < size %d counter %d node content %d\n", index, data->size_b, counter, node_content);
	print_stack(data->head_a, data->head_b, 1);
}

void	sort_big(t_data data, operation operations[3], int group_size, int *c)
{
	int		counter;
	int		max_index;
	t_min_op	OP;

	counter = 0;
	max_index = group_size - 1;
	if (!data.head_a)
		return ;
	OP = 4;
	print_stack(data.head_a, data.head_b, 1);
	while (data.size_a)
	{
		if (OP == 4)
			OP = smallest_dist_head(data.head_a, max_index) < smallest_dist_tail(data.head_a, max_index) ? 1 : 2;
		if (data.head_a->index <= max_index)
		{
			push_b(&data.head_a, &data.head_b);
			data.size_b++;
			sort_b(&data, operations, c);
			counter++;
			data.size_a--;
			OP = 4;
		}
		else
		{
			operations[OP](&data.head_a);
			printf("in else\n");
		}	
		if (counter > max_index)
			max_index += group_size;
		(*c)++;
		printf("\n-------------------in sort big------------------\n");
		//print_stack(data.head_a, data.head_b, 1);
		printf("\n-------------------after sort big------------------\n");
	}
	if (stack_b_sorted(data.head_b))
	{
		printf("in here\n");
		push_back_all(data, c);
	}
	printf("-----------THE END--------------\n");
	printf("group_size %d", group_size);
	print_stack(data.head_a, data.head_b, 1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:37:15 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/11 16:38:50 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_data *data, operation operations[8], int *c)
{
	if (data->size_a == 2 || (data->head_a->index < data->head_a->next->index && data->head_a->index  < data->head_a->next->next->index))
	{
		operations[SWAP_A](data);
		print_stack_dev(data->head_a, data->head_b, SWAP_A);
		(*c)++;
	}
	if ((data->head_a->index > data->head_a->next->index && data->head_a->index < data->head_a->next->next->index))
	{
		operations[SWAP_A](data);
		print_stack_dev(data->head_a, data->head_b, SWAP_A);
		(*c)++;
	}
	if (data->head_a->index > data->head_a->next->index && data->head_a->index > data->head_a->next->next->index)
	{
		operations[SHIFT_UP_A](data);
		print_stack_dev(data->head_a, data->head_b, SHIFT_UP_A);
		(*c)++;
	}
	if (data->head_a->index < data->head_a->next->index && data->head_a->index > data->head_a->next->next->index)
	{
		operations[SHIFT_DOWN_A](data);
		print_stack_dev(data->head_a, data->head_b, SHIFT_DOWN_A);
		(*c)++;
	}
}

/*void	sort_small(t_data *data, operation operations[3], int *c)
{
	while (!stack_a_sorted(data->head_a))
	{
		sort(data, operations, c);
	}
}

void sort_semi_small(t_data	*data, operation operations[3], int *c)
{
	t_list		*first;
	t_list		*second;
	t_list		*last;
	t_min_op	OP;

	first = data->head_a;
	second = data->head_a->next;
	last = 	lst_getlast(data->head_a);

	if (first->index < second->index && first->index > second->index)
	{
		if (last->index < data->size_a / 2)
			OP = SHIFT_DOWN;
		else
			OP = SHIFT_UP;
		operations[OP];
		print_stack_dev(data->head_a, data->head_b, CONST_A + OP * 2);
	}
}*/

void	mark_subseq(t_list *sub_seq_start, t_data data, int counter)
{
	t_list	*head_a;

	head_a = data.head_a;
	if (counter <= data.size_a / 2)
		return ;
	while (head_a)
	{
		//printf("head a %p sub seq %p\n", head_a, sub_seq_start);
		if (head_a == sub_seq_start && counter--)
		{
			head_a->selected = 1;
			sub_seq_start = sub_seq_start->next;
		}
		else
			head_a->selected = 0;
		head_a = head_a->next;
	}
}

t_list	*get_sub_seq(t_data data)
{
	t_list	*sub_seq;
	t_data	tmp_data;
	t_list	*tmp_sub_seq;
	int		max;
	int		tmp_max;
	int		init;

	max = 1;
	tmp_max = 1;
	init = 1;
	tmp_data = data;
	while (data.head_a->next)
	{
		if (data.head_a->index < data.head_a->next->index && data.head_a->next->index - data.head_a->index == 1)
		{
			if (init)
			{
				tmp_sub_seq = data.head_a;
				init = 0;
			}
			tmp_max++;
		}
		else
		{
			tmp_max = 1;
			init = 1;
		}
		if (max < tmp_max)
		{
			max = tmp_max;
			sub_seq = tmp_sub_seq;
		}
		data.head_a = data.head_a->next;
	}
	if (max > data.size_a / 2)
	{
		data.size_sel = max;
		mark_subseq(sub_seq, tmp_data, max);
	}
	else
		data.size_sel = 0;
	return (sub_seq);
}

t_min_op	get_op(t_data *data)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = data->head_a;
	second = data->head_a->next;
	last = lst_getlast(data->head_a);
	if (data->size_a == 2)
		return (SWAP_A);
	if (first->index > second->index && first->index > last->index && second->index > last->index)
	{
		if (!second->selected)
			return (SWAP_A);
		return (SHIFT_DOWN_A);
	}
	if (first->index > second->index && first->index > last->index && second->index < last->index)
	{
		if (last->index - second->index == 1 && first->index - last->index != 1)
			return (PUSH_B);
		if (last->index < data->size_a / 2)
			return (SHIFT_DOWN_A);
		return (SHIFT_UP_A);
	}
	if (first->index > second->index && first->index < last->index)
	{
		if (!second->selected && last->index - first->index != 1)
			return (SWAP_A); // return (PUSH_B)
		return (SHIFT_DOWN_A);
	}
	if (first->index < second->index && first->index > last->index)
	{
		if (data->size_a != 3 && !first->selected) //first->index >= data->size_a / 2 && 
			return (SHIFT_UP_A);
		return (SHIFT_DOWN_A);
	}
	if (first->index < second->index && first->index < last->index && second->index < last->index)
	{
		if (!second->selected && last->index - second->index == 1) //data->size_sel < data->size_a / 2 necessary?
			return (SWAP_A);
		if (first->index <= data->size_a / 2 && !first->selected)
			return (PUSH_B);
		return (SHIFT_DOWN_A);
	}
	if (first->index < second->index && first->index < last->index && second->index > last->index)
	{
		if (first->index <= data->size_a / 2 && !first->selected && last->index - first->index != 1) //  && second->index > data->size_a / 2 necessary?
			return (PUSH_B);
		if (second->index > data->size_a / 2 &&  last->index > data->size_a / 2 && !second->selected && last->index - first->index != 1)
			return (SWAP_A);
		return (SHIFT_DOWN_A);
	}
}

void	sort_small(t_data *data, operation operations[8], int *c)
{
	t_min_op	OP;
	t_list		*start_sub_seq;
	int			max;
	int			index;

	printf("----START-----\n");
	print_stack_dev(data->head_a, data->head_b, OP);
	while (!stack_a_sorted(data->head_a))
	{
		start_sub_seq = get_sub_seq(*data);
		//print_stack_dev(start_sub_seq, data->head_b, OP);
		//printf("data size el %d\n", data->size_sel);
		OP = get_op(data);
		operations[OP](data);
		print_stack_dev(data->head_a, data->head_b, OP);
		(*c)++;
		if (OP == PUSH_B)
		{
			data->size_a--;
			data->size_b++;
			//exit(0);
		}
		//sort(data, operations, c);
	}
	/*while (data->size_b > 0)
	{
		index = find_spot(*data, data->head_b);
		operations[PUSH_A](data);
		print_stack_dev(data->head_a, data->head_b, OP);
		(*c)++;
		data->size_a++;
		data->size_b--;
		if (index == data->size_a)
		{
			operations[SHIFT_UP_A](data);
			print_stack_dev(data->head_a, data->head_b, OP);
			(*c)++;
		}
	}*/
	sort_A(data, operations, c);
	printf("OPS %d\n", *c);
	printf("----END-----\n");
}

void	sort_three(t_data *data, operation operations[8], int *c)
{
	printf("-----------START-----------\n");
	print_stack_dev(data->head_a, data->head_b, ZERO_ALL);
	while (!stack_a_sorted(data->head_a))
	{
		sort(data, operations, c);
	}
	printf("------------END-------------\n");
}
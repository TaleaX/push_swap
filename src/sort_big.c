/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 07:03:18 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/14 13:40:17 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_spot(t_data data, t_list *to_insert)
{
	int	index;
	int	smaller;

	index = 0;
	smaller = 0;
	while (index < data.size_a)
	{
		//printf("find spot \t content %d index %d\n", data.head_a->content, index);
		if (data.head_a->content > to_insert->content)
			break ;
		index++;
		data.head_a = data.head_a->next;
	}
	/*while (data.head_a)
	{
		if (data.head_a->content < to_insert->content)
			smaller++;
		data.head_a = data.head_a->next;
	}
	if (smaller)
	{
		index = data.size_a - smaller;
	}*/
	return (index);
}

int	find_hidden_spot(t_data data, t_list *to_insert)
{
	int	greater;
	int	smaller;
	int	index;
	t_list	*last_a;
	t_list	*smallest;
	t_list	*greatest;

	greater = 0;
	smaller = 0;
	if (!data.head_a)
		return (0);
	last_a = lst_getlast(data.head_a);
	smallest = lst_get_smallest(data.head_a);
	greatest = lst_get_greatest(data.head_a);
	index = find_node_spot(data.head_a, smallest);
	/*while (index < data.size_a)
	{
		//printf("find spot \t content %d index %d\n", data.head_a->content, index);
		if (data.head_a->content > to_insert->content)
			break ;
		index++;
		data.head_a = data.head_a->next;
	}*/
	if (index == 0 && to_insert->index < smallest->index)
		return (0);
	if (index == 0 && to_insert->index > last_a->index)
		return (data.size_a);
	while (data.head_a && data.head_a->index > to_insert->index && last_a->index > to_insert->index)
	{
		if (data.head_a == smallest && to_insert->index < smallest->index)
			break ;
		greater++;
		data.head_a = data.head_a->next;
	}
	while (data.head_a && data.head_a->index < to_insert->index)
	{
		if (data.head_a == greatest && to_insert->index > greatest->index)
			break ;
		smaller++;
		data.head_a = data.head_a->next;
	}
	index = data.size_a - greater - smaller;
	return (data.size_a - index);
}

int		pre_check(t_data *data, operation operations[8], int index, int *c)
{
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

/*int	check_to_push(t_data *data, int counter_forth, int counter_back)
{
	int	index_first;
	t_list	*last_a;

	if (!data->head_b)
		return (PASS);
	if (!data->head_a)
		return (PUSH);
	index_first = find_spot(*data, data->head_b);
	last_a = lst_getlast(data->head_a);
	if (index_first == 0 && data->head_b->index > last_a->index) //  && data->head_b->index > last_a->index
		return (PUSH);
	if (index_first == 0 && counter_back == 0 & counter_forth == 0)
		return (PUSH);
	return (PASS);
}*/

int	check_to_push(t_data *data)
{
	int	index_first;
	t_list	*last_a;

	if (!data->head_b)
		return (PASS);
	if (!data->head_a)
		return (PUSH);
	index_first = find_spot(*data, data->head_b);
	last_a = lst_getlast(data->head_a);
	if (index_first == 0 && data->head_b->index > last_a->index) //  && data->head_b->index > last_a->index
		return (PUSH);
	/*if (index_first == 0 && counter_back == 0 & counter_forth == 0)
		return (PUSH);*/
	return (PASS);
}

int	push_second(t_data *data)
{
	int	index_first;
	int	index_sec;
	t_list	*last_a;

	if (!data->head_b || !data->head_b->next)
		return (PASS);
	index_first = find_spot(*data, data->head_b);
	index_sec = find_spot(*data, data->head_b->next);
	if (!data->head_a && index_sec > index_first)
		return (PUSH);
	if (!data->head_a)
		return (PASS);
	last_a = lst_getlast(data->head_a);
	if (index_sec == 0 && data->head_b->next->index > last_a->index)
	{
		if (index_first == 0 && data->head_b->index > data->head_b->next->index)
			return (PASS);
		return (PUSH);
	}
	/*if (index_sec > data->size_a / 2)
		index_sec = data->size_a - index_sec;
	if (index_first > data->size_a / 2)
		index_first = data->size_a - index_first;
	if (index_sec < index_first)
		return (PUSH);*/
	return (PASS);
}

void	before_push(t_data *data, operation operations[8], t_min_op OP, int counter, int index, int *c)
{
	printf("BEEEEFORE c %d i %d sizeA %d sizeB %d\n", counter, index, data->size_a, data->size_b);
	if (data->size_a == 0 || data->size_a == 1 || index == 1)
		return ;
	while(counter--)
	{
		/*if (push_second(data) == PUSH)
		{
			operations[SWAP_B](data);
			print_stack_dev(data->head_a, data->head_b, SWAP_B);
			operations[PUSH_A](data);
			print_stack_dev(data->head_a, data->head_b, PUSH_A);
			data->size_a++;
			data->size_b--;
			counter++;
			(*c) += 2;
		}*/
		operations[OP](data);
		print_stack_dev(data->head_a, data->head_b, OP);
		(*c)++;
	}
}

void	after_push(t_data *data, operation operations[8], t_min_op OP, int counter, int index, int *c)
{
	int	add_count;
	int	start_count;
	int	hidden_spot;

	start_count = counter;
	OP ^= 6;
	if (OP == SHIFT_UP_A)
		(counter)++;
	printf("AAAAAAAAAAAAAAAAAAFTER PUSH counter %d index %d data size %d OP = %d\n", counter, index, data->size_a, OP);
	while (counter)
	{
		/*if (counter > data->size_a / 2 && OP == SHIFT_UP_A)
		{
			OP = SHIFT_DOWN_A;;
			counter = data->size_a - counter;
		}*/
		//index = find_spot(*data, data->head_b);
		//hidden_spot = index;
		printf("index %d data->size_a %d size b %d OP %d counter %d\n", index, data->size_a, data->size_b, counter);
		if (push_second(data) == PUSH)
		{
			operations[SWAP_B](data);
			(*c)++;
			print_stack_dev(data->head_a, data->head_b, SWAP_B);
		}
		if (check_to_push(data) == PUSH)
		{
			operations[PUSH_A](data);
			data->size_a++;
			data->size_b--;
			if (OP == SHIFT_UP_A)
				(counter)++;
			(*c)++;
			print_stack_dev(data->head_a, data->head_b, PUSH_A);
		}
		/*else if (hidden_spot > (data->size_a / 2) && OP ==  SHIFT_UP_A)
		{
			//printf("hidden spot %d\n", hidden_spot);
			add_count = data->size_a - hidden_spot - 1;
			before_push(data, operations, SHIFT_DOWN_A, add_count, index, c);
			if ((data->size_a / 2) < data->size_a - start_count - add_count)
			{
				//printf("______________________LOL____________________________________\n");
				OP = SHIFT_DOWN_A;
				counter = data->size_a - start_count - add_count;
			}
			//printf("__________________________________________________________\n");
		}*/
		else
		{
			operations[OP](data);
			(*c)++;
			counter--;
			print_stack_dev(data->head_a, data->head_b, OP);
		}
	}
}

int check_double_swap(t_data *data)
{
	int	index_first;
	int	index_sec;
	t_list	*last_a;

	if (!data->head_a || !data->head_b || !data->head_b->next)
		return (0);
	index_first = find_spot(*data, data->head_b);
	last_a = lst_getlast(data->head_a);
	index_sec = find_spot(*data, data->head_b->next);
	/*if (index_first > ((data->size_a / 2) + 1))
		index_first = data->size_a - index_first;
	if (index_sec > ((data->size_a / 2) + 1))
		index_sec = data->size_a - index_sec;
	if (data->head_b->index < data->head_b->next->index && index_first >= index_sec)
		return (1);*/
	if (data->head_b->index < data->head_b->next->index)
	{
		return (1);
	}
	return (0);
}

void sort_A(t_data *data, operation operations[8], int *c)
{
	t_min_op	OP;
	int			index;
	int			counter;
	t_list		*last_a;

	while (data->size_b)
	{
		index = find_hidden_spot(*data, data->head_b);
		printf("FIRST index %d\n", index);
		counter = index;
		OP = SHIFT_UP_A;
		if (index > (data->size_a / 2)) //if data->size_b % 2 == 0 index >= ... ; else index > ...
		{
			counter = data->size_a - index;
			OP = SHIFT_DOWN_A;
		}
		before_push(data, operations, OP, counter, index, c);
		//printf("first push\n");
		operations[PUSH_A](data);
		data->size_a++;
		data->size_b--;
		(*c)++;
		print_stack_dev(data->head_a, data->head_b, PUSH_A);
		if (data->size_a >= 2 && index == 1)
		{
			operations[SWAP_A](data);
			(*c)++;
			print_stack_dev(data->head_a, data->head_b, SWAP_A);
			if (check_double_swap(data))
			{
				//printf("\nWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n");
				operations[SWAP_B](data);
				//(*c)++;
				print_stack_dev(data->head_a, data->head_b, SWAP_B);
			}
			continue ;
		}
		after_push(data, operations, OP, counter, index, c);
		printf("size b %d\n", data->size_a);
	}
}

/*void sort_A(t_data *data, operation operations[8], int *c)
{
	t_min_op	OP;
	t_min_op	OP_TMP;
	int			index;
	int			hidden_index;
	int			counter_forth;
	int			counter_back;
	int			counter_tmp;
	int			init_back;
	int			init_tmp;
	t_list		*last_a;

	counter_back = 0;
	counter_forth = 0;
	while (data->size_b)
	{
		index = find_hidden_spot(*data, data->head_b);
		if (!counter_forth && !counter_back)
		{
			init_back = 0;
			init_tmp = 0;
			counter_forth = index;
			counter_back = counter_forth;
			OP = SHIFT_UP_A;
			/*if (index == 0)
				OP = ZERO;
			printf("index %d\n", index);
			if (index > (data->size_a / 2)) //if data->size_b % 2 == 0 index >= ... ; else index > ...
			{
				printf("in if index %d\n", index);
				counter_forth = data->size_a - index;
				counter_back = counter_forth;
				OP = SHIFT_DOWN_A;
			}
		}
		printf("FIRST index %d counter forth %d counter back %d OP = %d\n", index, counter_forth, counter_back, OP);

		if (!counter_forth && !init_back) //
		{
			OP ^= 6;
			OP_TMP = OP;
			init_back = 1;
		}
		if (data->size_a >= 1 && index == 1)
		{
			operations[PUSH_A](data);
			data->size_a++;
			data->size_b--;
			print_stack_dev(data->head_a, data->head_b, PUSH_A);
			/*if (OP == SHIFT_DOWN_A)
				(counter_back)++;
			operations[SWAP_A](data);
			(*c) += 2;
			print_stack_dev(data->head_a, data->head_b, SWAP_A);
			if (check_double_swap(data))
			{
				printf("\nWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n");
				operations[SWAP_B](data);
				//(*c)++;
				print_stack_dev(data->head_a, data->head_b, SWAP_B);
			}
			continue ;
		}
		if (push_second(data) == PUSH)
		{
			operations[SWAP_B](data);
			(*c)++;
			print_stack_dev(data->head_a, data->head_b, SWAP_B);
		}
		else if (check_to_push(data, counter_forth, counter_back) == PUSH && counter_forth == 0 || data->size_a == index)
		{
			operations[PUSH_A](data);
			data->size_a++;
			data->size_b--;
			if (OP == SHIFT_UP_A)
				(counter_back)++;
			(*c)++;
			print_stack_dev(data->head_a, data->head_b, PUSH_A);
		}
		/*else if (!init_tmp && init_back && hidden_index > data->size_a / 2 )
		{
			printf("in here\n");
			OP = SHIFT_DOWN_A;
			counter_tmp = data->size_a - hidden_index;
			if (OP_TMP == SHIFT_UP_A)
				counter_back += counter_tmp;
			init_tmp = 1;
		}
		else if (!init_tmp && init_back && hidden_index <= data->size_a / 2 && hidden_index != 0)
		{
			printf("in here\n");
			OP = SHIFT_UP_A;
			counter_tmp = hidden_index;
			if (OP_TMP == SHIFT_DOWN_A)
				counter_back += counter_tmp;
			init_tmp = 1;
		}
		else if (init_tmp && !counter_tmp)
			init_tmp = 0;
		else
		{
			printf("else in here\n");
			operations[OP](data);
			(*c)++;
			print_stack_dev(data->head_a, data->head_b, OP);
			if (counter_forth)
			{
				counter_forth--;
			}
			else if (init_back)
			{
				counter_back--;
			}
			/*else if (init_tmp)
			{
				init_tmp--;
			}
		}
	}
	OP ^= 6;
	while (--counter_back)
	{
		printf("counter_back %d", counter_back);
		operations[OP](data);
		(*c)++;
		print_stack_dev(data->head_a, data->head_b, OP);
	}
}*/

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
			//printf("----PUSH TO B---------\n");
			data->size_b++;
			data->size_a--;
			(counter)++;
			if (counter > max_index)
				(max_index) += group_size - 1;
		}
		operations[OP](data);
		//print_stack_dev(data->head_a, data->head_b, OP);
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
	print_stack(data.head_a, data.head_b, ZERO_ALL);
	sort_A(&data, operations, c);
	print_stack(data.head_a, data.head_b, ZERO_ALL);
	printf("OPS %d\n", *c);
	/*if (stack_b_sorted(data.head_b))
		push_back_all(data, c);
	else
		printf("not sorted\n");*/
}

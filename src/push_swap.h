/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:49:47 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/05 20:26:58 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
# define CONST_A 1
# define CONST_B 2
# define ERROR 0
# define PASS 1

typedef enum op {
	SWAP_A = 1,
	SWAP_B,
	SHIFT_UP_A,
	SHIFT_UP_B,
	SHIFT_DOWN_A,
	SHIFT_DOWN_B,
	SWAP_BOTH,
	SHIFT_UP_BOTH,
	SHIFT_DOWN_BOTH,
	PUSH_A,
	PUSH_B,
	ZERO_ALL,
} t_op;

typedef enum min_op {
	SWAP,
	SHIFT_UP,
	SHIFT_DOWN,
	ZERO,
} t_min_op;

typedef void (*operation) (t_list **head);

typedef struct s_data {
	t_list	*head_a;
	t_list	*head_b;
	int		size_a;
	int		size_b;
}	t_data;

// create stack
t_data	create_stack_lst(int argc, char **argv);

//operations
void	shift_up(t_list **head);
void	shift_down(t_list **head);
void	swap(t_list **head);
void	push_b(t_list **head_a, t_list **head_b);
void	push_a(t_list **head_a, t_list **head_b);

//lst utils
t_list	*lst_new(int content, int selected, int index);
void	lst_rm(t_list **head, t_list *lst);
t_list	*lst_getlast(t_list *lst);
void	lst_add_front(t_list **lst, t_list *new);
void	lst_add_back(t_list **lst, t_list *new);
int		lst_size(t_list *lst);
int		find_node_spot(t_list *head, t_list *to_find);

//visuals
void	print_stack(t_list *head_a, t_list *head_b, t_op OP);
void	print_stack_dev(t_list *head_a, t_list *head_b, t_op OP);

//lst utils
int	find_sel_node_spot(t_list *head);

//utils
int		stack_a_sorted(t_list *head_a);
int		stack_b_sorted(t_list *head_b);
t_list	*first_node_tail(t_list *head_a, int max_index);
t_list	*first_node_head(t_list *head_a, int max_index);
int		smallest_dist_head(t_list *head, int max_index);
int		smallest_dist_tail(t_list *head, int max_index);
t_list	*get_next_smallest_node(t_list *head_a, t_list *prev_smallest);
t_list	*get_greatest(t_list *head_a);

//sort small
void	sort_small(t_data *data, operation operations[3], int *c);

//sort big
void	sort_big(t_data data, operation operations[3], int group_size, int *c);

#endif
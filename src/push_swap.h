/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:49:47 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/16 14:25:34 by tdehne           ###   ########.fr       */
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
# define ERROR -1

# define BEFORE_PUSH 0
# define START_PUSH 1
# define AFTER_PUSH 2
# define PASS 3
# define PUSH 4
# define SPECIAL 5

typedef enum op {
	S_A,
	S_B,
	R_A,
	R_B,
	RR_A,
	RR_B,
	P_A,
	P_B,
	SS,
	RR,
	RRR,
	ZERO_ALL,
} t_op;

typedef enum min_op {
	SWAP_A,
	SWAP_B,
	SHIFT_UP_A,
	SHIFT_UP_B,
	SHIFT_DOWN_A,
	SHIFT_DOWN_B,
	PUSH_A,
	PUSH_B,
	ZERO,
} t_min_op;

typedef struct s_data {
	t_list	*head_a;
	t_list	*head_b;
	int		size_a;
	int		size_b;
	int		size_sel;
}	t_data;

//übergebe immer nur den struct
typedef void (*operation) (t_data *data);

// create stack
t_data	create_stack_lst(int argc, char **argv);

//operations
void	shift_up_a(t_data *data);
void	shift_up_b(t_data *data);
void	shift_down_a(t_data *data);
void	shift_down_b(t_data *data);
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	push_b(t_data *data);
void	push_a(t_data *data);

//lst utils
t_list	*lst_new(int content, int selected, int index);
void	lst_rm(t_list **head, t_list *lst);
t_list	*lst_getlast(t_list *lst);
void	lst_add_front(t_list **lst, t_list *new);
void	lst_add_back(t_list **lst, t_list *new);
int		lst_size(t_list *lst);
int		find_node_spot(t_list *head, t_list *to_find);
t_list	*lst_get_smallest(t_list *head);
t_list	*lst_get_greatest(t_list *head);

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
void	sort_three(t_data *data, operation operations[8], int *c);

//sort big
void	sort_big(t_data data, operation operations[3], int group_size, int *c);
int		find_spot(t_data data, t_list *to_insert);
void	sort_A(t_data *data, operation operations[8], int group_size, int *c);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:49:47 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/19 15:28:30 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# define ERROR -1
# define PASS 3
# define PUSH 4
# define GT_MAX_INT 2147483648

typedef enum op {
	SWAP_A,
	SWAP_B,
	SHIFT_UP_A,
	SHIFT_UP_B,
	SHIFT_DOWN_A,
	SHIFT_DOWN_B,
	PUSH_A,
	PUSH_B,
	SS,
	RR,
	RRR,
	ZERO,
}	t_op;

typedef struct s_data {
	t_list	*head_a;
	t_list	*head_b;
	int		size_a;
	int		size_b;
}	t_data;

typedef struct s_vars {
	int	max_index;
	int	counter;
	int	stack_len;
	int	group_size;
}	t_vars;

typedef struct s_vars_parse {
	char		*nums;
	char		**argv_parsed;
	int			len;
}	t_vars_parse;

//übergebe immer nur den struct
typedef void	(*t_operation) (t_data *data);

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
void	shift_down_both(t_data *data);
void	shift_up_both(t_data *data);
void	swap_both(t_data *data);

//lst utils
t_list	*lst_new(int content, int selected, int index);
void	lst_rm(t_list **head, t_list *lst);
t_list	*lst_getlast(t_list *lst);
void	lst_add_front(t_list **lst, t_list *new);
void	lst_add_back(t_list **lst, t_list *new);
int		lst_size(t_list *lst);

//visuals
void	print_stack_dev(t_op OP);

//utils
int		stack_a_sorted(t_list *head_a);
t_list	*get_next_smallest_node(t_list *head_a, t_list *prev_smallest);
t_list	*get_greatest(t_list *head_a);
void	free_all(char **arr, size_t i);

//sort small
void	sort_smaller_six(t_data *data, t_operation operations[3]);
void	sort_three(t_data *data, t_operation operations[11]);

//sort big
void	sort_big(t_data *data, t_operation operations[3], t_vars vars);
int		find_spot(t_data data, t_list *to_insert);
void	sort_a(t_data *data, t_operation operations[11]);

//sort big utils
void	sort(t_data *data, t_operation operations[11], int min_index, int rev);
t_op	get_ops(t_data data, int min_index);
void	ready_to_push(t_data *data, t_operation operations[11], t_op op, int i);
t_op	rotate_b(t_data *data, int m_i);

//libft adds
void	ft_lstclear2(t_list **lst);
char	*ft_strjoin_better(char *s1, char *s2);

// init
int		error(int len, char **argv_parsed);
void	init_operations(t_operation operations[11], int *groups, int argc);
void	decide_algo(t_data *data, t_operation operations[11], int l, t_vars v);
char	*parse(int argc, char **argv);

void	print_stack(t_list *head_a, t_list *head_b, t_op OP);

#endif
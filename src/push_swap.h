/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:49:47 by tdehne            #+#    #+#             */
/*   Updated: 2022/06/01 20:50:23 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

typedef struct s_chosen
{
	int		pos;
	t_list	*node;
} t_chosen;

t_list	*create_stack(int argc, char **argv);

void	shift_up(t_list **head);
void	shift_down(t_list **head);
void	swap(t_list **head);

void	lst_rm(t_list **head, t_list *lst);
t_list	*lst_getlast(t_list *lst);
void	lst_add_front(t_list **lst, t_list *new);
void	lst_add_back(t_list **lst, t_list *new);
void	push_b(t_list **head_a, t_list **head_b);
void	push_a(t_list **head_a, t_list **head_b);
int		lst_size(t_list *lst);
int		find_node_spot(t_list *head, t_list *to_find);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:12:58 by tdehne            #+#    #+#             */
/*   Updated: 2022/06/14 13:16:16 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_new(int content, int selected, int index)
{
	t_list	*lst;

	lst = (t_list *) malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->selected = selected;
	lst->index = index;
	lst->next = NULL;
	return (lst);
}

void	lst_add_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new || *lst == new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	lst_add_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_list	*lst_getlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lst_rm(t_list **head, t_list *lst)
{
	t_list	*tmp;

	tmp = *head;
	if (*head == lst)
		*head = (*head)->next;
	else
	{
		while (tmp->next != lst)
			tmp = tmp->next;
		tmp->next = lst->next;
	}
}

int	lst_size(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	find_node_spot(t_list *head, t_list *to_find)
{
	int	counter;

	counter = 0;
	while (head)
	{
		if (head == to_find)
			break;
		counter++;
		head = head->next;
	}
	return (counter);
}

int	find_node_by_content(t_list *head, int content)
{
	int	counter;

	counter = 0;
	while (head)
	{
		if (head->content == content)
			break;
		counter++;
		head = head->next;
	}
	return (counter);
}


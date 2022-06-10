/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:10:19 by tdehne            #+#    #+#             */
/*   Updated: 2022/06/09 12:00:44 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *head)
{
	int prev_content;

	while (head->next)
	{
		prev_content = head->content;
		if (head->next->content < prev_content)
			return (0);
		head = head->next;
	}
	return (1);
}

/*int	check_input(int len, char **argv)
{
	while (len--)
	{

	}
}*/
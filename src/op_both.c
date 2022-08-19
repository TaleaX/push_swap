/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_both.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdehne <tdehne@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:00:16 by tdehne            #+#    #+#             */
/*   Updated: 2022/08/19 15:01:00 by tdehne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_up_both(t_data *data)
{
	shift_up_a(data);
	shift_up_b(data);
}

void	shift_down_both(t_data *data)
{
	shift_down_a(data);
	shift_down_b(data);
}

void	swap_both(t_data *data)
{
	swap_a(data);
	swap_b(data);
}

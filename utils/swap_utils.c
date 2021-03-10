/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:26:10 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/10 11:55:54 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	swap_stack(t_stack *stack)
{
	int		tmp;

	if (stack->position > 1)
	{
		tmp = stack->stack[stack->position - 1];
		stack->stack[stack->position - 1] = stack->stack[stack->position - 2];
		stack->stack[stack->position - 2] = tmp;
	}
}

void	swap_both(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
}

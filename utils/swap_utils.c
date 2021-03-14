/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:26:10 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/13 16:41:36 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	swap_stack(t_stack *stack)
{
	int		a;
	int		b;

	if (stack->position > 1)
	{
		a = pop(stack);
		b = pop(stack);
		push(stack, a);
		push(stack, b);
	}
}

void	swap_both(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
}

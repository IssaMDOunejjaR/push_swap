/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:10:59 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/17 15:12:23 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	push_stack_val(t_stack *dest, t_stack *src)
{
	if (src->position != 0)
	{
		dest->stack[dest->position] = pop(src);
		dest->position++;
	}
}

void	push(t_stack *dest, int value)
{
	dest->stack[dest->position] = value;
	dest->position++;
}

int		pop(t_stack *stack)
{
	int		value;

	value = 0;
	if (stack->position > 0)
	{
		value = stack->stack[stack->position - 1];
		stack->position--;
	}
	return (value);
}

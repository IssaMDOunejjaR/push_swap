/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:35:05 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/07 18:03:26 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	rotate_stack(t_stack *stack)
{
	int		tmp;
	int		i;

	i = stack->position - 1;
	while (i >= 0)
	{
		if (i == stack->position - 1)
			tmp = stack->stack[i];
		else
			stack->stack[i + 1] = stack->stack[i];
		i--;
	}
	stack->stack[i + 1] = tmp;
}

void	rotate_both(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
}

void	reverse_rotate_stack(t_stack *stack)
{
	int		tmp;
	int		i;

	i = 0;
	while (i < stack->position)
	{
		if (i == 0)
			tmp = stack->stack[i];
		else
			stack->stack[i - 1] = stack->stack[i];
		i++;
	}
	stack->stack[i - 1] = tmp;
}

void	reverse_rotate_both(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
}

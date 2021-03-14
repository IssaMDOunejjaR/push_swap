/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:35:05 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/13 16:50:04 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	rotate_stack(t_stack *stack)
{
	int		*tmp;
	int		i;
	int		len;

	i = 0;
	len = stack->position;
	tmp = malloc(sizeof(int) * len);
	while (stack->position != 0)
	{
		tmp[i] = pop(stack);
		i++;
	}
	push(stack, tmp[0]);
	i = len - 1;
	while (i > 0)
	{
		push(stack, tmp[i]);
		i--;
	}
	free(tmp);
}

void	rotate_both(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
}

void	reverse_rotate_stack(t_stack *stack)
{
	int		*tmp;
	int		i;
	int		len;

	i = 0;
	len = stack->position;
	tmp = malloc(sizeof(int) * len);
	while (stack->position != 0)
	{
		tmp[i] = pop(stack);
		i++;
	}
	i = len - 2;
	while (i >= 0)
	{
		push(stack, tmp[i]);
		i--;
	}
	push(stack, tmp[len - 1]);
	free(tmp);
}

void	reverse_rotate_both(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
}

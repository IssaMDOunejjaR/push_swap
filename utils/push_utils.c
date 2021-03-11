/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:10:59 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/10 17:56:29 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	push_stack_val(t_stack *dest, t_stack *src)
{
	if (src->position != -1)
	{
		dest->stack[dest->position] = src->stack[src->position - 1];
		dest->position++;
		src->position--;
	}
}

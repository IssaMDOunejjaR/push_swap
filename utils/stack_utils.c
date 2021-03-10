/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:05:59 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/10 11:00:13 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	push(t_stack *dest, int value)
{
	dest->stack[dest->position] = value;
	dest->position++;
}

int		pop(t_stack *stack)
{
	int		value;

	if (stack->position >= 0)
	{
		value = stack->stack[stack->position - 1];
		stack->position--;
	}
	return (value);
}

int		is_all_num(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int		fill_stack(t_stack *dest, char **tmp, char **argv)
{
	int		i;

	if (tmp != NULL)
	{
		i = 0;
		while (tmp[i] != NULL)
		{
			if (is_all_num(tmp[i]) == 1)
				return (1);
			push(dest, ft_atoi(tmp[i]));
			i++;
		}
	}
	else
	{
		i = 1;
		while (argv[i] != NULL)
		{
			if (is_all_num(argv[i]) == 1)
				return (1);
			push(dest, ft_atoi(argv[i]));
			i++;
		}
	}
	return (0);
}

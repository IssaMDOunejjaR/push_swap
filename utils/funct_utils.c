/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:21:21 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/10 11:55:16 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**init_value(t_stack *a, t_stack *b, char **argv, int argc)
{
	char	**tmp;
	int		len;

	len = argc - 1;
	tmp = NULL;
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		len = len_table(tmp);
	}
	a->stack = malloc(sizeof(int) * len);
	b->stack = malloc(sizeof(int) * len);
	a->position = 0;
	b->position = 0;
	a->length = len;
	b->length = len;
	return (tmp);
}

int		check_double_val(t_stack *stack)
{
	int		i;
	int		j;

	i = 0;
	while (i < stack->position)
	{
		j = i + 1;
		while (j < stack->position)
		{
			if (stack->stack[i] == stack->stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		is_sorted(t_stack *stack)
{
	int		i;

	i = stack->position - 1;
	while (i >= 0)
	{
		if (i - 1 >= 0)
		{
			if (stack->stack[i] > stack->stack[i - 1])
				return (1);
		}
		i--;
	}
	return (0);
}

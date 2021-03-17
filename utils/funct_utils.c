/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:21:21 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/17 15:21:38 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		len_stack(char **tab, int i)
{
	int	l;

	l = 0;
	while (tab[i] != NULL)
	{
		if (ft_strcmp(tab[i], "-v") && ft_strcmp(tab[i], "-c") &&
		ft_strcmp(tab[i], "-r") && ft_strcmp(tab[i], "-w"))
			break ;
		i++;
	}
	while (tab[i] != NULL)
	{
		i++;
		l++;
	}
	return (l);
}

int		check_double_val(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i] != NULL)
	{
		j = i + 1;
		while (tab[j] != NULL)
		{
			if (ft_strcmp(tab[i], tab[j]) == 0)
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
	int		len;
	int		*tmp;
	int		sorted;

	sorted = 0;
	len = stack->position;
	tmp = malloc(sizeof(int) * len);
	i = 0;
	while (stack->position != 0)
	{
		tmp[i] = pop(stack);
		i++;
	}
	i = len - 1;
	while (i >= 0)
	{
		if (i - 1 >= 0 && tmp[i] < tmp[i - 1])
			sorted = 1;
		push(stack, tmp[i--]);
	}
	free(tmp);
	if (sorted == 1)
		return (1);
	return (0);
}

int		is_smallest_number(t_stack *stack, int number)
{
	int		*tmp;
	int		i;
	int		len;
	int		is_small;

	i = 0;
	len = stack->position;
	tmp = malloc(sizeof(int) * len);
	while (stack->position != 0)
	{
		tmp[i] = pop(stack);
		i++;
	}
	i = len - 1;
	is_small = 0;
	while (i >= 0)
	{
		if (tmp[i] < number)
			is_small = 1;
		push(stack, tmp[i--]);
	}
	free(tmp);
	if (is_small == 1)
		return (1);
	return (0);
}

int		check_top_stack(t_stack *stack)
{
	int		a;
	int		b;
	int		check;

	check = 0;
	if (stack->position >= 1)
	{
		a = pop(stack);
		b = pop(stack);
		if (a > b)
			check = 1;
		push(stack, b);
		push(stack, a);
	}
	if (check == 1)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:21:21 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/15 18:15:21 by iounejja         ###   ########.fr       */
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

char	**init_value(t_stack *a, t_stack *b, char **argv, int argc)
{
	char	**tmp;
	int		len;

	tmp = NULL;
	len = len_stack(argv, 1);
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		len = len_stack(tmp, 0);
	}
	a->stack = malloc(sizeof(int) * len);
	b->stack = malloc(sizeof(int) * len);
	a->position = 0;
	b->position = 0;
	return (tmp);
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

void	print_stack(t_stack *stack, int fd)
{
	int		i;
	int		len;
	int		*tmp;

	if (stack->position == 0)
		ft_putendl_fd("Empty", fd);
	else
	{
		len = stack->position;
		tmp = malloc(sizeof(int) * len);
		i = 0;
		while (stack->position != 0)
		{
			tmp[i] = pop(stack);
			ft_putnbr_fd(tmp[i], fd);
			ft_putchar_fd('\n', fd);
			i++;
		}
		i = len - 1;
		while (i >= 0)
			push(stack, tmp[i--]);
		free(tmp);
	}
}

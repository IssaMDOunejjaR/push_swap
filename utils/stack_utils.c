/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:05:59 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/15 18:17:43 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		valid_option(t_option *options)
{
	if (options->display_status > 1)
		return (1);
	if (options->color > 1)
		return (1);
	if (options->read > 1)
		return (1);
	if (options->write > 1)
		return (1);
	return (0);
}

int		is_all_num(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && str[0] == '-')
			;
		else if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int		check_and_push(t_stack *stack, char **tab, int i)
{
	while (tab[i] != NULL)
	{
		if (is_all_num(tab[i]) == 1)
			return (1);
		push(stack, ft_atoi(tab[i]));
		i++;
	}
	return (0);
}

int		check_options(t_option *options, char **tab, int i)
{
	while (tab[i] != NULL)
	{
		if (ft_strcmp(tab[i], "-v") == 0)
			options->display_status++;
		else if (ft_strcmp(tab[i], "-c") == 0)
			options->color++;
		else if (ft_strcmp(tab[i], "-r") == 0)
		{
			options->read++;
			i++;
			options->read_file = tab[i];
		}
		else if (ft_strcmp(tab[i], "-w") == 0)
		{
			options->write++;
			i++;
			options->write_f = tab[i];
		}
		else
			break ;
		i++;
	}
	return (i);
}

int		fill_stack(t_stack *dest, char **tmp, char **argv, t_option *options)
{
	int		i;

	if (tmp != NULL)
	{
		i = check_options(options, tmp, 0);
		if (check_double_val(tmp) == 1)
			return (1);
		if (check_and_push(dest, tmp, i) == 1)
			return (1);
	}
	else
	{
		i = check_options(options, argv, 1);
		if (check_double_val(argv) == 1)
			return (1);
		if (check_and_push(dest, argv, i) == 1)
			return (1);
	}
	if (valid_option(options) == 1)
		return (1);
	return (0);
}

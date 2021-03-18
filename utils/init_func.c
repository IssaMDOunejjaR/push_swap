/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:11:05 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/18 10:55:33 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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

void	init_option(t_option *options)
{
	options->display_status = 0;
	options->color = 0;
	options->read = 0;
	options->write = 0;
}

long	ft_atoi_long(char *str)
{
	long	nb;
	long	n;
	int		i;

	i = 0;
	n = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		n = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	nb = nb * n;
	return (nb);
}

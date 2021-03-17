/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:11:05 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/17 15:11:55 by iounejja         ###   ########.fr       */
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

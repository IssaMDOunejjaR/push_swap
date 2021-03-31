/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:21:40 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/29 13:25:39 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	check_if_sorted(t_stack *a, t_stack *b)
{
	if (a->position == 0)
		return ;
	if (is_sorted(a) == 0 && b->position == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int		main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_option	options;
	char		**tmp;

	if (argc >= 2)
	{
		init_option(&options);
		tmp = init_value(&a, &b, argv, argc);
		if (fill_stack(&b, tmp, argv, &options) == 1)
			ft_putendl_fd("Error", 2);
		else
		{
			while (b.position - 1 >= 0)
				push(&a, pop(&b));
			if (get_instructions(&a, &b, &options) == 1)
				ft_putendl_fd("Error", 2);
			else
				check_if_sorted(&a, &b);
		}
		free(a.stack);
		free(b.stack);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:22:16 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/10 12:01:06 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	char	**tmp;
	
	if (argc >= 2)
	{
		tmp = init_value(&a, &b, argv, argc);
		if (fill_stack(&b, tmp, argv) == 1)
			ft_putendl_fd("Error", 2);
		else
		{
			while (b.position - 1 >= 0)
				push(&a, pop(&b));
			if (check_double_val(&a) == 1)
				ft_putendl_fd("Error", 2);
			else
			{
				
			}
		}
		free(a.stack);
		free(b.stack);
	}
	return (0);
}
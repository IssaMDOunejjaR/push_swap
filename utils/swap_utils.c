/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:26:10 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/15 14:20:42 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	swap_stack(t_stack *stack)
{
	int		a;
	int		b;

	if (stack->position > 1)
	{
		a = pop(stack);
		b = pop(stack);
		push(stack, a);
		push(stack, b);
	}
}

void	swap_both(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
}

void	print_start_status(t_stack *a, t_stack *b, int fd)
{
	ft_putendl_fd("#----- a -----#", fd);
	print_stack(a, fd);
	ft_putendl_fd("#----- b -----#", fd);
	print_stack(b, fd);
	ft_putendl_fd("#-------------#", fd);
	ft_putchar_fd('\n', fd);
	ft_putchar_fd('\n', fd);
}

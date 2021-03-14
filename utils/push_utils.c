/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:10:59 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/14 18:13:34 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	push_stack_val(t_stack *dest, t_stack *src)
{
	if (src->position != -1)
	{
		dest->stack[dest->position] = pop(src);
		dest->position++;
	}
}

void	push(t_stack *dest, int value)
{
	dest->stack[dest->position] = value;
	dest->position++;
}

int		pop(t_stack *stack)
{
	int		value;

	if (stack->position > 0)
	{
		value = stack->stack[stack->position - 1];
		stack->position--;
	}
	return (value);
}

void	init_option(t_option *options)
{
	options->display_status = 0;
	options->color_last_option = 0;
	options->read = 0;
	options->write = 0;
}

void	display_status(t_stack *a, t_stack *b, char *instruction, int fd)
{
	if (instruction != NULL)
	{
		ft_putstr_fd("===== ", fd);
		ft_putstr_fd(instruction, fd);
		ft_putendl_fd(" =====", fd);
	}
	ft_putendl_fd("#----- a -----#", fd);
	print_stack(a, fd);
	ft_putendl_fd("#----- b -----#", fd);
	print_stack(b, fd);
	ft_putendl_fd("#-------------#", fd);
	ft_putchar_fd('\n', fd);
	ft_putchar_fd('\n', fd);
}

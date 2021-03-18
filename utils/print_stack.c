/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:12:11 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/18 11:08:05 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	display_status(t_stack *a, t_stack *b, char *instruction, int fd)
{
	if (instruction != NULL)
	{
		ft_putstr_fd("====== ", fd);
		ft_putstr_fd(instruction, fd);
		ft_putendl_fd(" ======", fd);
	}
	ft_putendl_fd("#----- a -----#", fd);
	print_stack(a, fd);
	ft_putendl_fd("#----- b -----#", fd);
	print_stack(b, fd);
	ft_putendl_fd("#-------------#", fd);
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

int		display_checker_status(t_stack *a, t_stack *b, t_option *opt)
{
	int		fd;

	fd = 1;
	if (opt->display_status == 1)
	{
		if (opt->write == 1)
			fd = open(opt->write_f, O_CREAT | O_TRUNC | O_WRONLY, 0666);
		if (opt->display_status == 1)
			print_start_status(a, b, fd);
	}
	return (fd);
}

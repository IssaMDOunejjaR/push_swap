/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:22:16 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/26 19:06:26 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		check_files(t_option *options)
{
	int		fd;

	fd = 1;
	if (options->write == 1)
		fd = open(options->write_f, O_CREAT | O_TRUNC | O_WRONLY, 0666);
	if (options->read == 1)
	{
		if (open(options->read_file, O_RDONLY, 0666) < 0)
			return (-1);
	}
	return (fd);
}

int		main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_option	options;
	char		**tmp;
	int			fd;

	if (argc >= 2)
	{
		init_option(&options);
		tmp = init_value(&a, &b, argv, argc);
		if (fill_stack(&b, tmp, argv, &options) == 1)
			ft_putendl_fd("Error", 2);
		else
		{
			fd = 1;
			while (b.position - 1 >= 0)
				push(&a, pop(&b));
			if ((fd = check_files(&options)) < 0)
				ft_putendl_fd("Error", 2);
			print_instructions(&a, &b, &options, fd);
		}
		free(a.stack);
		free(b.stack);
	}
	return (0);
}

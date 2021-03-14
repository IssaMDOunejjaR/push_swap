/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:21:40 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/14 18:08:12 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		check_instruction(char *instruction, t_stack *a, t_stack *b)
{
	if (ft_strcmp(instruction, "sa") == 0)
		swap_stack(a);
	else if (ft_strcmp(instruction, "sb") == 0)
		swap_stack(b);
	else if (ft_strcmp(instruction, "ss") == 0)
		swap_both(a, b);
	else if (ft_strcmp(instruction, "pa") == 0)
		push_stack_val(a, b);
	else if (ft_strcmp(instruction, "pb") == 0)
		push_stack_val(b, a);
	else if (ft_strcmp(instruction, "ra") == 0)
		rotate_stack(a);
	else if (ft_strcmp(instruction, "rb") == 0)
		rotate_stack(b);
	else if (ft_strcmp(instruction, "rr") == 0)
		rotate_both(a, b);
	else if (ft_strcmp(instruction, "rra") == 0)
		reverse_rotate_stack(a);
	else if (ft_strcmp(instruction, "rrb") == 0)
		reverse_rotate_stack(b);
	else if (ft_strcmp(instruction, "rrr") == 0)
		reverse_rotate_both(a, b);
	else
		return (1);
	return (0);
}

int		execute_instructions(t_stack *a, t_stack *b, char **instructions, t_option *options)
{
	int		i;

	i = 0;
	if (options->display_status == 1)
	{
		ft_putendl_fd("--- a ---", 1);
		print_stack(a, 1);
		ft_putendl_fd("--- b ---", 1);
		print_stack(b, 1);
		ft_putendl_fd("---------", 1);
	}
	while (instructions[i] != NULL)
	{
		if (check_instruction(instructions[i], a, b) == 1)
			return (1);
		if (options->display_status == 1)
		{
			if (options->color_last_option == 1 && instructions[i + 1] == NULL)
				ft_putstr_fd("\e[1;32m", 1);
			display_status(a, b, instructions[i], 1);
			if (options->color_last_option == 1 && instructions[i + 1] == NULL)
				ft_putstr_fd("\033[0;37m", 1);
		}
		i++;
	}
	return (0);
}

int		get_instructions(t_stack *a, t_stack *b, t_option *options)
{
	char	**instructions;
	char	*line;
	int		fd;
	int		ret;

	instructions = malloc(sizeof(char *) * 1);
	instructions[0] = NULL;
	fd = 0;
	if (options->read == 1)
	{
		if ((fd = open(options->read_file, O_RDONLY, 0666)) < 0)
			return (1);
	}
	while (1)
	{
		ret = get_next_line(fd, &line);
		instructions = tab_join(instructions, line);
		free(line);
		if (ret == 0)
			break ;
	}
	if (execute_instructions(a, b, instructions, options) == 1)
	{
		free_table(instructions);
		return (1);
	}
	free_table(instructions);
	return (0);
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
			{
				if (is_sorted(&a) == 0 && b.position == 0)
					ft_putendl_fd("OK", 1);
				else
					ft_putendl_fd("KO", 1);
			}
		}
		free(a.stack);
		free(b.stack);
	}
	return (0);
}

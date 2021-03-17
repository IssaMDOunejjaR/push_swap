/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:18:06 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/17 15:13:52 by iounejja         ###   ########.fr       */
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

int		execute_instructions(t_stack *a, t_stack *b, char **in, t_option *opt)
{
	int		i;
	int		fd;

	i = 0;
	fd = display_checker_status(a, b, opt);
	while (in[i] != NULL)
	{
		if (check_instruction(in[i], a, b) == 1)
		{
			free_table(in);
			return (1);
		}
		if (opt->display_status == 1)
		{
			if (opt->color == 1 && in[i + 1] == NULL && opt->color == 0)
				ft_putstr_fd("\e[1;32m", fd);
			display_status(a, b, in[i], fd);
			if (opt->color == 1 && in[i + 1] == NULL && opt->color == 0)
				ft_putstr_fd("\033[0;37m", fd);
			if (in[i + 1] != NULL)
				ft_putstr_fd("\n\n", fd);
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

	instructions = malloc(sizeof(char *) * 1);
	instructions[0] = NULL;
	fd = 0;
	if (options->read == 1)
	{
		if ((fd = open(options->read_file, O_RDONLY, 0666)) < 0)
			return (1);
	}
	while (get_next_line(fd, &line))
	{
		instructions = tab_join(instructions, line);
		free(line);
	}
	free(line);
	if (execute_instructions(a, b, instructions, options) == 1)
		return (1);
	free_table(instructions);
	return (0);
}

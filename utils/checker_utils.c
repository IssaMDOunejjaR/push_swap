/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:18:06 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/15 12:35:33 by iounejja         ###   ########.fr       */
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

	i = 0;
	if (opt->display_status == 1)
		print_start_status(a, b, 1);
	while (in[i] != NULL)
	{
		if (check_instruction(in[i], a, b) == 1)
		{
			free_table(in);
			return (1);
		}
		if (opt->display_status == 1)
		{
			if (opt->color_last_option == 1 && in[i + 1] == NULL)
				ft_putstr_fd("\e[1;32m", 1);
			display_status(a, b, in[i], 1);
			if (opt->color_last_option == 1 && in[i + 1] == NULL)
				ft_putstr_fd("\033[0;37m", 1);
		}
		i++;
	}
	free_table(in);
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
	while (get_next_line(fd, &line))
	{
		instructions = tab_join(instructions, line);
		free(line);
	}
	free(line);
	if (execute_instructions(a, b, instructions, options) == 1)
		return (1);
	return (0);
}

void	print_instructions(t_stack *a, t_stack *b, t_option *options, int fd)
{
	t_list *instructions;
	t_list *tmp;

	if (options->display_status == 1)
		print_start_status(a, b, fd);
	instructions = set_instructions(a, b);
	tmp = instructions;
	while (tmp->next != NULL)
	{
		ft_putendl_fd(tmp->content, fd);
		if (options->display_status == 1)
			display_status(a, b, NULL, fd);
		tmp = tmp->next;
	}
	if (options->color_last_option == 1 && options->write == 0)
		ft_putstr_fd("\e[1;32m", fd);
	ft_putendl_fd(tmp->content, fd);
	if (options->display_status == 1)
		display_status(a, b, NULL, fd);
	if (options->color_last_option == 1 && options->write == 0)
		ft_putstr_fd("\033[0;37m", fd);
	free_instructions(instructions);
}

void	free_instructions(t_list *instructions)
{
	t_list *tmp;

	while (instructions != NULL)
	{
		free(instructions->content);
		tmp = instructions;
		instructions = instructions->next;
		free(tmp);
	}
}

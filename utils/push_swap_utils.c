/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:20:45 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/28 16:29:41 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		*bubble_sort(int *tab, int len)
{
	int		*new;
	int		sorted;
	int		i;
	int		tmp;

	sorted = 0;
	while (sorted == 0)
	{
		i = 0;
		sorted = 1;
		while (i < len)
		{
			if (i + 1 < len && tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
	}
	new = tab;
	return (new);
}

int		count_instructions(t_stack *stack)
{
	int		count;
	int		*tmp;
	int		biggest_number;
	int		pos;

	count = 1;
	tmp = malloc(sizeof(int) * stack->position);
	tmp[0] = pop(stack);
	biggest_number = tmp[0];
	pos = 0;
	while (stack->position != 0)
	{
		tmp[count] = pop(stack);
		if (tmp[count] > biggest_number)
		{
			pos = count;
			biggest_number = tmp[count];
		}
		count++;
	}
	count = count - 1;
	while (count >= 0)
		push(stack, tmp[count--]);
	free(tmp);
	return (pos);
}

void	print_final(t_stack *a, t_stack *b, t_option *opt, t_utils *utils)
{
	int		i;
	int		len;

	i = 0;
	len = len_table(utils->inst);
	while (utils->inst[i] != NULL)
	{
		check_instruction(utils->inst[i], a, b);
		if (i == len - 1 && opt->color == 1 && opt->write != 1)
			ft_putstr_fd("\e[1;32m", utils->fd);
		ft_putendl_fd(utils->inst[i], utils->fd);
		if (opt->display_status == 1)
			display_status(a, b, utils->inst[i], utils->fd);
		if (i == len - 1 && opt->color == 1 && opt->write != 1)
			ft_putstr_fd("\033[0;37m", utils->fd);
		else if (i != len - 1 && opt->display_status == 1)
			ft_putstr_fd("\n\n", utils->fd);
		i++;
	}
	free_table(utils->inst);
	if (utils->fd != 1)
		close(utils->fd);
}

void	print_instructions(t_stack *a, t_stack *b, t_option *options, int fd)
{
	t_utils utils;
	int		*tmp;
	int		i;
	int		len;

	len = a->position;
	utils.inst = malloc(sizeof(char *) * 1);
	utils.inst[0] = NULL;
	tmp = copy_stack(a);
	if (options->display_status == 1)
		print_start_status(a, b, fd);
	if (a->position >= 100 && a->position < 500)
		sort_big_stack(a, b, &utils, 5);
	else if (a->position >= 500)
		sort_big_stack(a, b, &utils, 10);
	else
		sort_small_stack(a, b, &utils);
	utils.fd = fd;
	while (a->position)
		pop(a);
	i = len - 1;
	while (i >= 0)
		push(a, tmp[i--]);
	print_final(a, b, options, &utils);
	free(tmp);
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

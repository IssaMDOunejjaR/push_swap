/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:20:45 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/17 15:26:41 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*sort_stack(t_stack *a, t_stack *b)
{
	char	*str;

	str = NULL;
	if (is_sorted(a) == 0 && b->position != 0)
	{
		push_stack_val(a, b);
		str = "pa";
	}
	else if (check_top_stack(a) == 1)
	{
		swap_stack(a);
		str = "sa";
	}
	else if (is_smallest_number(a, a->stack[a->position - 1]) == 0)
	{
		push_stack_val(b, a);
		str = "pb";
	}
	else
	{
		reverse_rotate_stack(a);
		str = "rra";
	}
	return (str);
}

void	print_instructions(t_stack *a, t_stack *b, t_option *options, int fd)
{
	char	*str;

	if (options->display_status == 1)
		print_start_status(a, b, fd);
	while (1)
	{
		str = NULL;
		if (is_sorted(a) == 0 && b->position == 0)
			break ;
		else
			str = sort_stack(a, b);
		ft_putendl_fd(str, fd);
		if (options->display_status == 1 && str != NULL)
			display_status(a, b, str, fd);
	}
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

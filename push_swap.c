/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:22:16 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/14 18:05:49 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		is_smallest_number(t_stack *stack, int number)
{
	int		*tmp;
	int		i;
	int		len;
	int		is_small;

	i = 0;
	len = stack->position;
	tmp = malloc(sizeof(int) * len);
	while (stack->position != 0)
	{
		tmp[i] = pop(stack);
		i++;
	}
	i = len - 1;
	is_small = 0;
	while (i >= 0)
	{
		if (tmp[i] < number)
			is_small = 1;
		push(stack, tmp[i]);
		i--;
	}
	if (is_small == 1)
		return (1);
	return (0);
}

int		check_top_stack(t_stack *stack)
{
	int		a;
	int		b;
	int		check;

	if (stack->position >= 1)
	{
		a = pop(stack);
		b = pop(stack);
		check = 0;
		
		if (a > b)
			check = 1;
		push(stack, b);
		push(stack, a);
	}
	if (check == 1)
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_option	options;
	t_list		*instructions;
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
			if (options.write == 1)
				fd = open(options.write_file, O_CREAT | O_WRONLY, 0666);
			if (options.display_status == 1)
			{
				ft_putendl_fd("#----- a -----#", fd);
				print_stack(&a, fd);
				ft_putendl_fd("#----- b -----#", fd);
				print_stack(&b, fd);
				ft_putendl_fd("#-------------#", fd);
			}
			instructions = NULL;
			while (1)
			{
				if (is_sorted(&a) == 0 && b.position == 0)
					break ;
				else if (is_sorted(&a) == 0 && b.position != 0)
				{
					ft_lstadd_back(&instructions, ft_lstnew(ft_strdup("pa")));
					push_stack_val(&a, &b);
				}
				else if (check_top_stack(&a) == 1)
				{
					ft_lstadd_back(&instructions, ft_lstnew(ft_strdup("sa")));
					swap_stack(&a);
				}
				else if (is_smallest_number(&a, a.stack[a.position - 1]) == 0)
				{
					ft_lstadd_back(&instructions, ft_lstnew(ft_strdup("pb")));
					push_stack_val(&b, &a);
				}
				else
				{
					ft_lstadd_back(&instructions, ft_lstnew(ft_strdup("rra")));
					reverse_rotate_stack(&a);
				}
			}
			t_list *tmp;

			tmp = instructions;
			while (tmp->next != NULL)
			{
				ft_putendl_fd(tmp->content, fd);
				if (options.display_status == 1)
					display_status(&a, &b, NULL, fd);
				tmp = tmp->next;
			}
			if (options.display_status == 1)
			{
				if (options.color_last_option == 1 && options.write == 0)
					ft_putstr_fd("\e[1;32m", fd);
				ft_putendl_fd(tmp->content, fd);
				display_status(&a, &b, NULL, fd);
				if (options.color_last_option == 1 && options.write == 0)
					ft_putstr_fd("\033[0;37m", fd);
			}
			else
			{
				if (options.color_last_option == 1 && options.write == 0)
					ft_putstr_fd("\e[1;32m", fd);
				ft_putstr_fd(tmp->content, fd);
				if (options.color_last_option == 1 && options.write == 0)
					ft_putstr_fd("\033[0;37m", fd);
			}
		}
		free(a.stack);
		free(b.stack);
	}
	return (0);
}

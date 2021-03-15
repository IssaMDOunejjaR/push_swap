/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:20:45 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/15 14:21:59 by iounejja         ###   ########.fr       */
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

void	set_instructions_more(t_stack *a, t_stack *b, t_list *instructions)
{
	if (check_top_stack(a) == 1)
	{
		ft_lstadd_back(&instructions, ft_lstnew(ft_strdup("sa")));
		swap_stack(a);
	}
	else if (is_smallest_number(a, a->stack[a->position - 1]) == 0)
	{
		ft_lstadd_back(&instructions, ft_lstnew(ft_strdup("pb")));
		push_stack_val(b, a);
	}
}

t_list	*set_instructions(t_stack *a, t_stack *b)
{
	t_list	*instructions;

	instructions = NULL;
	while (1)
	{
		if (is_sorted(a) == 0 && b->position == 0)
			break ;
		else if (is_sorted(a) == 0 && b->position != 0)
		{
			ft_lstadd_back(&instructions, ft_lstnew(ft_strdup("pa")));
			push_stack_val(a, b);
		}
		else if (check_top_stack(a) == 1 ||
		is_smallest_number(a, a->stack[a->position - 1]) == 0)
			set_instructions_more(a, b, instructions);
		else
		{
			ft_lstadd_back(&instructions, ft_lstnew(ft_strdup("rra")));
			reverse_rotate_stack(a);
		}
	}
	return (instructions);
}

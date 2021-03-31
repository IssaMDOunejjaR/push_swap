/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:19:38 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/27 16:36:37 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		check_top_bottom(t_stack *stack)
{
	int		*tmp;
	int		i;

	if (stack->position == 0)
		return (0);
	tmp = malloc(sizeof(int) * stack->position);
	i = 0;
	while (stack->position != 0)
	{
		tmp[i] = pop(stack);
		i++;
	}
	i = i - 1;
	while (i >= 0)
	{
		push(stack, tmp[i]);
		i--;
	}
	if (tmp[0] > tmp[stack->position - 1])
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

void	sort_more(t_stack *a, t_stack *b, t_utils *utils, int sorted)
{
	if (sorted == 0 && b->position != 0)
	{
		push_stack_val(a, b);
		utils->inst = tab_join(utils->inst, "pa");
	}
	else if (is_smallest_number(a, a->stack[a->position - 1]) == 0)
	{
		push_stack_val(b, a);
		utils->inst = tab_join(utils->inst, "pb");
	}
	else if (check_top_bottom(a) == 1)
	{
		rotate_stack(a);
		utils->inst = tab_join(utils->inst, "ra");
	}
	else if (check_top_stack(a) == 1)
	{
		swap_stack(a);
		utils->inst = tab_join(utils->inst, "sa");
	}
	else
	{
		rotate_stack(a);
		utils->inst = tab_join(utils->inst, "ra");
	}
}

void	sort_small_stack(t_stack *a, t_stack *b, t_utils *utils)
{
	int	sorted;

	while (1)
	{
		sorted = is_sorted(a);
		if (sorted == 0 && b->position == 0)
			break ;
		else
			sort_more(a, b, utils, sorted);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:20:41 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/27 16:42:36 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		*get_sorted_table(t_stack *stack)
{
	int		i;
	int		*tab;
	int		len;

	i = 0;
	len = stack->position;
	tab = malloc(sizeof(int) * len);
	while (stack->position)
	{
		tab[i] = pop(stack);
		i++;
	}
	i = i - 1;
	while (i >= 0)
	{
		push(stack, tab[i]);
		i--;
	}
	return (bubble_sort(tab, len));
}

void	check_chunk(t_stack *a, t_utils *utils)
{
	if (utils->check == utils->len / utils->chunk_len)
	{
		utils->chunk = utils->end;
		utils->end = utils->chunk + (utils->len / utils->chunk_len);
		utils->check = 0;
	}
	if (utils->check != utils->len / utils->chunk_len)
		utils->start = utils->chunk;
	if (utils->pushed == 0)
	{
		push(a, utils->number);
		utils->inst = tab_join(utils->inst, "ra");
		rotate_stack(a);
	}
}

void	push_by_chunk(t_stack *a, t_stack *b, t_utils *utils, int *tab)
{
	utils->check = 0;
	utils->chunk = 0;
	utils->start = utils->chunk;
	utils->end = utils->chunk + (utils->len / utils->chunk_len);
	while (a->position != 0)
	{
		utils->pushed = 0;
		utils->number = pop(a);
		while (utils->start < utils->end)
		{
			if (utils->number == tab[utils->start])
			{
				utils->inst = tab_join(utils->inst, "pb");
				push(b, utils->number);
				utils->check++;
				utils->pushed = 1;
				break ;
			}
			utils->start++;
		}
		check_chunk(a, utils);
	}
}

void	pop_and_sort(t_stack *a, t_stack *b, t_utils *utils, int count)
{
	if (count == 0)
	{
		utils->inst = tab_join(utils->inst, "pa");
		push(a, pop(b));
	}
	else if (count <= b->position / 2)
	{
		while (count != 0)
		{
			utils->inst = tab_join(utils->inst, "rb");
			rotate_stack(b);
			count--;
		}
	}
	else if (count > b->position / 2)
	{
		while (count < b->position)
		{
			utils->inst = tab_join(utils->inst, "rrb");
			reverse_rotate_stack(b);
			count++;
		}
	}
}

void	sort_big_stack(t_stack *a, t_stack *b, t_utils *utils, int chunk_len)
{
	int		*tab;
	int		count;

	utils->len = a->position;
	utils->chunk_len = chunk_len;
	tab = get_sorted_table(a);
	push_by_chunk(a, b, utils, tab);
	while (b->position != 0)
	{
		count = count_instructions(b);
		pop_and_sort(a, b, utils, count);
	}
	free(tab);
}

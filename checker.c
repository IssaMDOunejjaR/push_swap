/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:21:40 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/10 11:58:19 by iounejja         ###   ########.fr       */
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

int		execute_instructions(t_stack *a, t_stack *b, char **instructions)
{
	int		i;

	i = 0;
	while (instructions[i] != NULL)
	{
		if (check_instruction(instructions[i], a, b) == 1)
			return (1);
		i++;
	}
	return (0);
}

int		get_instructions(t_stack *a, t_stack *b)
{
	char	**instructions;
	char	*line;

	instructions = malloc(sizeof(char *) * 1);
	instructions[0] = NULL;
	while (get_next_line(0, &line))
	{
		if (ft_strcmp(line, "") == 0)
			break ;
		instructions = tab_join(instructions, line);
		free(line);
	}
	free(line);
	if (execute_instructions(a, b, instructions) == 1)
	{
		free_table(instructions);
		return (1);
	}
	free_table(instructions);
	return (0);
}

int		main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	**tmp;

	if (argc >= 2)
	{
		tmp = init_value(&a, &b, argv, argc);
		if (fill_stack(&b, tmp, argv) == 1)
			ft_putendl_fd("Error", 2);
		else
		{
			while (b.position - 1 >= 0)
				push(&a, pop(&b));
			if (check_double_val(&a) == 1)
				ft_putendl_fd("Error", 2);
			else
			{
				// int i = a.position - 1;
				// while (i >= 0)
				// {
				// 	printf("%d\n", a.stack[i]);
				// 	i--;
				// }
				// printf("==========\n");
				// i = b.position - 1;
				// while (i >= 0)
				// {
				// 	printf("%d\n", b.stack[i]);
				// 	i--;
				// }
				if (get_instructions(&a, &b) == 1)
					ft_putendl_fd("Error", 2);
				else
				{
					if (is_sorted(&a) == 0 && b.position == 0)
					ft_putendl_fd("OK", 1);
					else
						ft_putendl_fd("KO", 1);
				}
				// int i = a.position - 1;
				// while (i >= 0)
				// {
				// 	printf("%d\n", a.stack[i]);
				// 	i--;
				// }
				// printf("==========\n");
				// i = b.position - 1;
				// while (i >= 0)
				// {
				// 	printf("%d\n", b.stack[i]);
				// 	i--;
				// }
			}
		}
		free(a.stack);
		free(b.stack);
	}
	return (0);
}

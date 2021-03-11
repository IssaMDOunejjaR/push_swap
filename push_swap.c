/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:22:16 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/11 18:53:13 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		is_smallest_number(t_stack *stack, int number)
{
	int		i;

	i = 0;
	while (i < stack->position)
	{
		if (stack->stack[i] < number)
			return (1);
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
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
				while (1)
				{
					if (is_sorted(&a) == 0 && b.position == 0)
						break ;
					else if (is_sorted(&a) == 0 && b.position != 0)
					{
						ft_putendl_fd("pa", 1);
						push_stack_val(&a, &b);
					}
					else if (a.position - 1 >= 0 && a.position - 2 >= 0 && a.stack[a.position - 1] > a.stack[a.position - 2])
					{
						ft_putendl_fd("sa", 1);
						swap_stack(&a);
					}
					else if (is_smallest_number(&a, a.stack[a.position - 1]) == 0)
					{
						ft_putendl_fd("pb", 1);
						push_stack_val(&b, &a);
					}
					else
					{
						ft_putendl_fd("rra", 1);
						reverse_rotate_stack(&a);
					}
				}
				// i = a.position - 1;
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

/*
	6		1		8		1		2		1		0												0
	1		6		1		8		1		2		1												1
	9		9		6		6		8		8		2												2
	4		4		9		9		6		6		8		8		6		7		6		4		4
	7		7		4		4		9		9		6		6		8		6		7		6		6
	0		0		7		7		4		4		9		9	2	9	2	8	2	8	2	7	2	7
	2		2		0		0		7		7		4		4	1	4	1	9	1	9	1	8	1	8
	8		8		2		2		0		0		7		7	0	7	0	4	0	4	0	9	0	9
	=	=	=	=	=	=	=	=	=	=	=	=	=	=	=	=	=	=	=	=	=	=	=	=	=	=
	a	b	a	b	a	b	a	b	a	b	a	b	a	b	a	b	a	b	a	b	a	b	a	b	a	b

	sa
	rra
	sa
	rra
	sa
	rra
	pb
	pb
	pb
	sa
	rra
	sa
	rra
	pa
	pa
	pa

	if a = sorted && b = empty		==> finish
	if a = sorted && b = not empty 	==> push b -> a
	if a[0] = is the small number	==> push a -> b
	if 0 > 1 						==> swap
	

	a = 28074916
	b =
	a = 2807496
	b = 1
	a = 280749
	b = 16
	a = 28079
	b = 164
	a = 2809
	b = 1647
	a = 289
	b = 16470
	a = 29
	b = 164708
	a = 9
	b = 1647082
	a = 98
	b = 164702
	a = 982
	
	sa
	pb
	pb
	sa
	pb
	sa
	pb
	sa
	pb
	sa
	pb
	sa
	pb
	sb
	pa
*/
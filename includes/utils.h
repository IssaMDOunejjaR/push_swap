/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:31:16 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/10 11:22:39 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

# define BUFFER_SIZE 1

typedef struct	s_stack
{
	int		*stack;
	int		position;
	int		length;
}				t_stack;

int		ft_strcmp(char *s1, char *s2);

int		len_table(char **tab);
char	**tab_join(char **tab, char *line);
void	free_table(char **tab);

int		get_next_line(int fd, char **line);

int		check_double_val(t_stack *stack);
int		is_sorted(t_stack *stack);
char	**init_value(t_stack *a, t_stack *b, char **argv, int argc);

void	push(t_stack *dest, int value);
int		pop(t_stack *stack);
int		fill_stack(t_stack *dest, char **tmp, char **argv);

void	push_stack_val(t_stack *dest, t_stack *src);

void	swap_stack(t_stack *stack);
void	swap_both(t_stack *a, t_stack *b);

void	rotate_stack(t_stack *stack);
void	rotate_both(t_stack *a, t_stack *b);
void	reverse_rotate_stack(t_stack *stack);
void	reverse_rotate_both(t_stack *a, t_stack *b);

#endif
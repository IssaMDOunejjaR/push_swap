/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:31:16 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/14 11:12:22 by iounejja         ###   ########.fr       */
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

typedef struct	s_option
{
	int			display_status;
	int			color_last_option;
	int			read;
	int			write;
	char		*read_file;
	char		*write_file;
}				t_option;

typedef struct	s_stack
{
	int			*stack;
	int			position;
}				t_stack;

int				ft_strcmp(char *s1, char *s2);
int				len_table(char **tab);
char			**tab_join(char **tab, char *line);
void			free_table(char **tab);
int				get_next_line(int fd, char **line);
int				check_double_val(char **tab);
int				is_sorted(t_stack *stack);
char			**init_value(t_stack *a, t_stack *b, char **argv, int argc);
void			init_option(t_option *options);
void			print_stack(t_stack *stack, int fd);
void			push(t_stack *dest, int value);
int				pop(t_stack *stack);
int				fill_stack(t_stack *dest, char **tmp, char **argv, t_option *options);
void			display_status(t_stack *a, t_stack *b, char *instruction, int fd);
int				check_options(t_option *options, char **tab, int i);
void			push_stack_val(t_stack *dest, t_stack *src);
void			swap_stack(t_stack *stack);
void			swap_both(t_stack *a, t_stack *b);
void			rotate_stack(t_stack *stack);
void			rotate_both(t_stack *a, t_stack *b);
void			reverse_rotate_stack(t_stack *stack);
void			reverse_rotate_both(t_stack *a, t_stack *b);

#endif

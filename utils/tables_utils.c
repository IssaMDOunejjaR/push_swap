/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tables_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:30:29 by iounejja          #+#    #+#             */
/*   Updated: 2021/03/09 11:20:27 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		len_table(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

char	**tab_join(char **tab, char *line)
{
	char	**new_tab;
	int		i;

	new_tab = malloc(sizeof(char*) * (len_table(tab) + 2));
	i = 0;
	while (tab[i] != NULL)
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	new_tab[i] = ft_strdup(line);
	new_tab[++i] = NULL;
	free_table(tab);
	return (new_tab);
}

void	free_table(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

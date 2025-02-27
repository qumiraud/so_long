/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:03:03 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/27 14:52:46 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_clear_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free (tab);
}

void	ft_init_map(t_map **map_lst, char ***map_tab)
{
	t_map	*nav;
	int		i;

	i = -1;
	nav = (*map_lst);
	*map_tab = malloc((ft_lst_map_size(*map_lst) + 1) * sizeof(char *));
	if (!(*map_tab))
	{
		ft_clear_maplines(map_lst);
		return ;
	}
	while (nav)
	{
		(*map_tab)[++i] = malloc((ft_strlen(nav->map_line) + 1) * sizeof(char));
		if (!(*map_tab)[i])
		{
			ft_clear_tab(*map_tab);
			ft_clear_maplines(map_lst);
			exit(EXIT_FAILURE);
		}
		ft_strcpy(nav->map_line, (*map_tab)[i]);
		nav = nav->next;
	}
	(*map_tab)[++i] = NULL;
}

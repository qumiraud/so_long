/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:03:03 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/17 15:26:44 by qumiraud         ###   ########.fr       */
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

char **ft_init_map(t_map **map_lst)
{
	t_map	*nav;
	char	**map;
	int		i;

	i = -1;
	nav = (*map_lst);
	map = malloc(sizeof(char *) + 1);
	if (!map)
	{
		ft_clear_maplines(map_lst);
		return (NULL);
	}
	while (map[++i])
	{
		map[i] = malloc(sizeof(char) + 1);
		if (!map[i])
		{
			ft_clear_tab(map);
			ft_clear_maplines(map_lst);
			exit(EXIT_FAILURE);
		}
		ft_strcpy(nav->map_line, map[i]);
		nav = nav->next;
	}
	return (map);
}

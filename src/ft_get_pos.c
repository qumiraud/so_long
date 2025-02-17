/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:38:52 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/17 15:53:40 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_get_pos_x(char **map_tab)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (map_tab[i])
	{
		while (map_tab[i][x])
		{
			if (ft_strchr(map_tab[i][x], 'P') == 'P')
				return (x);
			x++;
		}
		i++;
	}
	return (0);
}

int	ft_get_pos_y(char **map_tab)
{
	int	y;
	int	j;

	while (map_tab[y])
	{
		while (map_tab[y][j])
		{
			if (ft_strchr(map_tab[y][j], 'P') == 'P')
				return (y);
			j++;
		}
		y++;
	}
	return (0);
}


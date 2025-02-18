/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:38:52 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/18 11:54:13 by qumiraud         ###   ########.fr       */
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
		x = 0;
		while (map_tab[i][x])
		{
			if (map_tab[i][x] == 'P')
				return (x);
			x++;
		}
		i++;
	}
	printf("je passe par la \n");
	return (x);
}

int	ft_get_pos_y(char **map_tab)
{
	int	y;
	int	j;

	j = 0;
	y = 0;
	while (map_tab[y])
	{
		j = 0;
		while (map_tab[y][j])
		{
			if (map_tab[y][j] == 'P')
				return (y);
			j++;
		}
		y++;
	}
	return (y);
}


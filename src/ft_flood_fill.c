/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:10:47 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/17 15:47:04 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_prep_tab(t_map **map_lst, char **map_tab)
{
	int	c;
	int	i;

	i = -1;
	c = 0;
	map_tab = ft_init_map(map_lst);
	ft_clear_maplines(map_lst);

	while (map_tab[++i])
		c = ft_count_element_c(map_tab[i], c);


	ft_flood_fill(map_tab, c, ft_get_pos_x(map_tab), ft_get_pos_y(map_tab));


}

int	ft_flood_fill(char **map_tab, int c, int x, int y)
{
	// int	x;
	// int	y;

	// x = 0;
	// y = 0;

	if ()

	// ft_flood_fill();

		return (8);


	return (0);
}
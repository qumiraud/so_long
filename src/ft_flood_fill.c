/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:10:47 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/18 17:09:05 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_case_pos(char **map_tab, int *c, int x, int y)
{
	if (map_tab[y][x] ==  'C' || map_tab[y][x] == 'E')
	{
		(*c)--;
		map_tab[y][x] = 'X';
	}
	else if (map_tab[y][x] == '0')
		map_tab[y][x] = 'X';
}

int	ft_flood_fill(char **map_tab, int *c, int x, int y)
{
	//map_tab[y][x]
		int i = 0;
	// int	y;
	printf("-------|%d|-------\n\n", *c);
	printf("-------|%c|\n", map_tab[y][x - 1]);

	if (*c == -1)
		return (0);
	else if (map_tab[y][x] == 'P')
	{
		map_tab[y][x] = 'X';
		ft_flood_fill(map_tab, c, x, y);
	}
	if (map_tab[y - 1][x] != '1' && map_tab[y - 1][x] != 'X')
	{
		i = 0;
		while (map_tab[i])
		{
			// printf("\n second map\n%s\n", (map_tab)[i]);
			i++;
		}
		// printf("cas 1\n");
		ft_case_pos(map_tab, c, x, y);
		y--;
		ft_flood_fill(map_tab, c, x, y);
		// if (map_tab[y + 1][x] == 'C')
			// c--;
		// map_tab[y + 1][x] = 'x';
	}
	else if (map_tab[y][x + 1] != '1' && map_tab[y][x + 1] != 'X')
	{
		i = 0;
		while (map_tab[i])
		{
			// printf("\n second map\n%s\n", (map_tab)[i]);
			i++;
		}
		// printf("cas 2\n");
		ft_case_pos(map_tab, c, x, y);
		x++;
		ft_flood_fill(map_tab, c, x, y);

		// if (map_tab[y][x + 1 ] == 'C')
		// 	c--;
		// map_tab[y][x + 1] = 'x';
	}
	else if (map_tab[y + 1][x] != '1' && map_tab[y + 1][x] != 'X')
	{
		i = 0;
		while (map_tab[i])
		{
			// printf("\n second map\n%s\n", (map_tab)[i]);
			i++;
		}
		// printf("cas 3\n");
		ft_case_pos(map_tab, c, x, y);
		y++;
		ft_flood_fill(map_tab, c, x, y);
		// if (map_tab[y - 1][x] == 'C')
		// 	c--;
		// map_tab[y - 1][x] = 'x';
	}
	else if (map_tab[y][x - 1] != '1' && map_tab[y][x - 1] != 'X')
	{
		i = 0;
		while (map_tab[i])
		{
			// printf("\n second map\n%s\n", (map_tab)[i]);
			i++;
		}
		printf("cas 4\n");
		ft_case_pos(map_tab, c, x, y);
		x--;
		ft_flood_fill(map_tab, c, x, y);
		// if (map_tab[y][x - 1 ] == 'C')
		// 	c--;
		// map_tab[y][x - 1] = 'x';
	}
	if (*c == -1)
		return (0);

	// printf ("c_value in flood_fill : %d\n", *c);

	return (8);


}

int	ft_prep_tab(t_map **map_lst, char ***map_tab)
{
	int	c;
	int	i;

	i = 0;
	c = 0;

	ft_init_map(map_lst, map_tab);
	//printf("%s\n", (*map_tab)[0]);


	ft_clear_maplines(map_lst);


	while ((*map_tab)[i])
	{
		printf("%s | %d\n", (*map_tab)[i], c);
		c += ft_count_element_c((*map_tab)[i], c);
		i++;
	}
	// while ((*map_tab)[y])
	// {
	// 	y++;
	// }
	// int x = 0;



//	return (0);
	return(ft_flood_fill((*map_tab), &c, ft_get_pos_x(*map_tab), ft_get_pos_y(*map_tab)));
}

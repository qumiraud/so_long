/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:10:47 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/27 16:24:53 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	ft_case_pos(char **map_tab, int *c, int x, int y)
// {
// 	if (map_tab[y][x] ==  'C' || map_tab[y][x] == 'E')
// 	{
// 		(*c)--;
// 		map_tab[y][x] = 'X';
// 	}
// 	else if (map_tab[y][x] == '0')
// 		map_tab[y][x] = 'X';
// }

int	ft_flood_fill(char **map_tab, int *c, int x, int y)
{
	if (map_tab[y][x] == 'C' || map_tab[y][x] == 'E')
		(*c)--;
	if (map_tab[y][x] != '1' && map_tab[y][x] != 'X')
	{
		map_tab[y][x] = 'X';
		ft_flood_fill(map_tab, c, (x + 1), y);
		ft_flood_fill(map_tab, c, x, (y + 1));
		ft_flood_fill(map_tab, c, (x - 1), y);
		ft_flood_fill(map_tab, c, x, (y - 1));
	}
	if (*c == -1)
		return (0);
	return (8);
}

int	ft_check_borders(t_map **map_list)
{
	t_map	*nav;
	int		i;

	i = 0;
	nav = *map_list;
	while ((size_t)i < ft_strlen(nav->map_line) - 1)
	{
		if (nav->map_line[i] != '1')
		{
			printf("%s   -ko\n", nav->map_line);
			return (7);
		}
		i++;
	}
	printf("%s   -ok\n", nav->map_line);
	nav = nav->next;
	while (nav->next->next)
	{
		if (nav->map_line[0] != '1' || nav->map_line[ft_strlen(nav->map_line) - 2] != '1')
		{
			printf("pos : %d  | %s index0 : %c indexend : %c -ko\n",nav->index_line, nav->map_line, nav->map_line[0], nav->map_line[ft_strlen(nav->map_line) - 2]);
			return (7);
		}
		printf("%s   -ok\n", nav->map_line);
		nav = nav->next;
	}
	nav = nav->next;
	i = 0;
	while ((size_t)i < ft_strlen(nav->map_line) - 1)
	{
		if (nav->map_line[i] != '1')
		{
			printf("%s   -ko\n", nav->map_line);
			return (7);
		}
		i++;
	}
	printf("%s   -ok\n", nav->map_line);
	return (0);
}

int	ft_prep_tab(t_map **map_lst, char ***map_tab)
{
	int		c;
	int		i;
	char	**tmp_tab = NULL;

	i = 0;
	c = 0;
	if (ft_check_borders(map_lst) != 0)
		return(7);
	ft_init_map(map_lst, map_tab);
	ft_init_map(map_lst, &tmp_tab);
	ft_clear_maplines(map_lst);
	while ((tmp_tab)[i])
	{
		c += ft_count_element_c((tmp_tab)[i], c);
		i++;
	}
	if (ft_flood_fill((tmp_tab), &c, ft_get_pos_x(tmp_tab), ft_get_pos_y(tmp_tab)) != 0)
		return (8);
	ft_clear_tab(tmp_tab);
	return(0);
}

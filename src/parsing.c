/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:55:06 by quentin           #+#    #+#             */
/*   Updated: 2025/02/17 14:10:06 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////
// verif extension de la map

#include "../includes/so_long.h"

int	ft_map_element(t_map *map_lines)
{
	t_map	*nav;
	int		p; // == 1 a la fin;
	int		c; // == X a la fin;
	int		e; // == 1 a la fin;

	p = 0;
	c = 0;
	e = 0;
	nav = map_lines;
	while (nav)
	{
		if (ft_count_element_true(nav->map_line) != 0)
			return (6);
		p += ft_count_element_p(nav->map_line, p);
		c += ft_count_element_c(nav->map_line, c);
		e += ft_count_element_e(nav->map_line, e);
		nav = nav->next;
	}
	if (p != 1)
		return (3);
	else if (c < 1)
		return (4);
	else if (e != 1)
		return (5);
	return (0);
}

int	ft_map_content(t_map **map_lines)
{
	int	map_elem_res;

	map_elem_res = 0;
	map_elem_res = ft_map_element(*map_lines);
	if (map_elem_res != 0)
		return (map_elem_res);



	return (0);
}
// rassemble les fonctions de parsing pour valider la map

void	map_in_struct(int fd, t_map **map_lines)
{
	int		i;
	t_map *nav;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return;
	while (line)
	{
		ft_addline_back(map_lines, ft_newline_map(line));
		line = get_next_line(fd);
	}
	nav = (*map_lines);
	while (nav)
	{
		nav->index_line = i;
		i++;
		nav = nav->next;
	}
	return;
}

int	ft_map_form(int fd, t_map **map_lines)
{
	t_map *nav_map_lines;

	map_in_struct(fd, map_lines);
	nav_map_lines = (*map_lines);
	if (fd <= 0)
	{
		close (fd);
		exit(EXIT_FAILURE);
	}
	while (nav_map_lines->next)
	{
		if (nav_map_lines->len != nav_map_lines->next->len)
		{
//			close (fd);
			return (2);
		}
		nav_map_lines = nav_map_lines->next;
	}
	return (0);
}

int	ft_map_file_name(char *str, t_map **map_lines)
{
	int	i;
	int	fd;
	int	parse_res;

	i = 0;
	fd = 0;
	parse_res = 0;
	while (str[i] != '\0')
		i++;
	if (i == 4)
		return (1);
	if (str[i - 1] == 'r' && str[i - 2] == 'e'
		&& str[i - 3] == 'b' && str[i - 4] == '.')
	{
		fd = open(str, O_RDONLY);
		if (fd > 0)
		{
			parse_res = ft_map_form(fd, map_lines);
			if (parse_res == 0)
			{
				parse_res = ft_map_content(map_lines);
				if (parse_res == 0) //check les murs ext &&
					return (0);						//le P et le C et le E
				else
					return (parse_res);
			}
			else
				return (parse_res);
		}
	}
	return (1);
}

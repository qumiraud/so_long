/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list_fctn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 08:55:00 by quentin           #+#    #+#             */
/*   Updated: 2025/02/13 14:33:38 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*ft_newline_map(char *str)
{
	t_map	*new_mapline;

	new_mapline = NULL;
	new_mapline = malloc(sizeof(t_map));
	if (!new_mapline)
		return (NULL);
	new_mapline->map_line = str;
	new_mapline->len = ft_strchrlen(str);
	new_mapline->index_line = 0;
	new_mapline->next = NULL;

/////////////////////////////////////
//	free (new_mapline->map_line);
//	free (new_mapline);
/////////////////////////////////////

	return (new_mapline);
}

void	ft_addline_back(t_map **line_map, t_map *new_line)
{
	t_map	*nav_linemap;

	if (!*line_map)
	{
		*line_map = new_line;
		return;
	}
	nav_linemap = *line_map;
	while (nav_linemap->next)
		nav_linemap = nav_linemap->next;
	nav_linemap->next = new_line;
}

void	ft_clear_maplines(t_map **line_map)
{
	t_map	*nav_linemap;

	nav_linemap = NULL;
	if (!line_map)
		return ;
	while (*line_map)
	{
		nav_linemap = *line_map;
		//  free ((*line_map)->map_line);
		*line_map = (*line_map)->next;
		free(nav_linemap);
	}
	line_map = NULL;
}
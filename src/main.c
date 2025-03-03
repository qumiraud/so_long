/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:18:43 by quentin           #+#    #+#             */
/*   Updated: 2025/03/03 09:35:36 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_arg_counter(int argc)
{
	if (argc != 2)
	{
		printf("wrong argument number");
		exit (EXIT_FAILURE);
	}
}

void	ref_main(int map_parse, t_map *map_lines, char **map_tab)
{
	error_case(map_parse);
	if (map_lines)
		ft_clear_maplines(&map_lines);
	if (map_tab)
		ft_clear_tab(map_tab);
}

int	main(int argc, char **argv)
{
	char		**map_tab;
	t_map		*map_lines;
	int			map_parse;

	map_tab = NULL;
	map_lines = NULL;
	check_arg_counter(argc);
	map_parse = ft_map_file_name(argv[1], &map_lines);
	if (map_parse != 0)
	{
		ref_main(map_parse, map_lines, map_tab);
		return (1);
	}
	map_parse = ft_prep_tab(&map_lines, &map_tab);
	if (map_parse != 0)
	{
		ref_main(map_parse, map_lines, map_tab);
		return (1);
	}
	ft_init_mlx(map_tab);
	return (0);
}

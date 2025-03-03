/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:15:21 by quentin           #+#    #+#             */
/*   Updated: 2025/03/03 10:06:49 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_putstr_error(char *str, char *color)
{
	write(2, color, ft_strlen(color));
	write(2, str, ft_strlen(str));
	write(2, RESET_COLOR, ft_strlen(RESET_COLOR));
}

void	error_case(int error_code)
{
	if (error_code == 1)
	{
		ft_putstr_error("wrong map extension or file not found\n", RED);
		exit (EXIT_FAILURE);
	}
	else if (error_code == 2)
		ft_putstr_error("the map isn't a rectangle\n", RED);
	else if (error_code == 3)
		ft_putstr_error("bad number of player\n", RED);
	else if (error_code == 4)
		ft_putstr_error("consumable missing\n", RED);
	else if (error_code == 5)
		ft_putstr_error("bad number of escape\n", RED);
	else if (error_code == 6)
		ft_putstr_error("Wrong or empty case in map\n", RED);
	else if (error_code == 7)
		ft_putstr_error("map's borders aren't complete\n", RED);
	else if (error_code == 8)
		ft_putstr_error("Elements aren't collectible\n", YELLOW);
	else if (error_code == 10)
	{
		ft_putstr_error("the map is bigger than the window\n", YELLOW);
		ft_putstr_error("pls resize the map\n", YELLOW);
		ft_putstr_error("max_width : 22 | max_height : 15\n", YELLOW);
	}
}

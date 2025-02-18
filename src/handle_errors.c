/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:15:21 by quentin           #+#    #+#             */
/*   Updated: 2025/02/18 10:29:34 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_putstr_error(char *str, char *color)
{
	write(2, color, ft_strlen(color));
	write(2, str, ft_strlen(str));
	write(2, RESET_COLOR, ft_strlen(RESET_COLOR));
}

void	error_case(int  error_code)
{
	// 1 - bad file extension (!= ".ber")
	if (error_code == 1)
	{
		ft_putstr_error("wrong map extension or file not found\n", RED);
		exit (EXIT_FAILURE);
	}
	// 2 - bad map's form
	else if (error_code == 2)
		ft_putstr_error("the map isn't a rectangle\n", RED);
	// 3 -  player's problem
	else if (error_code == 3)
		ft_putstr_error("bad number of player\n", RED);
	// 4 - consommable's problem
	else if (error_code == 4)
		ft_putstr_error("consumable missing\n", RED);
	// 5 - escape's problem
	else if (error_code == 5)
		ft_putstr_error("bad number of escape\n", RED);
	// 6 - escape's problem
	else if (error_code == 6)
		ft_putstr_error("Wrong or empty case in map\n", RED);
	// 7 - problem is coming


	// 8 - element aren't collectible
	else if (error_code == 8)
		ft_putstr_error("Elements aren't collectible\n", YELLOW);
	}

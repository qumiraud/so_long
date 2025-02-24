/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:07:02 by quentin           #+#    #+#             */
/*   Updated: 2025/02/24 15:42:36 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_to_right(t_image img)
{
	int	x;
	int	y;

	printf("coucou mtr\n");
	x = ft_get_pos_x(img.map);
	y = ft_get_pos_y(img.map);
	if (img.map[y][x + 1] != '1')
	{
		img.map[y][x] = '0';
		img.map[y][x + 1] = 'P';
	}
}

void	move_to_left(t_image img)
{
	int	x;
	int	y;

	printf("coucou mtl\n");
	x = ft_get_pos_x(img.map);
	y = ft_get_pos_y(img.map);
	if (img.map[y][x - 1] != '1')
	{
		img.map[y][x] = '0';
		img.map[y][x - 1] = 'P';
	}
}

void	move_up(t_image img)
{
	int	x;
	int	y;

	printf("coucou mtu\n");
	x = ft_get_pos_x(img.map);
	y = ft_get_pos_y(img.map);
	if (img.map[y - 1][x] != '1')
	{
		img.map[y][x] = '0';
		img.map[y - 1][x] = 'P';
	}
}

void	move_down(t_image img)
{
	int	x;
	int	y;

	printf("coucou mtd\n");
	x = ft_get_pos_x(img.map);
	y = ft_get_pos_y(img.map);
	if (img.map[y + 1][x] != '1')
	{
		img.map[y][x] = '0';
		img.map[y + 1][x] = 'P';
	}
}
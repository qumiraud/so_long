/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:00:40 by quentin           #+#    #+#             */
/*   Updated: 2025/02/27 11:53:10 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clear_counter(t_image img, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			mlx_pixel_put(img.win.mlx_ptr, img.win.mlx_win,
				img.width + i, img.height -10 + j, color);
			j++;
		}
		i++;
	}
}

void	counter_on_window(t_image img)
{
	char	*tmp;
	char	*counter_str;

	clear_counter(img, 20, 10, 0x000000);
	tmp = ft_itoa(img.win.counter);
	counter_str = ft_strdup(tmp);
	mlx_string_put(img.win.mlx_ptr, img.win.mlx_win, img.width,
		img.height, 0xFFFFFF, counter_str);
	ft_printf("move counter : %d\n", img.win.counter);
	free(tmp);
	free(counter_str);
}

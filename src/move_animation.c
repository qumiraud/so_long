/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:12:56 by quentin           #+#    #+#             */
/*   Updated: 2025/02/27 17:06:18 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	anim_move_right(t_image img, int x, int y)
{
	int		i;

	i = 48;
	while (--i > 0)
	{
		if (i % 2 == 0)
		{
			img.img_ptr = mlx_xpm_file_to_image(img.win.mlx_ptr,
					"C_F_F/P_pos/P_moveR.xpm", &(img.width), &(img.height));
			mlx_put_image_to_window(img.win.mlx_ptr, img.win.mlx_win,
				img.img_ptr, (x + 1) * 48 - i, y * 48);
			mlx_destroy_image(img.win.mlx_ptr, img.img_ptr);
		}
		else
		{
			img.img_ptr = mlx_xpm_file_to_image(img.win.mlx_ptr,
					"C_F_F/P_pos/P_moveR_2.xpm", &(img.width), &(img.height));
			mlx_put_image_to_window(img.win.mlx_ptr,
				img.win.mlx_win, img.img_ptr, (x + 1) * 48 - i, y * 48);
			mlx_destroy_image(img.win.mlx_ptr, img.img_ptr);
		}
	}
}

void	anim_move_up(t_image img, int x, int y)
{
	int	i;

	i = 48;
	while (--i >= 0)
	{
		if (i > 24)
		{
			img.img_ptr = mlx_xpm_file_to_image(img.win.mlx_ptr,
					"C_F_F/P_pos/P_moveB.xpm", &(img.width), &(img.height));
			mlx_put_image_to_window(img.win.mlx_ptr, img.win.mlx_win,
				img.img_ptr, x * 48 + 10, (y - 1) * 48 + i);
			mlx_destroy_image(img.win.mlx_ptr, img.img_ptr);
		}
		else
		{
			img.img_ptr = mlx_xpm_file_to_image(img.win.mlx_ptr,
					"C_F_F/P_pos/P_moveB_2.xpm", &(img.width), &(img.height));
			mlx_put_image_to_window(img.win.mlx_ptr, img.win.mlx_win,
				img.img_ptr, x * 48 + 10, (y - 1) * 48 + i);
			mlx_destroy_image(img.win.mlx_ptr, img.img_ptr);
		}
	}
}

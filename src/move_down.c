/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:00:32 by pjurdana          #+#    #+#             */
/*   Updated: 2025/03/03 11:34:00 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ref_move_down(t_image img, int x, int y)
{
	img.map[y][x] = '0';
	img.map[y + 1][x] = 'P';
	img.img_ptr = mlx_xpm_file_to_image(img.win.mlx_ptr,
			"C_F_F/P_pos/D_F.xpm", &(img.width), &(img.height));
	if (!img.img_ptr)
		exit(exit_so_long(&img));
	mlx_put_image_to_window(img.win.mlx_ptr, img.win.mlx_win,
		img.img_ptr, x * 48, y * 48);
	mlx_destroy_image(img.win.mlx_ptr, img.img_ptr);
	img.img_ptr = mlx_xpm_file_to_image(img.win.mlx_ptr,
			"C_F_F/P_pos/P_f.xpm", &(img.width), &(img.height));
	if (!img.img_ptr)
		exit(exit_so_long(&img));
	mlx_put_image_to_window(img.win.mlx_ptr, img.win.mlx_win,
		img.img_ptr, x * 48, (y + 1) * 48);
	mlx_destroy_image(img.win.mlx_ptr, img.img_ptr);
}

void	ref_2_move_down(t_image img, int x, int y)
{
	img.map[y][x] = '0';
	img.map[y + 1][x] = 'P';
	img.img_ptr = mlx_xpm_file_to_image(img.win.mlx_ptr,
			"C_F_F/P_pos/D_F.xpm", &(img.width), &(img.height));
	if (!img.img_ptr)
		exit(exit_so_long(&img));
	mlx_put_image_to_window(img.win.mlx_ptr, img.win.mlx_win,
		img.img_ptr, x * 48, y * 48);
	mlx_destroy_image(img.win.mlx_ptr, img.img_ptr);
	img.img_ptr = mlx_xpm_file_to_image(img.win.mlx_ptr,
			"C_F_F/P_pos/P_f.xpm", &(img.width), &(img.height));
	if (!img.img_ptr)
		exit(exit_so_long(&img));
	mlx_put_image_to_window(img.win.mlx_ptr, img.win.mlx_win,
		img.img_ptr, x * 48, (y + 1) * 48);
	mlx_destroy_image(img.win.mlx_ptr, img.img_ptr);
}

void	move_down(t_image img)
{
	int	x;
	int	y;

	x = ft_get_pos_x(img.map);
	y = ft_get_pos_y(img.map);
	if (img.map[y + 1][x] != '1' )
	{
		if (img.map[y + 1][x] == 'E' && ft_count_collec(img.map) == 0)
			exit_so_long(&img);
		if ((img.map)[y + 1][x] == 'E' && ft_count_collec(img.map) != 0)
			ref_move_down(img, x, y);
		ref_2_move_down(img, x, y);
		if (img.tmp_map[y][x] == 'E')
		{
			img.map[y][x] = 'E';
			img.img_ptr = mlx_xpm_file_to_image(img.win.mlx_ptr,
					"C_F_F/H_I_F.xpm", &(img.width), &(img.height));
			mlx_put_image_to_window(img.win.mlx_ptr, img.win.mlx_win,
				img.img_ptr, x * 48, y * 48);
			mlx_destroy_image(img.win.mlx_ptr, img.img_ptr);
		}
		counter_on_window(img);
	}
}

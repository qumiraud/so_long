/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:07:02 by quentin           #+#    #+#             */
/*   Updated: 2025/02/27 16:24:36 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int    ft_count_collec(char **map_tab)
{
    int    i;
    int    x;

    i = 0;
    x = 0;
    while (map_tab[i])
    {
        x = 0;
        while (map_tab[i][x])
        {
            if (map_tab[i][x] == 'C')
                return (1);
            x++;
        }
        i++;
    }
    return (0);
}

void	move_to_right(t_image img)
{
	int		x;
	int		y;

	x = ft_get_pos_x(img.map);
	y = ft_get_pos_y(img.map);
	if (img.map[y][x + 1] != '1' && (img.map[y][x + 1] != 'E' || ft_count_collec(img.map) == 0))
	{
		if (img.map[y][x + 1] == 'E')
			exit_so_long(&img);
		img.map[y][x] = '0';
		img.map[y][x + 1] = 'P';
		img.img_ptr = mlx_xpm_file_to_image(img.win.mlx_ptr, "C_F_F/T/F_T.xpm", &(img.width), &(img.height));
		mlx_put_image_to_window(img.win.mlx_ptr, img.win.mlx_win, img.img_ptr, x*48, y*48);
		mlx_destroy_image(img.win.mlx_ptr, img.img_ptr);

		anim_move_right(img, x, y);
		img.img_ptr = mlx_xpm_file_to_image(img.win.mlx_ptr, "C_F_F/P_R.xpm", &(img.width), &(img.height));
		mlx_put_image_to_window(img.win.mlx_ptr, img.win.mlx_win, img.img_ptr, (x + 1)*48, y*48);
		mlx_destroy_image(img.win.mlx_ptr, img.img_ptr);
		counter_on_window(img);
	}
}

void	move_to_left(t_image img)
{
	int	x;
	int	y;

	x = ft_get_pos_x(img.map);
	y = ft_get_pos_y(img.map);
	if (img.map[y][x - 1] != '1' && (img.map[y][x - 1] != 'E' || ft_count_collec(img.map) == 0))
	{
		if (img.map[y][x - 1] == 'E')
			exit_so_long(&img);
		img.map[y][x] = '0';
		img.map[y][x - 1] = 'P';
		img.img_ptr = mlx_xpm_file_to_image(img.win.mlx_ptr, "C_F_F/P_L.xpm", &(img.width), &(img.height));
		mlx_put_image_to_window(img.win.mlx_ptr, img.win.mlx_win, img.img_ptr, (x - 1)*48, y*48);
		mlx_destroy_image(img.win.mlx_ptr, img.img_ptr);
		img.img_ptr = mlx_xpm_file_to_image(img.win.mlx_ptr, "C_F_F/T/F_T.xpm", &(img.width), &(img.height));
		mlx_put_image_to_window(img.win.mlx_ptr, img.win.mlx_win, img.img_ptr, x*48, y*48);
		mlx_destroy_image(img.win.mlx_ptr, img.img_ptr);
		counter_on_window(img);
	}
}

void	move_up(t_image img)
{
	int	x;
	int	y;

	x = ft_get_pos_x(img.map);
	y = ft_get_pos_y(img.map);
	if (img.map[y - 1][x] != '1' && (img.map[y - 1][x] != 'E' || ft_count_collec(img.map) == 0))
	{
		if (img.map[y - 1][x] == 'E')
			exit_so_long(&img);

		img.map[y][x] = '0';
		img.map[y - 1][x] = 'P';
		img.img_ptr = mlx_xpm_file_to_image(img.win.mlx_ptr, "C_F_F/T/F_T.xpm", &(img.width), &(img.height));
		mlx_put_image_to_window(img.win.mlx_ptr, img.win.mlx_win, img.img_ptr, x*48, y*48);
		mlx_destroy_image(img.win.mlx_ptr, img.img_ptr);
		img.img_ptr = mlx_xpm_file_to_image(img.win.mlx_ptr, "C_F_F/P_B.xpm", &(img.width), &(img.height));
		mlx_put_image_to_window(img.win.mlx_ptr, img.win.mlx_win, img.img_ptr, x*48, (y - 1) * 48);
		mlx_destroy_image(img.win.mlx_ptr, img.img_ptr);
		counter_on_window(img);
	}
}

void	move_down(t_image img)
{
	int	x;
	int	y;

	x = ft_get_pos_x(img.map);
	y = ft_get_pos_y(img.map);
	if (img.map[y + 1][x] != '1' && (img.map[y + 1][x] != 'E' || ft_count_collec(img.map) == 0))
	{
		if (img.map[y + 1][x] == 'E')
			exit_so_long(&img);

		img.map[y][x] = '0';
		img.img_ptr = mlx_xpm_file_to_image(img.win.mlx_ptr, "C_F_F/T/F_T.xpm", &(img.width), &(img.height));
		mlx_put_image_to_window(img.win.mlx_ptr, img.win.mlx_win, img.img_ptr, x*48, y*48);
		mlx_destroy_image(img.win.mlx_ptr, img.img_ptr);
		img.map[y + 1][x] = 'P';
		img.img_ptr = mlx_xpm_file_to_image(img.win.mlx_ptr, "C_F_F/P_W_T.xpm",
			&(img.width), &(img.height));
		mlx_put_image_to_window(img.win.mlx_ptr, img.win.mlx_win,
			img.img_ptr, x * 48, (y + 1) * 48);
		mlx_destroy_image(img.win.mlx_ptr, img.img_ptr);
		counter_on_window(img);
	}
}

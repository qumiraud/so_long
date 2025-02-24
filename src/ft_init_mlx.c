/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:12:18 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/24 16:13:29 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_win	new_launch(int width, int height,char *str)
{
	t_win	win_return;

	win_return.mlx_ptr = mlx_init();
	win_return.mlx_win = mlx_new_window(win_return.mlx_ptr, width, height, str);
	win_return.width = width;
	win_return.height = height;
	return (win_return);
}

t_image	new_img(int width, int height, t_win mlx_win, char **map)
{
	t_image	img_48x48;
	int	i;
	
	i = 0;
	img_48x48.map = malloc((ft_tablen(map) + 1) * sizeof(char *));
	while (i < ft_tablen(map))
	{
		img_48x48.map[i] = ft_strdup(map[i]);
		i++;
	}
	img_48x48.map[i] = NULL;
	img_48x48.win = mlx_win;
	img_48x48.img_ptr = mlx_new_image(mlx_win.mlx_ptr, width , height);
	img_48x48.addr = mlx_get_data_addr(img_48x48.img_ptr, &(img_48x48.bpp), &(img_48x48.line_len), &(img_48x48.endian));
	img_48x48.width = width;
	img_48x48.height = height;
	return (img_48x48);
}

void	put_pixel_img(t_image img, int x, int y, int color)
{
	char	*dst;
	if (x >= 0 && y >= 0 && x < img.width && y < img.height)
	{
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}



int	exit_so_long(t_win *mlx_win)
{
	if (mlx_win)
		mlx_destroy_window(mlx_win->mlx_ptr, mlx_win->mlx_win);
	exit(EXIT_SUCCESS);
}

void	ft_put_img_on_map(t_image *img_48x48)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (img_48x48->map[i])
	{
		while (img_48x48->map[i][j])
		{
			if (img_48x48->map[i][j] == '0')
			{
				img_48x48->img_ptr = mlx_xpm_file_to_image(img_48x48->win.mlx_ptr, "Cute_Fantasy_Free/Tiles/FarmLand_Tile.xpm", &(img_48x48->width), &(img_48x48->height));
				mlx_put_image_to_window(img_48x48->win.mlx_ptr, img_48x48->win.mlx_win, img_48x48->img_ptr, j*48, i*48);
			}
			if (img_48x48->map[i][j] == '1')
			{
				img_48x48->img_ptr = mlx_xpm_file_to_image(img_48x48->win.mlx_ptr, "Cute_Fantasy_Free/Tiles/grass_with_tulipe.xpm", &(img_48x48->width), &(img_48x48->height));
				mlx_put_image_to_window(img_48x48->win.mlx_ptr, img_48x48->win.mlx_win, img_48x48->img_ptr, j*48, i*48);
			}
			if (img_48x48->map[i][j] == 'P')
			{
				img_48x48->img_ptr = mlx_xpm_file_to_image(img_48x48->win.mlx_ptr, "Cute_Fantasy_Free/Player/voleur de tulipe.xpm", &(img_48x48->width), &(img_48x48->height));
				mlx_put_image_to_window(img_48x48->win.mlx_ptr, img_48x48->win.mlx_win, img_48x48->img_ptr, j*48, i*48);
			}
			if (img_48x48->map[i][j] == 'C')
			{
				img_48x48->img_ptr = mlx_xpm_file_to_image(img_48x48->win.mlx_ptr, "Cute_Fantasy_Free/Oak_tree_in_farmland.xpm", &(img_48x48->width), &(img_48x48->height));
				mlx_put_image_to_window(img_48x48->win.mlx_ptr, img_48x48->win.mlx_win, img_48x48->img_ptr, j*48, i*48);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	ft_init_mlx(char **map_tab)
{
	t_win	so_long;
	t_image	img_48x48;
	// int	i;
	// int	j;

	// i = 0;
	// j = 0;
	so_long = new_launch(1080, 720, "Bonjour Miam LE JEU");
	if (!so_long.mlx_ptr || !so_long.mlx_win)
		return(9);
	img_48x48 = new_img(1080, 720, so_long, map_tab);
	//put_pixel_img(img_48x48, 540, 360, 0x00AA80BB);
	ft_put_img_on_map(&img_48x48);
	// while (map_tab[i])
	// {
	// 	while (map_tab[i][j])
	// 	{
	// 		if (map_tab[i][j] == '0')
	// 		{
	// 			img_48x48.img_ptr = mlx_xpm_file_to_image(img_48x48.win.mlx_ptr, "Cute_Fantasy_Free/Tiles/FarmLand_Tile.xpm", &(img_48x48.width), &(img_48x48.height));
	// 			mlx_put_image_to_window(img_48x48.win.mlx_ptr, img_48x48.win.mlx_win, img_48x48.img_ptr, j*48, i*48);
	// 		}
	// 		if (map_tab[i][j] == '1')
	// 		{
	// 			img_48x48.img_ptr = mlx_xpm_file_to_image(img_48x48.win.mlx_ptr, "Cute_Fantasy_Free/Tiles/grass_with_tulipe.xpm", &(img_48x48.width), &(img_48x48.height));
	// 			mlx_put_image_to_window(img_48x48.win.mlx_ptr, img_48x48.win.mlx_win, img_48x48.img_ptr, j*48, i*48);
	// 		}
	// 		j++;
	// 	}
	// 	j = 0;
	// 	i++;
	// }
	mlx_hook(so_long.mlx_win, KeyPress, KeyPressMask, key_press, &img_48x48);
	mlx_hook(so_long.mlx_win, DestroyNotify, 0, exit_so_long, &img_48x48);
	// printf("Let's find oput what's inside our structure :D\n");
	// printf("img_ptr			: [%p]\n", img_48x48.img_ptr);
	// printf("bpp				: [%d]\n", img_48x48.bpp);
	// printf("line_len		: [%d]\n", img_48x48.line_len);
	// printf("endian			: [%d]\n", img_48x48.endian);
	// printf("addr			: [%p]\n", img_48x48.addr);
	mlx_loop(so_long.mlx_ptr);
	return (0);
}



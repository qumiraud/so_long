/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:12:18 by qumiraud          #+#    #+#             */
/*   Updated: 2025/03/03 11:15:28 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_image	new_img(int width, int height, t_win mlx_win, char **map)
{
	t_image	img_48x48;
	int		i;

	i = 0;
	img_48x48.map = malloc((ft_tablen(map) + 1) * sizeof(char *));
	img_48x48.tmp_map = malloc((ft_tablen(map) + 1) * sizeof(char *));
	while (i < ft_tablen(map))
	{
		img_48x48.map[i] = ft_strdup(map[i]);
		img_48x48.tmp_map[i] = ft_strdup(map[i]);
		i++;
	}
	img_48x48.map[i] = NULL;
	img_48x48.tmp_map[i] = NULL;
	img_48x48.win = mlx_win;
	img_48x48.img_ptr = mlx_new_image(mlx_win.mlx_ptr,
			width, height);
	img_48x48.addr = mlx_get_data_addr(img_48x48.img_ptr,
			&(img_48x48.bpp), &(img_48x48.line_len), &(img_48x48.endian));
	img_48x48.width = width;
	img_48x48.height = height;
	return (img_48x48);
}

int	exit_so_long(t_image *img)
{
	mlx_loop_end(img->win.mlx_ptr);
	mlx_destroy_window(img->win.mlx_ptr, img->win.mlx_win);
	mlx_destroy_display(img->win.mlx_ptr);
	ft_clear_tab(img->map);
	ft_clear_tab(img->tmp_map);
	free(img->win.mlx_ptr);
	exit(EXIT_SUCCESS);
}

void	ref_ft_put_img_on_map(t_image *img_48x48, int i, int j, char *str)
{
	img_48x48->img_ptr = mlx_xpm_file_to_image(img_48x48->win.mlx_ptr, str,
			&(img_48x48->width), &(img_48x48->height));
	if (!(img_48x48->img_ptr))
		exit_so_long(img_48x48);
	mlx_put_image_to_window(img_48x48->win.mlx_ptr, img_48x48->win.mlx_win,
		img_48x48->img_ptr, j * 48, i * 48);
	mlx_destroy_image(img_48x48->win.mlx_ptr, img_48x48->img_ptr);
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
				ref_ft_put_img_on_map(img_48x48, i, j, "C_F_F/P_pos/D_F.xpm");
			if (img_48x48->map[i][j] == '1')
				ref_ft_put_img_on_map(img_48x48, i, j, "C_F_F/T/G_W_T.xpm");
			if (img_48x48->map[i][j] == 'P')
				ref_ft_put_img_on_map(img_48x48, i, j, "C_F_F/P_pos/P_f.xpm");
			if (img_48x48->map[i][j] == 'C')
				ref_ft_put_img_on_map(img_48x48, i, j, "C_F_F/P_pos/Tree.xpm");
			if (img_48x48->map[i][j] == 'E')
				ref_ft_put_img_on_map(img_48x48, i, j, "C_F_F/H_I_F.xpm");
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

	so_long = new_launch(48 * 22, 15 * 48, "Bonjour Miam LE JEU");
	if (!so_long.mlx_ptr || !so_long.mlx_win)
	{
		ft_clear_tab(map_tab);
		return (9);
	}
		img_48x48 = new_img(48 * 22, 15 * 48, so_long, map_tab);
	if (!img_48x48.img_ptr || !img_48x48.addr)
		return (9);
	ft_clear_tab(map_tab);
	mlx_destroy_image(img_48x48.win.mlx_ptr, img_48x48.img_ptr);
	ft_put_img_on_map(&img_48x48);
	mlx_hook(so_long.mlx_win, KeyPress, KeyPressMask, key_press, &img_48x48);
	mlx_hook(so_long.mlx_win, DestroyNotify, 0, exit_so_long, &img_48x48);
	mlx_loop(so_long.mlx_ptr);
	return (0);
}

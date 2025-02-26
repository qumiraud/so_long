/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:01:54 by quentin           #+#    #+#             */
/*   Updated: 2025/02/26 09:53:42 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	cross_click(void *params)
{
	void	**params_tab = (void **)params;

	mlx_destroy_image(params_tab[0], params_tab[2]);
	mlx_destroy_window(params_tab[0], params_tab[1]);
	mlx_destroy_display(params_tab[0]);
	mlx_loop_end(params_tab[0]);
	free (params_tab[0]);
	exit (EXIT_SUCCESS);
	return (0);
}

int esc_key_press(void *params)
{
	void    **params_tab = (void **)params;

//	params[0] = {mlx};
//	params[1] = {mlx_win};
//	params[2] = {img};
	mlx_destroy_image(params_tab[0], params_tab[2]);
	mlx_destroy_window(params_tab[0], params_tab[1]);
	mlx_destroy_display(params_tab[0]);
	mlx_loop_end(params_tab[0]);
	free (params_tab[0]);
	exit (EXIT_SUCCESS);
	return (0);
}

int	check_pos_player(t_image img)
{
	int	x;
	int	y;

	x = ft_get_pos_x(img.map);
	y = ft_get_pos_y(img.map);
	if (img.map[y][x + 1] == '1')
		return (0);
	if (img.map[y][x - 1] == '1')
		return (1);
	if (img.map[y + 1][x] == '1')
		return (2);
	if (img.map[y - 1][x] == '1')
		return (3);
	return (4);
}

int	key_press(int keycode, t_image *params)
{
	t_image	*params_tab = params;

	if (keycode == KEY_ESCAPE) // ESC
		exit_so_long(&params_tab->win);



		
	if (keycode == KEY_D || keycode == XK_Right)
	{
		if (check_pos_player(*params_tab) == 0)
			return (0);
		params_tab->win.counter++;
		move_to_right(*params_tab);
	}
	else if (keycode == KEY_W || keycode == XK_Up)
	{
		if (check_pos_player(*params_tab) == 3)
			return (0);
		params_tab->win.counter++;
		move_up(*params_tab);
	}
	else if (keycode == KEY_A || keycode == XK_Left)
	{
		if (check_pos_player(*params_tab) == 1)
			return (0);
		params_tab->win.counter++;
		move_to_left(*params_tab);
	}
	else if (keycode == KEY_S || keycode == XK_Down)
	{
		if (check_pos_player(*params_tab) == 2)
			return (0);
		params_tab->win.counter++;
		move_down(*params_tab);
	}
	else
		return (0);
	return (0);
}







// int esc_key_press(int keycode, void *params)
// {
//     void    **params_tab = (void **)params;
//     //params[0]={mlx};
//     //params[1]={mlx_win};
//     //params[2]={img};
//     if (keycode == 65307)
//     {
//         mlx_destroy_image( params_tab[0], params_tab[2]);
//         mlx_destroy_window(params_tab[0], params_tab[1]);
//         mlx_destroy_display(params_tab[0]); // gere quasi tout les free
//         mlx_loop_end(params_tab[0]); 
//         free(params_tab[0]);
//         exit (EXIT_SUCCESS);
//     }
//     return (0);
// }



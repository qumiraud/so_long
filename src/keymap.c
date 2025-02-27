/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:01:54 by quentin           #+#    #+#             */
/*   Updated: 2025/02/27 14:49:11 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	ref_key_press(t_image *params, int direction,
	void (*move_function)(t_image))
{
	if (check_pos_player(*params) == direction)
		return (0);
	params->win.counter++;
	move_function(*params);
	return (1);
}

int	key_press(int keycode, t_image *params)
{
	if (keycode == KEY_ESCAPE)
		exit_so_long(params);
	if (keycode == KEY_D || keycode == XK_Right)
		ref_key_press(params, 0, move_to_right);
	else if (keycode == KEY_W || keycode == XK_Up)
		ref_key_press(params, 3, move_up);
	else if (keycode == KEY_A || keycode == XK_Left)
		ref_key_press(params, 1, move_to_left);
	else if (keycode == KEY_S || keycode == XK_Down)
		ref_key_press(params, 2, move_down);
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



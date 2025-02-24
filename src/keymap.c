/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:01:54 by quentin           #+#    #+#             */
/*   Updated: 2025/02/21 19:35:10 by quentin          ###   ########.fr       */
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

int	key_press(int keycode, void *params)
{
	void	*params_tab = params;

	if (keycode == KEY_ESCAPE) // ESC
		exit_so_long(params_tab);
	// if (keycode == 119) // W
	// 	esc_key_press(params_tab);
	// if (keycode == 97) // A
	// 	esc_key_press(params_tab);
	// if (keycode == 115) // S
	// 	esc_key_press(params_tab);
	 //if (keycode == KEY_D) // D
	 //	move_to_riht(params_tab);
	// if (keycode == 65362) // Up Arrow
	// 	esc_key_press(params_tab);
	// if (keycode == 65364) // Down Arrow
	// 	esc_key_press(params_tab);
	// if (keycode == 65361) // Left Arrow
	// 	esc_key_press(params_tab);
	// if (keycode == 65363) // Right Arrow
	// 	esc_key_press(params_tab);
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



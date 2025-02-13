/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:18:43 by quentin           #+#    #+#             */
/*   Updated: 2025/02/13 15:57:26 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/////////////////////////////////////////////////////////
//futur main

void	check_arg_counter(int argc)
{
	if (argc != 2)
	{
		printf("wrong argument number");
		exit (EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_map *map_lines;
	int map_parse;

	map_lines = NULL;
	check_arg_counter(argc);
	map_parse = ft_map_file_name(argv[1], &map_lines);
	if (map_parse != 0)
	{
		error_case(map_parse);
		if (map_lines)
			ft_clear_maplines(&map_lines);
		return (1);
	}
	printf("GG");
	// ft_suite ???
	ft_clear_maplines(&map_lines);
	
	return (0);
}

/////////////////////////////////////////
// #include    "mlx.h"
// #include	"mlx_int.h"

// void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
//     char    *dst;
//     dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
//     *(unsigned int*)dst = color;
// }

// int main(void)
// {
//     mlx_opt  win_params; 
//     //void    *img;
//     char    *relative_path = "./Cute_Fantasy_Free/Player/Player.xpm";
//     //void    **params;

//     win_params.mlx = mlx_init();
//     win_params.mlx_win = mlx_new_window(win_params.mlx, 1080, 720, "Le double vitrage ????");
//     win_params.width = 1080;
//     win_params.height = 720;
//     win_params.img = mlx_xpm_file_to_image(win_params.mlx, relative_path, &win_params.width, &win_params.height);
//     mlx_put_image_to_window(win_params.mlx, win_params.mlx_win, win_params.img, 0, 0);
//     void *params[] = {win_params.mlx, win_params.mlx_win, win_params.img};
//     mlx_hook(win_params.mlx_win, 2, 1L << 0, key_press, params);
//     mlx_hook(win_params.mlx_win, 17, 0, cross_click, params);
//     mlx_loop(win_params.mlx);
//     return (0);
// }




















/*

// main affichant une fenetre fixe grace a un * while (1) *





///////////////////////////////////////////////////////////////

#include <stdlib.h>

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include <X11/keysym.h>


# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

#define MLX_ERROR 1


int main(void)
{
    void	*mlx_ptr;
    void	*win_ptr;

    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
        return (MLX_ERROR);
    win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
    if (win_ptr == NULL)
    {
        free(win_ptr);
        return (MLX_ERROR);
    }
    while (1)
        ;
    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
}


 */
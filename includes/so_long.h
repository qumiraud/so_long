/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:05:59 by quentin           #+#    #+#             */
/*   Updated: 2025/02/20 12:55:08 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <unistd.h>

#include "../libft/libft.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"


typedef struct s_tab_map
{
	char	**map;
}	t_tab_map;

typedef struct s_map
{
    char    *map_line;
    int     len;
    int     index_line;
	struct s_map *previous;
    struct s_map *next;
}   t_map;

typedef struct mlx_opt
{
    void    *mlx;
    void    *mlx_win;
    void    *img;
    int     width;
    int     height;
}                   mlx_opt;

typedef struct s_data
{
    //void	*img;
    char	*addr;
    int		bpp; // bit per pixel
    int		line_length;
	int		endian;
}                   t_data;

//!!!!!!!!!!!   ERRORS COLORS   !!!!!!!!!!!!!!!!!!!!!!!!!!/
# define RESET_COLOR	"\x1b[0m"
# define RED			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define PURPLE			"\x1b[35m"
# define CYAN			"\x1b[36m"
# define BLANC			"\x1b[37m"
//!!!!!!!!!!!   ERRORS COLORS   !!!!!!!!!!!!!!!!!!!!!!!!!!/

////////////*map_list_fctn.c////////////////
t_map	*ft_newline_map(char *str);
void	ft_addline_back(t_map **line_map, t_map *new_line);
void	ft_clear_maplines(t_map **line_map);
int		ft_lst_map_size(t_map *lst_map);



////////////*keymap.c////////////////
int	esc_key_press(void *params);
int	key_press(int keycode, void *params);
int	cross_click(void *params);

////////////*handle_errors.c////////////////
void	error_case(int  error_code);
void	ft_putstr_error(char *str, char *color);


////////////*parsing.c////////////////
int		ft_map_file_name(char *str, t_map **map_lines);
int		ft_map_form(int fd, t_map **map_lines);
void	map_in_struct(int fd, t_map **map_lines);

////////////*ft_count_element.c////////////////
int		ft_count_element_p(char *line, int p);
int		ft_count_element_c(char *line, int c);
int		ft_count_element_e(char *line, int e);
int		ft_count_element_true(char *line);

////////////*ft_init_tab.c////////////////
void	ft_init_map(t_map **map_lst, char ***map_tab);
void	ft_clear_tab(char **tab);

////////////*ft_flood_fill.c////////////////
int	ft_prep_tab(t_map **map_lst, char ***map_tab);
int	ft_flood_fill(char **map_tab, int *c, int x, int y);

////////////*ft_get_pos.c////////////////
int	ft_get_pos_x(char **map_tab);
int	ft_get_pos_y(char **map_tab);




////////////////////////////

//# include <stdio.h>

////////////////////////////



#endif
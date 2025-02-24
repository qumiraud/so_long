/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:05:59 by quentin           #+#    #+#             */
/*   Updated: 2025/02/21 19:47:53 by quentin          ###   ########.fr       */
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
	char			*map_line;
	int				len;
	int				index_line;
	struct s_map	*previous;
	struct s_map	*next;
}				t_map;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		width;
	int		height;
}				t_win;

typedef struct s_image
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		height;
	int		width;
	int		bpp; // bit per pixel
	int		endian;
	int		line_len;
	char 	**map; //map de jeu
}				t_image ;

//!!!!!!!!!!!	ENUM KEYCODE    !!!!!!!!!!!!!!!!!!!!!!!!!!/
enum KeyCode {
    KEY_A = XK_a,
    KEY_B = XK_b,
    KEY_C = XK_c,
    KEY_D = XK_d,
    KEY_E = XK_e,
    KEY_F = XK_f,
    KEY_G = XK_g,
    KEY_H = XK_h,
    KEY_I = XK_i,
    KEY_J = XK_j,
    KEY_K = XK_k,
    KEY_L = XK_l,
    KEY_M = XK_m,
    KEY_N = XK_n,
    KEY_O = XK_o,
    KEY_P = XK_p,
    KEY_Q = XK_q,
    KEY_R = XK_r,
    KEY_S = XK_s,
    KEY_T = XK_t,
    KEY_U = XK_u,
    KEY_V = XK_v,
    KEY_W = XK_w,
    KEY_X = XK_x,
    KEY_Y = XK_y,
    KEY_Z = XK_z,
    KEY_SPACE = XK_space,
    KEY_ENTER = XK_Return,
    KEY_ESCAPE = XK_Escape,
    KEY_BACKSPACE = XK_BackSpace,
    KEY_TAB = XK_Tab,
    KEY_SHIFT_L = XK_Shift_L,
    KEY_SHIFT_R = XK_Shift_R,
    KEY_CTRL_L = XK_Control_L,
    KEY_CTRL_R = XK_Control_R,
    KEY_ALT_L = XK_Alt_L,
    KEY_ALT_R = XK_Alt_R
};
//!!!!!!!!!!!	ENUM KEYCODE    !!!!!!!!!!!!!!!!!!!!!!!!!!/



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

////////////*ft_init_mlx.c////////////////

t_win	new_launch(int width, int height,char *str);
t_image	new_img(int width, int height, t_win mlx_win, char **map);
int		ft_init_mlx(char **map_tab);
void	put_pixel_img(t_image img, int x, int y, int color);
int		exit_so_long(t_win *mlx_win);






////////////////////////////

//# include <stdio.h>

////////////////////////////



#endif
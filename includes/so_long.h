/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:05:59 by quentin           #+#    #+#             */
/*   Updated: 2025/03/03 10:28:52 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <unistd.h>

# include "../libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

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
	int		counter;
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
	int		x;
	int		y;//test x/y
	char	**map; //map de jeu
	char	**tmp_map;
}				t_image;

//!!!!!!!!!!!	ENUM KEYCODE    !!!!!!!!!!!!!!!!!!!!!!!!!!/
enum e_keycode {
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
int		key_press(int keycode, t_image *params);
int		ref_key_press(t_image *params, int direction,
			void (*move_function)(t_image));
int		check_pos_player(t_image img);

////////////*handle_errors.c////////////////
void	error_case(int error_code);
void	ft_putstr_error(char *str, char *color);

////////////*parsing.c////////////////
int		ft_map_file_name(char *str, t_map **map_lines);
int		ref_map_file(char *str, int i, int parse_res, t_map **map_lines);
int		ft_map_form(int fd, t_map **map_lines, int i);
void	map_in_struct(int fd, t_map **map_lines);
int		ft_map_element(t_map *map_lines);
int		ft_map_content(t_map **map_lines);

////////////*ft_count_element.c////////////////
int		ft_count_element_p(char *line, int p);
int		ft_count_element_c(char *line, int c);
int		ft_count_element_e(char *line, int e);
int		ft_count_element_true(char *line);

////////////*ft_init_tab.c////////////////
void	ft_clear_tab(char **tab);
void	ft_init_map(t_map **map_lst, char ***map_tab);

////////////*ft_flood_fill.c////////////////
int		ft_prep_tab(t_map **map_lst, char ***map_tab);
int		ft_flood_fill(char **map_tab, int *c, int x, int y);
int		ft_check_borders(t_map **map_list, int i);

////////////*ft_get_pos.c////////////////
int		ft_get_pos_x(char **map_tab);
int		ft_get_pos_y(char **map_tab);

////////////*ft_init_mlx.c////////////////
int		ft_init_mlx(char **map_tab);
void	ft_put_img_on_map(t_image *img_48x48);
void	ref_ft_put_img_on_map(t_image *img_48x48, int i, int j, char *str);
int		exit_so_long(t_image *mlx_win);
t_image	new_img(int width, int height, t_win mlx_win, char **map);
t_win	new_launch(int width, int height, char *str);

////////////*move_to_right.c////////////////
int		ft_count_collec(char **map_tab);
void	move_to_right(t_image img);
void	ref_move_to_right(t_image img, int x, int y);
void	ref_2_move_to_right(t_image img, int x, int y);

////////////*move_to_left.c////////////////
void	move_to_left(t_image img);
void	ref_move_to_left(t_image img, int x, int y);
void	ref_2_move_to_left(t_image img, int x, int y);

////////////*move_down.c////////////////
void	move_down(t_image img);
void	ref_move_down(t_image img, int x, int y);
void	ref_2_move_down(t_image img, int x, int y);

////////////*move_up.c////////////////
void	move_up(t_image img);
void	ref_move_up(t_image img, int x, int y);
void	ref_2_move_up(t_image img, int x, int y);

////////////*move_counter.c////////////////
void	counter_on_window(t_image img);
void	clear_counter(t_image img, int x, int y, int color);

////////////*move_animation.c////////////////
void	anim_move_up(t_image img, int x, int y);
void	anim_move_right(t_image img, int x, int y);
int		before_anim_static(t_image img);
int		anim_static(t_image img, int x, int y);

#endif
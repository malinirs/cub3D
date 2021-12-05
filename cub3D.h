/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:12:00 by hparis            #+#    #+#             */
/*   Updated: 2021/12/05 16:12:04 by hparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "./libft/libft.h"

# define W_KEY			13
# define A_KEY			0
# define S_KEY			1
# define D_KEY			2
# define RL_KEY			123
# define RR_KEY			124
# define ESC_KEY		53

# define MOVE_SPEED		0.05
# define ROT_SPEED		0.05

# define RES_X			1280
# define RES_Y			720

# define SPRITE_SIZE	64

# define MAP_SIZE		5
# define MAP_W_COLOR	0xFFFFFF
# define MAP_PL_COLOR	0xFF0000
# define MAP_RAY_COLOR	0x990099
# define M_2PI			6.283185307179586

typedef struct s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct s_dist
{
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	int		stepx;
	int		stepy;
	int		x;
	int		y;
}				t_dist;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_wall
{
	t_img	*spr_n;
	t_img	*spr_s;
	t_img	*spr_w;
	t_img	*spr_e;
}				t_wall;

typedef struct s_plan
{
	int		fd;
	char	**map;
	int		len_y;
	int		len_x;
	int		heigh;
	int		width;
	char	*wall_n;
	char	*wall_s;
	char	*wall_w;
	char	*wall_e;
	char	*c_flor;
	char	*c_ceil;
	char	start;
	int		numb_color;
	int		numb_commas;
	int		count;
	char	*space;
}					t_plan;

typedef struct s_plr
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	angle;
}			t_plr;

typedef struct s_keys
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		arrow_l;
	int		arrow_r;
}				t_keys;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	long	floor;
	long	ceiling;
	t_keys	*key;
	t_plr	*plr;
	t_wall	*wall;
	t_plan	*plan;
	t_img	*img;
}			t_game;

/**main*/
int		end_game(t_game *game);
void	puterror(char *line);
int		main_loop(t_game *game);

/**keys*/
int		press_key(int keycode, t_game *game);
int		unpress_key(int keycode, t_game *game);

/**color_back*/
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
void	print_background(t_game *game, int x, int y);
void	init_color(long *color, char *line);

/**travel*/
void	travel(t_game *game, double step_x, double step_y);

/**initial*/
void	initial(t_game *game);

/**init_sprite*/
void	init_sprite(t_game *game);
void	init_dist(t_dist *dist, t_vector ray, t_plr *plr);

/**print_wall*/
void	print_walls(t_game *game, int x);

/** parser.c */
void	parser(int argc, char **argv, t_plan *plan, t_plr *plr);
int		close_program(char *str, t_plan *plan, int code);

/** get_next_line.c */
int		get_next_line(int fd, char **line);

/** open_file.c */
void	check_extension_file(char *temp, t_plan *plan);
void	open_file(char *str_for_read, t_plan *plan);

/** check_symbol_map.c */
void	check_symbol_map(t_plan *plan, t_plr *plr);

/** check_number_rgb.c */
void	check_numb_color(t_plan *plan);

/** pars_sprites_color.c */
void	pars_sprites_color(t_plan *plan, int i);

/** main_parsing.c */
void	main_parsing(t_plan *plan);

/** rendering_map.c */
void	search_width(t_plan *plan);
void	rendering_correct_map(t_plan *plan);
void	remove_empty_lines(t_plan *plan);

/** print_map_bonus.c */
void	print_minimap(t_game *game);

#endif

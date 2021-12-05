/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:04:15 by hparis            #+#    #+#             */
/*   Updated: 2021/12/05 12:04:16 by hparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_dir(char c, t_plr *plr)
{
	if (c == 'N')
	{
		plr->dir_x = -0.66;
		plr->dir_y = 0;
	}
	if (c == 'S')
	{
		plr->dir_x = 0.66;
		plr->dir_y = 0;
	}
	if (c == 'W')
	{
		plr->dir_x = 0;
		plr->dir_y = -0.66;
	}
	if (c == 'E')
	{
		plr->dir_x = 0;
		plr->dir_y = 0.66;
	}
}

static void	init_img_key(t_game *game)
{
	game->img = malloc(sizeof(t_img));
	if (!game->img)
		puterror("can't allocate memory(img)");
	game->img->img = mlx_new_image(game->mlx, RES_X, RES_Y);
	if (!game->img->img)
		puterror("can't create new image");
	game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits, \
							&game->img->line_length, &game->img->endian);
	if (!game->img->addr)
		puterror("can't create image addr");
	game->wall->spr_e = NULL;
	game->wall->spr_s = NULL;
	game->wall->spr_w = NULL;
	game->wall->spr_n = NULL;
	game->key = malloc(sizeof(t_keys));
	if (!game->key)
		puterror("can't allocate memory(key)");
		game->key->w = -1;
		game->key->s = -1;
		game->key->d = -1;
		game->key->a = -1;
		game->key->arrow_l = -1;
		game->key->arrow_r = -1;
}

static void	set_plane(t_plr *plr)
{
	plr->plane_x = -plr->dir_y * tan(85 * M_PI / 360);
	plr->plane_y = plr->dir_x * tan(85 * M_PI / 360);
}

void	initial(t_game *game)
{
	init_color(&game->floor, game->plan->c_flor);
	init_color(&game->ceiling, game->plan->c_ceil);
	set_dir(game->plan->start, game->plr);
	set_plane(game->plr);
	game->wall = malloc(sizeof(t_wall));
	if (!game->wall)
		puterror("can't allocate memory(wall)");
	init_img_key(game);
	init_sprite(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		puterror("can't initialize mlx");
	game->win = mlx_new_window(game->mlx, RES_X, RES_Y, "cub3d");
	if (!game->win)
		puterror("can't create game window");
}

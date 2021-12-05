/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:03:57 by hparis            #+#    #+#             */
/*   Updated: 2021/12/05 12:04:00 by hparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	loading_xmp(t_game *game, t_img *texture, char *file)
{
	int	fl[2];

	if (!texture)
		puterror("can't allocate memory(texture)");
	texture->img = mlx_xpm_file_to_image(game->mlx, file, &fl[0], &fl[1]);
	if (!texture->img)
		puterror(ft_strjoin("can not read xpm file ", file));
	if (fl[0] != SPRITE_SIZE || fl[0] != fl[1])
		puterror(ft_strjoin("incorrect xpm size ", file));
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits, \
									&texture->line_length, &texture->endian);
	texture->bits = texture->bits / 8;
}

void	init_sprite(t_game *game)
{
	game->wall->spr_e = malloc(sizeof(t_img));
	loading_xmp(game, game->wall->spr_e, game->plan->wall_e);
	game->wall->spr_s = malloc(sizeof(t_img));
	loading_xmp(game, game->wall->spr_s, game->plan->wall_s);
	game->wall->spr_n = malloc(sizeof(t_img));
	loading_xmp(game, game->wall->spr_n, game->plan->wall_n);
	game->wall->spr_w = malloc(sizeof(t_img));
	loading_xmp(game, game->wall->spr_w, game->plan->wall_w);
}

void	init_dist(t_dist *dist, t_vector ray, t_plr *plr)
{
	dist->deltadistx = fabs(1 / ray.x);
	dist->deltadisty = fabs(1 / ray.y);
	dist->x = (int)plr->pos_x;
	dist->y = (int)plr->pos_y;
	if (ray.x > 0)
	{
		dist->stepx = 1;
		dist->sidedistx = (ceil(plr->pos_x) - plr->pos_x) * dist->deltadistx;
	}
	else
	{
		dist->stepx = -1;
		dist->sidedistx = (plr->pos_x - floor(plr->pos_x)) * dist->deltadistx;
	}
	if (ray.y > 0)
	{
		dist->stepy = 1;
		dist->sidedisty = (ceil(plr->pos_y) - plr->pos_y) * dist->deltadisty;
	}
	else
	{
		dist->stepy = -1;
		dist->sidedisty = (plr->pos_y - floor(plr->pos_y)) * dist->deltadisty;
	}
}

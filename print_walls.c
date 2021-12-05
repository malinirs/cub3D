/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:04:38 by hparis            #+#    #+#             */
/*   Updated: 2021/12/05 12:04:40 by hparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static unsigned int	*set_color(t_img *img, int x, int y)
{
	return ((unsigned *)(img->addr + y * img->line_length + x * img->bits));
}

static void	put_tex_stripe(t_game *game, int x, t_vector trash, t_img *tex)
{
	int			p_x;
	int			p_y;
	int			start;
	int			finish;
	t_vector	step_pos;

	step_pos.x = (double)SPRITE_SIZE / trash.y;
	start = (RES_Y - (int)trash.y) / 2;
	if (start < 0)
		start = 0;
	finish = RES_Y - start;
	p_x = (int)((double)SPRITE_SIZE * trash.x);
	step_pos.y = (start + ((int)trash.y - RES_Y) * 0.5) * step_pos.x;
	while (start < finish)
	{
		p_y = (int)step_pos.y & (SPRITE_SIZE - 1);
		my_mlx_pixel_put(game, x, start, *set_color(tex, p_x, p_y));
		step_pos.y += step_pos.x;
		start++;
	}
}

static double	find_dist(t_vector ray, t_plr *plr, char **map, char *side)
{
	t_dist	dist;
	int		fl;

	init_dist(&dist, ray, plr);
	while (map[dist.y][dist.x] != '1')
	{
		if (dist.sidedistx < dist.sidedisty)
		{
			dist.sidedistx += dist.deltadistx;
			dist.x += dist.stepx;
			fl = 1;
		}
		else
		{
			dist.sidedisty += dist.deltadisty;
			dist.y += dist.stepy;
			fl = 0;
		}
	}
	if (fl)
		*side = 'H';
	if (fl)
		return ((dist.x - plr->pos_x + (1 - dist.stepx) * 0.5) / ray.x);
	*side = 'V';
	return ((dist.y - plr->pos_y + (1 - dist.stepy) * 0.5) / ray.y);
}

static t_vector	get_tex_data(t_vector ray, t_plr *plr, \
							t_game *game, t_img **tex)
{
	t_vector	trash;
	double		dist;
	char		side;

	dist = find_dist(ray, plr, game->plan->map, &side);
	if (side == 'V')
	{
		trash.x = plr->pos_x + dist * ray.x;
		if (ray.y > 0)
			*tex = game->wall->spr_n;
		else
			*tex = game->wall->spr_s;
	}
	else if (side == 'H')
	{
		trash.x = plr->pos_y + dist * ray.y;
		if (ray.x > 0)
			*tex = game->wall->spr_w;
		else
			*tex = game->wall->spr_e;
	}
	trash.x -= floor(trash.x);
	trash.y = dist;
	return (trash);
}

void	print_walls(t_game *game, int x)
{
	double		camerax;
	t_img		*tex;
	t_vector	ray;
	t_vector	trash;

	while (x < RES_X)
	{
		camerax = (double)x * (2.0 / (double)RES_X) - 1;
		ray.x = game->plr->dir_x + game->plr->plane_x * camerax;
		ray.y = game->plr->dir_y + game->plr->plane_y * camerax;
		trash = get_tex_data(ray, game->plr, game, &tex);
		trash.y = (double)RES_Y / trash.y;
		put_tex_stripe(game, x, trash, tex);
		x++;
	}
}

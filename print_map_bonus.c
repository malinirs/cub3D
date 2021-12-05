/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:47:24 by hparis            #+#    #+#             */
/*   Updated: 2021/12/05 16:47:31 by hparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	ft_angle(t_plr *plr)
{
	if (plr->angle <= 0)
		plr->angle += M_2PI;
	if (plr->angle > M_2PI)
		plr->angle -= M_2PI;
	return (plr->angle);
}

static void	ft_cast_rays(t_game *game, double x, double y)
{
	double	x_s;
	double	y_s;
	double	start;
	double	end;
	double	step;

	start = ft_angle(game->plr);
	end = start + ((double)85 / 180.0) * M_PI;
	step = (((double)85 / 180.0) * M_PI) / 1000;
	while (start < end)
	{
		x_s = x;
		y_s = y;
		while (game->plan->map[(int)(y_s / MAP_SIZE)][(int)(x_s / MAP_SIZE)]
			!= '1')
		{
			x_s += cos(start - ((double)85 / 180.0) * M_PI * 0.5);
			y_s += sin(start - ((double)85 / 180.0) * M_PI * 0.5);
			my_mlx_pixel_put(game, (int)x_s, (int)y_s, MAP_RAY_COLOR);
		}
		start += step;
	}
}

static void	sizepixel_player(t_game *game, int x, int y, int color)
{
	int		x_size;
	int		y_size;
	double	diff;

	diff = (double)MAP_SIZE * 0.25;
	ft_cast_rays(game, x, y);
	y = y + diff;
	x = x + diff;
	y_size = y - diff;
	while (y_size < y && y_size < RES_Y)
	{
		x_size = x - diff;
		while (x_size < x && x_size < RES_X)
		{
			my_mlx_pixel_put(game, x_size, y_size, color);
			x_size++;
		}
		y_size++;
	}
}

static void	sizepixel(t_game *game, int x, int y, int color)
{
	int	x_size;
	int	y_size;

	y_size = y;
	while (y_size < y + MAP_SIZE && y_size < RES_Y)
	{
		x_size = x;
		while (x_size < x + MAP_SIZE && x_size < RES_X)
		{
			my_mlx_pixel_put(game, x_size, y_size, color);
			x_size++;
		}
		y_size++;
	}
}

void	print_minimap(t_game *game)
{
	int	x;
	int	y;	
	int	step_x;
	int	step_y;

	y = -1;
	step_y = 0;
	while (game->plan->map[++y])
	{
		step_x = 0;
		x = -1;
		while (game->plan->map[y][++x])
		{
			if (game->plan->map[y][x] == '1')
				sizepixel(game, step_x, step_y, MAP_W_COLOR);
			step_x += MAP_SIZE;
		}
		step_y += MAP_SIZE;
	}
	sizepixel_player(game, (int)(game->plr->pos_x * MAP_SIZE), \
	(int)(game->plr->pos_y * MAP_SIZE), MAP_PL_COLOR);
}

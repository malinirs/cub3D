/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:03:08 by hparis            #+#    #+#             */
/*   Updated: 2021/12/05 12:03:10 by hparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_color(long *color, char *line)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;
	int		i;

	rgb = NULL;
	rgb = ft_split(line, ',');
	if (!rgb)
		puterror("can't allocate memory(color)");
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	i = -1;
	while (rgb[++i])
		free(rgb[i]);
	free(rgb);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		puterror("incorrect color format");
	*color = (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->img->addr + (y * game->img->line_length + x
			* (game->img->bits / 8));
	*(unsigned int *)dst = color;
}

void	print_background(t_game *game, int x, int y)
{
	y = 0;
	while (y < RES_Y)
	{
		x = 0;
		while (x < RES_X)
		{
			if (y > (RES_Y / 2))
				my_mlx_pixel_put(game, x, y, game->floor);
			else
				my_mlx_pixel_put(game, x, y, game->ceiling);
			x++;
		}
		y++;
	}
}

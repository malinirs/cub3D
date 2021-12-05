/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   travel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:05:00 by hparis            #+#    #+#             */
/*   Updated: 2021/12/05 12:05:02 by hparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_step(char **mapi, t_game *game, double step_x, \
					double step_y)
{
	step_x = game->plr->pos_x + step_x;
	step_y = game->plr->pos_y + step_y;
	if (mapi[(int)step_y][(int)step_x] == '0')
		return (1);
	return (0);
}

static void	trav_step(t_game *game, double step_x, double step_y)
{
	if (check_step(game->plan->map, game, step_x, 0))
		game->plr->pos_x += step_x;
	if (check_step(game->plan->map, game, 0, step_y))
		game->plr->pos_y += step_y;
}

static void	trav_arrow(t_plr *plr, double speed)
{
	double	olddirx;
	double	oldplanex;

	olddirx = plr->dir_x;
	plr->dir_x = plr->dir_x * cos(speed) - plr->dir_y * sin(speed);
	plr->dir_y = olddirx * sin(speed) + plr->dir_y * cos(speed);
	oldplanex = plr->plane_x;
	plr->plane_x = plr->plane_x * cos(speed) - plr->plane_y * sin(speed);
	plr->plane_y = oldplanex * sin(speed) + plr->plane_y * cos(speed);
}

void	travel(t_game *game, double step_x, double step_y)
{
	step_x = game->plr->dir_x * MOVE_SPEED;
	step_y = game->plr->dir_y * MOVE_SPEED;
	if (game->key->w == 1)
		trav_step(game, step_x, step_y);
	if (game->key->s == 1)
		trav_step(game, -step_x, -step_y);
	if (game->key->d == 1)
		trav_step(game, -step_y, step_x);
	if (game->key->a == 1)
		trav_step(game, step_y, -step_x);
	if (game->key->arrow_l == 1)
		trav_arrow(game->plr, -ROT_SPEED);
	if (game->key->arrow_r == 1)
		trav_arrow(game->plr, ROT_SPEED);
}

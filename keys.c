/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:03:30 by hparis            #+#    #+#             */
/*   Updated: 2021/12/05 12:03:32 by hparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	press_key(int keycode, t_game *game)
{
	if (keycode == W_KEY)
		game->key->w = 1;
	else if (keycode == S_KEY)
		game->key->s = 1;
	else if (keycode == D_KEY)
		game->key->d = 1;
	else if (keycode == A_KEY)
		game->key->a = 1;
	else if (keycode == RL_KEY)
		game->key->arrow_l = 1;
	else if (keycode == RR_KEY)
		game->key->arrow_r = 1;
	if (keycode == ESC_KEY)
		end_game(game);
	return (0);
}

int	unpress_key(int keycode, t_game *game)
{
	if (keycode == W_KEY)
		game->key->w = 0;
	else if (keycode == S_KEY)
		game->key->s = 0;
	else if (keycode == D_KEY)
		game->key->d = 0;
	else if (keycode == A_KEY)
		game->key->a = 0;
	else if (keycode == RL_KEY)
		game->key->arrow_l = 0;
	else if (keycode == RR_KEY)
		game->key->arrow_r = 0;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_symbol_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:54:29 by awoods            #+#    #+#             */
/*   Updated: 2021/12/04 22:54:32 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	number_players(t_plan *plan, t_plr *plr)
{
	int	i;
	int	j;
	int	player;

	i = -1;
	player = 0;
	while (++i < plan->len_y)
	{
		j = -1;
		while (++j < plan->len_x)
		{
			if (plan->map[i][j] == 'N' || plan->map[i][j] == 'S' || \
			plan->map[i][j] == 'W' || plan->map[i][j] == 'E')
			{
				plan->start = plan->map[i][j];
				plr->pos_x = j;
				plr->pos_y = i;
				plan->map[i][j] = '0';
				player++;
			}
		}
	}
	return (player);
}

static void	check_symbol_sprites(char *str, t_plan *plan)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '.' && str[i] != '/')
			close_program("Error: incorrect sprite address\n", plan, 1);
	}
}

void	check_symbol_map(t_plan *plan, t_plr *plr)
{
	int	player;

	pars_sprites_color(plan, -1);
	check_numb_color(plan);
	check_symbol_sprites(plan->wall_n, plan);
	check_symbol_sprites(plan->wall_s, plan);
	check_symbol_sprites(plan->wall_w, plan);
	check_symbol_sprites(plan->wall_e, plan);
	search_width(plan);
	rendering_correct_map(plan);
	remove_empty_lines(plan);
	main_parsing(plan);
	player = number_players(plan, plr);
	if (plan->len_x < 3 || plan->len_y < 3)
		close_program("Error: invalid map\n", plan, 1);
	if (player != 1)
		close_program("Error: wrong number of players\n", plan, 1);
}

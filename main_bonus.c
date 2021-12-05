/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:54:35 by hparis            #+#    #+#             */
/*   Updated: 2021/12/05 17:17:58 by hparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	puterror(char *line)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(line, 1);
	exit(1);
}

int	end_game(t_game *game)
{
	free(game->plan->wall_n);
	free(game->plan->wall_s);
	free(game->plan->wall_w);
	free(game->plan->wall_e);
	free(game->plan);
	free(game->plr);
	free(game->img);
	free(game->key);
	free(game->wall->spr_n);
	free(game->wall->spr_s);
	free(game->wall->spr_w);
	free(game->wall->spr_e);
	free(game->wall);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	main_loop(t_game *game)
{
	travel(game, 0, 0);
	print_background(game, 0, 0);
	print_walls(game, 0);
	print_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.plan = malloc(sizeof(t_plan));
	if (!game.plan)
		puterror("can't allocate memory(plan)");
	game.plr = malloc(sizeof(t_plr));
	if (!game.plr)
		puterror("can't allocate memory(plr)");
	game.plr->pos_x = 0;
	game.plr->pos_y = 0;
	game.plr->dir_x = 0;
	game.plr->dir_y = 0;
	game.plr->angle = 0;
	parser(argc, argv, game.plan, game.plr);
	initial(&game);
	mlx_hook(game.win, 17, 0L, end_game, &game);
	mlx_hook(game.win, 2, 0, press_key, &game);
	mlx_hook(game.win, 3, 0, unpress_key, &game);
	mlx_loop_hook(game.mlx, main_loop, &game);
	mlx_loop(game.mlx);
}

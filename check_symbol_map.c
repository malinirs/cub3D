#include "cub3D.h"

void	check_symbol_sprites(char *str, t_plan *plan)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '.' && str[i] != '/')
			error_and_close_program("Error: incorrect sprite address\n", plan, 1);
	}
}

void	check_symbol_map(t_plan *plan)
{
	pars_sprites_wall(plan);
	check_numb_color(plan);
	check_symbol_sprites(plan->wall_n, plan);
	check_symbol_sprites(plan->wall_s, plan);
	check_symbol_sprites(plan->wall_w, plan);
	check_symbol_sprites(plan->wall_e, plan);
}
#include "cub3D.h"

int	error_and_close_program(char *str, t_plan *plan, int code)
{
	int	i;

	i = -1;
	if (code == 1)
		write(2, str, ft_strlen(str));
	if (plan->map)
	{
		while (++i <= plan->len_y)
			free(plan->map[i]);
		free(plan->map);
	}
	if (plan->wall_e)
		free(plan->wall_e);
	if (plan->wall_w)
		free(plan->wall_w);
	if (plan->wall_s)
		free(plan->wall_s);
	if (plan->wall_n)
		free(plan->wall_n);
	if (plan->c_ceil)
		free(plan->c_ceil);
	if (plan->c_flor)
		free(plan->c_flor);
	exit(code);
}

void	init(t_plan *plan)
{
	plan->map = NULL;
	plan->wall_n = NULL;
	plan->wall_s = NULL;
	plan->wall_w = NULL;
	plan->wall_e = NULL;
	plan->c_flor = NULL;
	plan->c_ceil = NULL;
}

void	check_argc_and_open_map(int argc, char **argv, t_plan *plan)
{
	init(plan);
	if (argc == 1)
		error_and_close_program("Error: file is missing\n", plan, 1);
	else if (argc == 2)
	{
		check_extension_file(argv[1], plan);
		open_file(argv[1], plan);
		check_symbol_map(plan);
	}
	else if (argc > 2)
		error_and_close_program("Error: many arguments\n", plan, 1);
}

void	parser(int argc, char **argv, t_plan *plan)
{
	check_argc_and_open_map(argc, argv, plan);
}



int	main(int argc, char **argv)
{
	t_plan	plan;

	parser(argc, argv, &plan);
	return (0);
}

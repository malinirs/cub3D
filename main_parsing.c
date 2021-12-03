#include "cub3D.h"

static void	checking_outer_walls(t_plan *plan)
{
	int	i;

	i = -1;
	while (++i < plan->len_x)
	{
		if (!(plan->map[0][i] == '1' || plan->map[0][i] == ' '))
			close_program("Error: invalid map\n", plan,1);
		if (!(plan->map[plan->len_y - 1][i] == '1' || \
		plan->map[plan->len_y - 1][i] == ' '))
			close_program("Error: invalid map\n", plan,1);
	}
	i = -1;
	while (++i < plan->len_y)
	{
		if (!(plan->map[i][0] == '1' || plan->map[i][0] == ' '))
			close_program("Error: invalid map\n", plan,1);
		if (!(plan->map[i][plan->len_x - 1] == '1' || \
		plan->map[i][plan->len_x - 1] == ' '))
			close_program("Error: invalid map\n", plan,1);
	}
}

int	all_symbol(t_plan *plan, int i, int j)
{
	if (!(plan->map[i][j] == '0' || plan->map[i][j] == ' ' || \
	plan->map[i][j] == '1' || plan->map[i][j] == 'N' || \
	plan->map[i][j] == 'S' || plan->map[i][j] == 'W' || \
	plan->map[i][j] == 'E'))
		return (1);
	return (0);
}

void	symbol(t_plan *plan, int i, int j)
{
	if (plan->map[i][j] == ' ' || plan->map[i][j] == '\0')
		close_program("Error: invalid map\n", plan,1);
}

static void	checking_zero(t_plan *plan, int i, int j)
{
	symbol(plan, i - 1, j - 1);
	symbol(plan, i, j -1);
	symbol(plan, i + 1, j +1);
	symbol(plan, i - 1, j);
	symbol(plan, i + 1, j);
	symbol(plan, i - 1, j + 1);
	symbol(plan, i, j + 1);
	symbol(plan, i + 1, j + 1);
}

void	main_parsing(t_plan *plan)
{
	int	i;
	int	j;

	i = 0;
	checking_outer_walls(plan);
	while (i < plan->len_y)
	{
		j = -1;
		while (++j < plan->len_x)
		{
			if (all_symbol(plan, i, j))
				close_program("Error: invalid map\n", plan,1);
			if (plan->map[i][j] == '0' || plan->map[i][j] == 'N' || \
			plan->map[i][j] == 'S' || plan->map[i][j] == 'W' || \
			plan->map[i][j] == 'E')
				checking_zero(plan, i, j);
		}
		i++;
	}
}
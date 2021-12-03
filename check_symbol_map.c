#include "cub3D.h"

static void	search_width(t_plan *plan)
{
	int	i;

	i = plan->count;
	plan->len_x = 0;
	while (plan->map[i])
	{
		if ((int)ft_strlen(plan->map[i]) > plan->len_x)
			plan->len_x = (int)ft_strlen(plan->map[i]);
		i++;
	}
	if (plan->len_x < 3 && plan->len_y < 3)
		close_program("Error: invalid map\n", plan, 1);
}

static void	replace_map(t_plan *plan)
{
	char	**temp;
	int		count;
	int		i;

	i = -1;
	count = plan->len_y;
	plan->len_y = plan->len_y - plan->count + 1;
	temp = malloc(sizeof(char *) * (plan->len_y + 1));
	while (++i < plan->len_y)
		temp[i] = plan->map[plan->count++];
	i = -1;
	while (++i <= count - plan->len_y)
		free(plan->map[i]);
	free(plan->map);
	plan->map = temp;
}

static char	*pad_spaces(int i, t_plan *plan)
{
	int		count;

	count = -1;
	plan->space = malloc(sizeof(char) * (i + 1));
	while (++count < i)
		plan->space[count] = ' ';
	plan->space[i] = '\0';
	return (plan->space);
}

static void	rendering_correct_map(t_plan *plan)
{
	int		i;
	char	*temp;

	i = plan->count;
	while (plan->map[i])
	{
		if (plan->len_x > ft_strlen(plan->map[i]))
		{
			temp = ft_strjoin(plan->map[i], pad_spaces(plan->len_x -
			ft_strlen(plan->map[i]), plan));
			if (!temp)
				close_program("Memory allocation error\n", plan, 1);
			free(plan->space);
			free(plan->map[i]);
			plan->map[i] = temp;
		}
		i++;
	}
	replace_map(plan);

//	i = -1;
//	while (plan->map[++i])
//		printf("%s|\n", plan->map[i]);

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

void	number_players(t_plan *plan, t_plr *plr)
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
				plr->PosX = j;
				plr->PosY = i;
				plan->map[i][j] = '0';
				player++;
			}
		}
	}
	if (player != 1)
		close_program("Error: wrong number of players\n", plan, 1);
}

void	check_symbol_map(t_plan *plan, t_plr *plr)
{
	pars_sprites_wall(plan, -1);
	check_numb_color(plan);
	check_symbol_sprites(plan->wall_n, plan);
	check_symbol_sprites(plan->wall_s, plan);
	check_symbol_sprites(plan->wall_w, plan);
	check_symbol_sprites(plan->wall_e, plan);
	search_width(plan);
	rendering_correct_map(plan);
	main_parsing(plan);
	number_players(plan, plr);


	int i = -1;
	while (plan->map[++i])
		printf("%s|\n", plan->map[i]);
}
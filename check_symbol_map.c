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

static char	*pad_spaces(int i)
{
	char	*str;
	int		count;

	count = -1;
	str = malloc(sizeof(char) * (i + 1));
	while (++count < i)
		str[count] = ' ';
	str[i] = '\0';
	return (str);
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
			ft_strlen(plan->map[i])));
			if (!temp)
				close_program("Memory allocation error\n", plan, 1);
			free(plan->map[i]);
			plan->map[i] = temp;
		}
		i++;
	}
//	replace_map(plan);

	i = -1;
	while (plan->map[++i])
		printf("%s|\n", plan->map[i]);

}

//t_bool	check_around(int **map, t_plan map_size, int ln, int col)
//{
//	if ((map[ln][col] == 0 && ln > 0 && ln < map_size.y - 1
//		 && col > 0 && col < map_size.x - 1
//		 && ((map[ln - 1][col] == 0 || map[ln - 1][col] == 1)
//			 && (map[ln + 1][col] == 0 || map[ln + 1][col] == 1)
//			 && (map[ln][col - 1] == 0 || map[ln][col - 1] == 1)
//			 && (map[ln][col + 1] == 0 || map[ln][col + 1] == 1)
//			 && (map[ln - 1][col - 1] == 0 || map[ln - 1][col - 1] == 1)
//			 && (map[ln + 1][col + 1] == 0 || map[ln + 1][col + 1] == 1)
//			 && (map[ln + 1][col - 1] == 0 || map[ln + 1][col - 1] == 1)
//			 && (map[ln - 1][col + 1] == 0 || map[ln - 1][col + 1] == 1)))
//		|| map[ln][col] == 1 || map[ln][col] == -1)
//		return (true);
//	return (false);
//}
//
//void	parsing_map(t_plan *plan)
//{
//	int	i;
//	int	j;
//
//	i = 0;
//	if (map_size.y < 3 || map_size.x < 3)
//		close_program("Error: invalid map\n", plan,1);
//	while (i < map_size.y)
//	{
//		j = -1;
//		while (++j < map_size.x)
//		{
//			if (!check_around(map, map_size, i, j)
//				|| ((i == 0 || i == map_size.y - 1) && map[i][j] == 0))
//				close_program("Error: invalid map\n", plan,1);
//		}
//		i++;
//	}
//}


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

void	check_symbol_map(t_plan *plan)
{
	pars_sprites_wall(plan, -1);
	check_numb_color(plan);
	check_symbol_sprites(plan->wall_n, plan);
	check_symbol_sprites(plan->wall_s, plan);
	check_symbol_sprites(plan->wall_w, plan);
	check_symbol_sprites(plan->wall_e, plan);
	search_width(plan);
//	rendering_correct_map(plan);
}
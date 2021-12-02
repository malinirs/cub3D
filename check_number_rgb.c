#include "cub3D.h"

static void	check_number_rgb_last(char *str, t_plan *plan, int j)
{
	int		numb;
	char	*temp;

	temp = ft_substr(str, j, ft_strlen(str) - j);
	if (ft_strlen(temp) > 3)
	{
		free(temp);
		close_program("Error: incorrect color number\n", plan, 1);
	}
	numb = ft_atoi(temp);
	free(temp);
	plan->numb_color++;
	if (numb < 0 || numb > 255 || plan->numb_color != 3 || plan->numb_commas
														   != 2)
		close_program("Error: incorrect color number\n", plan, 1);
}

static void	check_number_rgb(char *str, t_plan *plan, int i, int j)
{
	int		numb;
	char	*temp;

	while (str[++i] != '\0')
	{
		if (str[i] == ',' || str[i] == '\0')
		{
			temp = ft_substr(str, j, i - j);
			if (ft_strlen(temp) > 3)
			{
				free(temp);
				close_program("Error: incorrect color number\n", plan, 1);
			}
			j = i + 1;
			numb = ft_atoi(temp);
			free(temp);
			if (numb < 0 || numb > 255)
				close_program("Error: incorrect color number\n", plan, 1);
			plan->numb_color++;
			plan->numb_commas++;
		}
	}
	check_number_rgb_last(str,plan, j);
}
void	check_numb_color(t_plan *plan)
{
	int	i;

	i = -1;
	while (plan->c_ceil[++i])
		if (!ft_isdigit(plan->c_ceil[i]) && plan->c_ceil[i]	!= 44)
			close_program("Error: incorrect color number\n", plan, 1);
	i = -1;
	while (plan->c_flor[++i])
		if (!ft_isdigit(plan->c_flor[i]) && plan->c_flor[i]	!= 44)
			close_program("Error: incorrect color number\n", plan, 1);
	plan->numb_color = 0;
	plan->numb_commas = 0;
	check_number_rgb(plan->c_flor, plan, -1, 0);
	plan->numb_color = 0;
	plan->numb_commas = 0;
	check_number_rgb(plan->c_ceil, plan, -1, 0);
}

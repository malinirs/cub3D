/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_sprites_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:02:20 by awoods            #+#    #+#             */
/*   Updated: 2021/12/04 23:02:25 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_space(char *str, t_plan *plan)
{
	int	i;
	int	space;

	space = 2;
	if (!ft_strncmp(str, "F", 1) || !ft_strncmp(str, "C", 1))
		space = 1;
	i = space;
	while (str[space] == ' ')
		space++;
	if (space - i == 0)
		close_program("Error: incorrect sprite address\n", plan, 1);
	return (space);
}

static void	write_value(char **str, char *value, t_plan *plan, int i)
{
	int	count;
	int	space;

	space = check_space(plan->map[i], plan);
	count = space;
	if (!(*str))
	{
		while (value[count] != ' ' && value[count])
			count++;
		while (value[count] == ' ' && value[count])
		{
			count++;
			space++;
		}
		if (value[count] != '\0')
			close_program("Error: incorrect sprite or color\n", plan, 1);
		*str = ft_substr(&value[space], 0, count - space);
		if (!(*str))
			close_program("Memory allocation error\n", plan, 1);
	}
	else
		close_program("Error: incorrect sprite or color\n", plan, 1);
}

static void	check_value(t_plan *plan, int i)
{
	if (!plan->wall_n || !plan->wall_s || !plan->wall_w || !plan->wall_e || \
		!plan->c_flor || !plan->c_ceil)
		close_program("Error: invalid map\n", plan, 1);
	plan->count = i;
}

static int	delete_spase(char **str)
{
	char	*temp;
	int		i;

	i = 0;
	while ((*str)[i] == ' ')
		i++;
	if ((*str)[i] == 'W' || (*str)[i] == 'E' || \
	(*str)[i] == 'N' || (*str)[i] == 'S' || \
	(*str)[i] == 'F' || (*str)[i] == 'C')
	{
		temp = ft_substr(*str, i, ft_strlen(*str) - i);
		free(*str);
		*str = temp;
		return (0);
	}
	return (1);
}

void	pars_sprites_color(t_plan *plan, int i)
{
	while (plan->map[++i])
	{
		if (!ft_strncmp(plan->map[i], " ", 1))
			if (delete_spase(&plan->map[i]))
				break ;
		if (!ft_strncmp(plan->map[i], "\0", 1))
			;
		else if (!ft_strncmp(plan->map[i], "WE", 2))
			write_value(&plan->wall_w, plan->map[i], plan, i);
		else if (!ft_strncmp(plan->map[i], "EA", 2))
			write_value(&plan->wall_e, plan->map[i], plan, i);
		else if (!ft_strncmp(plan->map[i], "NO", 2))
			write_value(&plan->wall_n, plan->map[i], plan, i);
		else if (!ft_strncmp(plan->map[i], "SO", 2))
			write_value(&plan->wall_s, plan->map[i], plan, i);
		else if (!ft_strncmp(plan->map[i], "F", 1))
			write_value(&plan->c_flor, plan->map[i], plan, i);
		else if (!ft_strncmp(plan->map[i], "C", 1))
			write_value(&plan->c_ceil, plan->map[i], plan, i);
		else
			break ;
	}
	check_value(plan, i);
}

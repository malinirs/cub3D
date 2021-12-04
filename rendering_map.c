/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:04:44 by awoods            #+#    #+#             */
/*   Updated: 2021/12/04 23:04:46 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	search_width(t_plan *plan)
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

void	rendering_correct_map(t_plan *plan)
{
	int		i;
	char	*temp;

	i = plan->count;
	while (plan->map[i])
	{
		if (plan->len_x > (int)ft_strlen(plan->map[i]))
		{
			temp = ft_strjoin(plan->map[i], \
			pad_spaces(plan->len_x - ft_strlen(plan->map[i]), plan));
			if (!temp)
				close_program("Memory allocation error\n", plan, 1);
			free(plan->space);
			free(plan->map[i]);
			plan->map[i] = temp;
		}
		i++;
	}
	replace_map(plan);
}

void	remove_empty_lines(t_plan *plan)
{
	int	i;

	i = plan->len_y;
	while (plan->map[--i])
	{
		if (!ft_strncmp(plan->map[i], pad_spaces(plan->len_x, plan), \
					plan->len_x))
		{
			free(plan->map[i]);
			free(plan->space);
			plan->map[i] = NULL;
			plan->len_y--;
		}
		else
		{
			free(plan->space);
			break ;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:01:25 by awoods            #+#    #+#             */
/*   Updated: 2021/12/04 23:01:28 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_extension_file(char *temp, t_plan *plan)
{
	char	*str;

	str = temp;
	while (str && *str != '\0')
	{
		while (*str != '.' && *str != '\0')
			str++;
		if (ft_strncmp(str, ".cub", 5))
			close_program("Error: invalid map\n", plan, 1);
		break ;
	}
}

static int	check_numb_str(char *str_for_read, t_plan *plan)
{
	int		numb_str;
	int		fd;
	char	c;
	int		byte_was_read;

	numb_str = 0;
	fd = open (str_for_read, O_RDONLY);
	if (fd < 0)
		close_program("File open error!\n", plan, 1);
	byte_was_read = 1;
	while (byte_was_read)
	{
		byte_was_read = read(fd, &c, 1);
		if (byte_was_read == -1)
			close_program("File read error!\n", plan, 1);
		if (c == '\n')
			numb_str++;
	}
	close(fd);
	return (numb_str + 2);
}
/** numb_str + 2, т.к. нужно отдельно печатать ГНЛом последнюю строку + NULL*/

void	open_file(char *str_for_read, t_plan *plan)
{
	char	*line;

	line = NULL;
	plan->len_y = 0;
	plan->fd = open(str_for_read, O_DIRECTORY);
	if (plan->fd != -1)
		close_program("File open error!\n", plan, 1);
	plan->fd = open(str_for_read, O_RDONLY);
	if (plan->fd == -1)
		close_program("File open error!\n", plan, 1);
	plan->map = malloc(sizeof(char *) * (check_numb_str(str_for_read, plan)));
	while (get_next_line(plan->fd, &line))
	{
		plan->map[plan->len_y] = line;
		if (!plan->map[plan->len_y])
			close_program("File read error!\n", plan, 1);
		plan->len_y++;
	}
	plan->map[plan->len_y] = line;
	plan->map[plan->len_y + 1] = NULL;
	close(plan->fd);
}

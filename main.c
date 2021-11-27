#include "cub3D.h"

int	write_error_and_close_program(char *str, t_plan *plan)
{
	int	i;

	i = -1;
	write(2, str, ft_strlen(str));
	if (plan->map)
	{
		while (++i <= plan->len_y)
			free(plan->map[i]);
		free(plan->map);
	}
	exit(1);
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
		write_error_and_close_program("File open error!\n", plan);
	byte_was_read = 1;
	while (byte_was_read)
	{
		byte_was_read = read(fd, &c, 1);
		if (byte_was_read == -1)
			write_error_and_close_program("File read error!\n", plan);
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
		write_error_and_close_program("File open error!\n", plan);
	plan->fd = open(str_for_read, O_RDONLY);
	if (plan->fd == -1)
		write_error_and_close_program("File open error!\n", plan);
	plan->map = malloc(sizeof(char *) * (check_numb_str(str_for_read, plan)));
	while (get_next_line(plan->fd, &line))
	{
		plan->map[plan->len_y] = line;
		if (!plan->map[plan->len_y])
			write_error_and_close_program("File read error!\n", plan);
		plan->len_y++;
	}
	plan->map[plan->len_y] = line;
	plan->map[plan->len_y + 1] = NULL;
	close(plan->fd);


	int i = -1;
	while (plan->map[++i])
		printf("%s\n", plan->map[i]);
}

int	ft_strncm(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i != n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

void	check_extension_file(char *temp, t_plan *plan)
{
	char	*str;

	str = temp;
	while (str && *str != '\0')
	{
		while (*str != '.' && *str != '\0')
			str++;
		if (ft_strncm(str, ".cub", 5))
			write_error_and_close_program("Error: invalid map\n", plan);
		break ;
	}
}

void	check_argc_and_open_map(int argc, char **argv, t_plan *plan)
{
	plan->map = NULL;
	if (argc == 1)
		write_error_and_close_program("Error: file is missing\n", plan);
	else if (argc == 2)
	{
		check_extension_file(argv[1], plan);
		open_file(argv[1], plan);
//		check_symbol_map(info, 0, 0);
	}
	else if (argc > 2)
		write_error_and_close_program("Error: many arguments\n", plan);
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

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "Libft/libft.h"



typedef struct	s_plan
{
	int		fd;
	char	**map;
	int		len_y;
	int		len_x;

	int		heigh;
	int		width;

	char	*wall_n;/**путь к спрайту стены ./sprites/wall.xpm*/
	char	*wall_s;/**путь к спрайту стены ./sprites/wall.xpm*/
	char	*wall_w;/**путь к спрайту стены ./sprites/wall.xpm*/
	char	*wall_e;/**путь к спрайту стены ./sprites/wall.xpm*/
	char	*c_flor;/**строка с цветом пола */
	char	*c_ceil;/**строка с цветом потолока */

	int		numb_color; /** количество цветов */
	int		numb_commas; /** количество запятых */
	int		count; /** счетчик по y */
}				t_plan;




/** main.c */
int		close_program(char *str, t_plan *plan, int code);

/** get_next_line.c */
int		get_next_line(int fd, char **line);

/** open_file.c */
void	check_extension_file(char *temp, t_plan *plan);
void	open_file(char *str_for_read, t_plan *plan);

/** check_symbol_map.c */
void	check_symbol_map(t_plan *plan);

/** check_number_rgb.c */
void	check_numb_color(t_plan *plan);

/** pars_sprites_wall.c */
void	pars_sprites_wall(t_plan *plan, int i);

#endif
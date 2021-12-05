NAME	=  cub3D
NAME_BON	= cub3D_bonus

SRC		=  cub3D.c travel.c keys.c color_back.c print_walls.c parser.c \
			open_file.c get_next_line.c check_symbol_map.c check_number_rgb.c \
			initial.c init_sprite.c main_parsing.c \
			pars_sprites_color.c rendering_map.c \

SRC_BON	= main_bonus.c travel.c keys.c color_back.c print_walls.c parser.c \
              open_file.c get_next_line.c check_symbol_map.c check_number_rgb.c \
              initial.c init_sprite.c main_parsing.c \
              pars_sprites_color.c rendering_map.c \
              print_map_bonus.c

OBJ		=  $(SRC:.c=.o)
OBJ_BON	=  $(SRC_BON:.c=.o)

HEADER	= ./cub3D.h

FLAGS	=  -Werror -Wextra -Wall
MLX_LIBS	= -lmlx -lm -L ./minilibx -framework OpenGL -framework AppKit
LIB		= ./Libft/libft.a


all :		$(NAME)

minilibx:
			${MAKE} -C ./minilibx 2> /dev/null

%.o: %.c	$(HEADER)
			gcc $(FLAGS) -c $< -o ${<:.c=.o}

libft:
			${MAKE} -C ./libft/

$(NAME):	$(OBJ) $(HEADER)
			$(MAKE) -C Libft
			${MAKE} -C ./minilibx 2> /dev/null
			gcc $(SRC) -o $(NAME) ${LIB} $(MLX_LIBS) -I

bonus:		$(OBJ) $(HEADER)
			$(MAKE) -C Libft
			${MAKE} -C ./minilibx 2> /dev/null
			gcc $(SRC_BON) -o $(NAME_BON) ${LIB} $(MLX_LIBS) -I

clean:
			rm -rf *.o
			@make -C $(dir $(LIB)) clean

fclean:		clean
			@make -C $(dir $(LIB)) fclean
			rm -f $(NAME)
			rm -f $(NAME_BON)

re:			fclean all

.PHONY: all clean fclean re
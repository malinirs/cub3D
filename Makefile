NAME	=	cub3D

SRC		=	main.c \
			get_next_line.c \
			open_file.c \
			check_symbol_map.c \
			check_number_rgb.c \
			pars_sprites_wall.c \
			main_parsing.c \



OBJ		=	$(SRC:.c=.o)

HEADER	=	./cub3D.h ./Libft/libft.h

FLAGS	=	-Werror -Wextra -Wall
#LIBS	=	-lmlx -framework OpenGL -framework AppKit
LIB		=	./Libft/libft.a


all		:	$(NAME)

%.o		: %.c	$(HEADER)
		gcc $(FLAGS) -c $< -o $@

$(NAME)	:	$(OBJ) $(HEADER)
		 $(MAKE) -C Libft
#		 $(MAKE) -C minilibx
		 gcc $(SRC) -o $(NAME) $(INCLUDE)  $(OBJS) $(LIB)

clean	:
		rm -rf *.o
		@make -C $(dir $(LIB)) clean

fclean	:	clean
			@make -C $(dir $(LIB)) fclean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
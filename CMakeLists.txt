cmake_minimum_required(VERSION 3.20)
project(cub3d C)

set(CMAKE_C_STANDARD 99)

link_directories(Libft)
add_executable(cub3d main.c get_next_line.c open_file.c check_symbol_map.c check_number_rgb.c
        pars_sprites_color.c main_parsing.c parser.c rendering_map.c)
target_link_libraries(cub3d libft.a)

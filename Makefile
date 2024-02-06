NAME	= cub3D

HEADER	= includes/cub3d.h

MAIN		= main start_game

MOVEMENT	= keys move

RAY_CASTING	= ray_casting ray

RENDERING	= draw line

MAP			= val_main val_texture val_color val_map val_map2 gnl utils utils2 errors player

MINI_MAP = mini_map

SRCS	= $(addsuffix .c, $(addprefix srcs/, $(MAIN))) \
		  $(addsuffix .c, $(addprefix srcs/movement/, $(MOVEMENT))) \
		  $(addsuffix .c, $(addprefix srcs/ray_casting/, $(RAY_CASTING))) \
		  $(addsuffix .c, $(addprefix srcs/rendering/, $(RENDERING))) \
		  $(addsuffix .c, $(addprefix srcs/map/, $(MAP)))

OBJ		= $(SRCS:.c=.o)

MLX		= -Lmlx_linux -lmlx_Linux -L./mlx -Imlx_linux -lXext -lX11 -lm -lz  -g

CC		= cc

FLAGS	=  -Imlx -g -I includes/ -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
	$(CC) $(OBJ) -o $(NAME) $(MLX)

%.o : %.c	$(HEADER) 
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) 

fclean: clean
	@rm -f $(NAME) 

re: fclean all

test: re
	@make clean
	@clear


.PHONY : all clean fclean re 


#include "../includes/cub3d.h"

static void	init_params(t_params *all)
{
	ft_memset(all, 0, sizeof(*all));
	all->player = (t_player *)malloc(sizeof(t_player));
	if (!all->player)
		ft_exit(all);
	all->player->pos_x = -1;
	all->count_par = 0;
	all->move.up = 0;
	all->move.down = 0;
	all->move.left = 0;
	all->move.right = 0;
	all->move.rot_left = 0;
	all->move.rot_right = 0;
	all->mlx = mlx_init();
	all->mlx_win = mlx_new_window(all->mlx, WINDOW_W, WINDOW_H, "cub3d");
}

int	main(int argc, char **argv)
{
	t_params	all;

	if (argc != 2)
	{
		write(2, "Wrong number of arguments!\n", 27);
		return (1);
	}
	init_params(&all);
	valid_main(argv[1], &all);
	texture_xpm(&all);
	start_game(&all);
	return (0);
}

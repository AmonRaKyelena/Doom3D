

#include "../includes/cub3d.h"

int	ft_exit(t_params *params)
{
	my_free(params);
	exit(0);
}

void	start_game(t_params *params)
{
	mlx_loop_hook(params->mlx, &main_loop, params);
	mlx_hook(params->mlx_win, 2, 1L << 0, &ft_key_down, params);
	mlx_hook(params->mlx_win, 3, 2L << 0, &ft_key_up, params);
	mlx_hook(params->mlx_win, 17, 0L, ft_exit, params);
	mlx_loop(params->mlx);
}

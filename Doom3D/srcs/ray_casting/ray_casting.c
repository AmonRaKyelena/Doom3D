

#include "../../includes/cub3d.h"

void	ray_casting(t_params *params)
{
	int	i;

	i = 0;
	while (i < WINDOW_W)
	{
		ft_line(params, i, ray(params, i, 0, 0));
		i++;
	}
}

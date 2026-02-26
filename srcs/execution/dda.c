/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvync <dlytvync@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:58:18 by dlytvync          #+#    #+#             */
/*   Updated: 2026/02/26 12:08:23 by dlytvync         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	calc_delta(double dir)
{
	if (dir == 0.0)
		return (1e30);
	return (fabs(1.0 / dir));
}

void	init_dda_axis_x(t_game *game, t_dda *dda, double player, int map)
{
	if (game->ray.dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_x = (player - map) * dda->delta_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_x = (map + 1.0 - player) * dda->delta_x;
	}
}

void	init_dda_axis_y(t_game *game, t_dda *dda, double player, int map)
{
	if (game->ray.dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_y = (player - map) * dda->delta_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_y = (map + 1.0 - player) * dda->delta_y;
	}
}

void	init_dda(t_game *game, double angle, t_dda *dda)
{
	double	player_x;
	double	player_y;
	int		map_x;
	int		map_y;

	player_x = game->player.pos_x;
	player_y = game->player.pos_y;
	map_x = (int)player_x;
	map_y = (int)player_y;
	game->ray.dir_x = cos(angle);
	game->ray.dir_y = sin(angle);
	dda->delta_x = calc_delta(game->ray.dir_x);
	init_dda_axis_x(game, dda, player_x, map_x);
	dda->delta_y = calc_delta(game->ray.dir_y);
	init_dda_axis_y(game, dda, player_y, map_y);
	dda->map_x = map_x;
	dda->map_y = map_y;
}

void	perform_dda(t_game *game, t_dda *dda)
{
	while (1)
	{
		if (dda->side_x < dda->side_y)
		{
			dda->side_x += dda->delta_x;
			dda->map_x += dda->step_x;
			game->ray.side = 0;
		}
		else
		{
			dda->side_y += dda->delta_y;
			dda->map_y += dda->step_y;
			game->ray.side = 1;
		}
		if (game->map.grid[dda->map_y][dda->map_x] == '1')
			break ;
	}
}

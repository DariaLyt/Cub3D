/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvync <dlytvync@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:08:34 by dlytvync          #+#    #+#             */
/*   Updated: 2026/02/26 12:08:35 by dlytvync         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_minimap_rays(t_game *game)
{
	double	ray_x;
	double	ray_y;
	double	x;
	double	y;
	double	angle;

	angle = game->player.angle;
	while (angle <= (game->player.angle))
	{
		ray_x = game->player.pos_x;
		ray_y = game->player.pos_y;
		while (!is_wall(game, ray_x, ray_y))
		{
			ray_x += cos(angle) * STEP_SIZE;
			ray_y += sin(angle) * STEP_SIZE;
			x = ray_x * MINIMAP_SCALE;
			y = ray_y * MINIMAP_SCALE;
			if (x >= 0 && x < game->width && y >= 0 && y < game->height)
				mlx_put_pixel(game->image, (int)x, (int)y, RED_COLOR);
		}
		angle += 0.001;
	}
}

void	draw_mini_square(t_game *game, int x, int y, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if ((x + i) >= 0 && (x + i) < game->width
				&& (y + j) >= 0 && (y + j) < game->height)
			{
				mlx_put_pixel(game->image, x + i, y + j, game->mini_color);
			}
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	int	x;
	int	y;
	int	screen_x;
	int	screen_y;

	game->mini_color = 0;
	y = -1;
	while (game->map.grid[++y])
	{
		x = -1;
		while (game->map.grid[y][++x])
		{
			screen_x = x * MINIMAP_SCALE;
			screen_y = y * MINIMAP_SCALE;
			if (game->map.grid[y][x] == '\n')
				break ;
			if (game->map.grid[y][x] == '1' || game->map.grid[y][x] == ' '
				|| game->map.grid[y][x] <= 13)
				game->mini_color = BLACK_COLOR;
			else if (game->map.grid[y][x] == '0'
				|| game->map.grid[y][x] == game->player.direction)
				game->mini_color = GRAY_COLOR;
			draw_mini_square(game, screen_x, screen_y, MINIMAP_SCALE);
		}
	}
}

void	draw_player(t_game *game)
{
	int	x;
	int	y;
	int	size;
	int	i;
	int	j;

	x = (int)(game->player.pos_x * MINIMAP_SCALE);
	y = (int)(game->player.pos_y * MINIMAP_SCALE);
	size = 5;
	i = -size / 2;
	while (i <= size / 2)
	{
		j = -size / 2;
		while (j <= size / 2)
		{
			if (x + i >= 0 && x + i < game->width
				&& y + j >= 0 && y + j < game->height)
			{
				mlx_put_pixel(game->image, x + i, y + j, RED_COLOR);
			}
			j++;
		}
		i++;
	}
}

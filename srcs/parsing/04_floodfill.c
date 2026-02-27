/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:36:14 by pnurmi            #+#    #+#             */
/*   Updated: 2026/02/27 09:36:16 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_map_closed(t_game *game)
{
	char	**temp_grid;
	int		is_closed;

	temp_grid = ft_dup_map(game);
	if (find_player(game) == INVALID)
	{
		free_tmp_map(temp_grid);
		return (INVALID);
	}
	if (flood_fill(game, temp_grid, game->player.pos_x,
			game->player.pos_y) == INVALID)
	{
		free_tmp_map(temp_grid);
		printf("Error: Map not enclosed\n");
		return (INVALID);
	}
	free_tmp_map(temp_grid);
	return (SUCCESS);
}

int	find_player(t_game *game)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			if (ft_strchr("NSEW", game->map.grid[y][x]))
			{
				save_play_cord(game, game->map.grid[y][x], x, y);
				count++;
			}
			x++;
		}
		y++;
	}
	if (count != 1)
		return (printf("Error: Wrong player count: %d\n", count), INVALID);
	return (SUCCESS);
}

void	save_play_cord(t_game *game, char direction, int x, int y)
{
	game->player.pos_x = x + 0.5;
	game->player.pos_y = y + 0.5;
	game->player.direction = direction;
}

char	**ft_dup_map(t_game *game)
{
	char	**temp_grid;
	int		y;
	int		x;

	temp_grid = malloc(sizeof(char *) * (game->map.height + 1));
	y = 0;
	while (y < game->map.height)
	{
		temp_grid[y] = malloc(sizeof(char) * (game->map.width + 1));
		x = 0;
		while (x < game->map.width)
		{
			if (x < (int)ft_strlen(game->map.grid[y]))
				temp_grid[y][x] = game->map.grid[y][x];
			else
				temp_grid[y][x] = ' ';
			x++;
		}
		temp_grid[y][x] = '\0';
		y++;
	}
	temp_grid[y] = NULL;
	return (temp_grid);
}

int	flood_fill(t_game *game, char **temp_grid, int x, int y)
{
	if (y < 0 || y >= game->map.height || x < 0
		|| x >= (int)ft_strlen(temp_grid[y]))
		return (INVALID);
	if (temp_grid[y][x] == ' ' || temp_grid[y][x] == '\t'
		|| temp_grid[y][x] == '\n')
		return (INVALID);
	if (temp_grid[y][x] == '1' || temp_grid[y][x] == 'V')
		return (SUCCESS);
	temp_grid[y][x] = 'V';
	if (flood_fill(game, temp_grid, x + 1, y) == INVALID)
		return (INVALID);
	if (flood_fill(game, temp_grid, x - 1, y) == INVALID)
		return (INVALID);
	if (flood_fill(game, temp_grid, x, y + 1) == INVALID)
		return (INVALID);
	if (flood_fill(game, temp_grid, x, y - 1) == INVALID)
		return (INVALID);
	return (SUCCESS);
}

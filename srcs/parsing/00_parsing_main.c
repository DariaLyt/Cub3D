/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_parsing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:36:08 by pnurmi            #+#    #+#             */
/*   Updated: 2026/02/27 09:40:07 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parsing(char *map_name, t_game *game)
{
	if (is_valid_ext(map_name) == INVALID)
		return (INVALID);
	if (fill_map_struct(game, (map_name)) == INVALID)
		return (INVALID);
	return (SUCCESS);
}

int	fill_map_struct(t_game *game, char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (INVALID);
	if (parse_file(game, fd) == INVALID)
	{
		close(fd);
		free_map(game);
		return (INVALID);
	}
	close(fd);
	convert_list_to_grid(game);
	if (is_map_closed(game) == INVALID)
	{
		free_map(game);
		return (INVALID);
	}
	ft_lstclear(&game->map.temp_list, free);
	return (SUCCESS);
}

void	init_game_struct(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->map.no_path = NULL;
	game->map.so_path = NULL;
	game->map.we_path = NULL;
	game->map.ea_path = NULL;
	game->map.floor_col = -1;
	game->map.ceiling_col = -1;
	game->map.grid = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.temp_list = NULL;
	game->texture.north = NULL;
	game->texture.east = NULL;
	game->texture.south = NULL;
	game->texture.west = NULL;
}

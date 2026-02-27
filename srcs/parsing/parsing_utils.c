/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:36:24 by pnurmi            #+#    #+#             */
/*   Updated: 2026/02/27 09:40:13 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_strjoin_and_free(char *map_whole, char *line)
{
	char	*result;

	result = ft_strjoin(map_whole, line);
	if (map_whole)
		free(map_whole);
	if (line)
		free(line);
	return (result);
}

void	free_map(t_game *game)
{
	int	i;

	if (game->map.grid)
	{
		i = 0;
		while (game->map.grid[i])
		{
			free(game->map.grid[i]);
			i++;
		}
		free(game->map.grid);
	}
	free(game->map.no_path);
	free(game->map.so_path);
	free(game->map.ea_path);
	free(game->map.we_path);
	free_texture(game);
	if (game->map.temp_list)
		ft_lstclear(&game->map.temp_list, free);
}

char	*skip_spaces(char *str)
{
	if (!str)
		return (NULL);
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

void	free_texture(t_game *game)
{
	if (game->texture.north)
		mlx_delete_texture(game->texture.north);
	if (game->texture.east)
		mlx_delete_texture(game->texture.east);
	if (game->texture.south)
		mlx_delete_texture(game->texture.south);
	if (game->texture.west)
		mlx_delete_texture(game->texture.west);
}

void	free_tmp_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	print_game_data(t_game *game)
{
	int	i;

	printf("\n--- DEBUG: GAME DATA ---\n");
	// 1. Print Texture Paths
	printf("NO Path: [%s]\n", game->map.no_path ? game->map.no_path : "NULL");
	printf("SO Path: [%s]\n", game->map.so_path ? game->map.so_path : "NULL");
	printf("WE Path: [%s]\n", game->map.we_path ? game->map.we_path : "NULL");
	printf("EA Path: [%s]\n", game->map.ea_path ? game->map.ea_path : "NULL");
	// 2. Print Colors (using %d for decimal or %X for Hexadecimal)
	printf("Floor Color:   %d (Hex: 0x%X)\n", game->map.floor_col,
		game->map.floor_col);
	printf("Sky/Ceil Color: %d (Hex: 0x%X)\n", game->map.ceiling_col,
		game->map.ceiling_col);
	// 3. Print Map Dimensions
	printf("Map Dimensions: %d (W) x %d (H)\n", game->map.width,
		game->map.height);
	// 4. Print the Grid
	printf("Grid Content:\n");
	if (game->map.grid)
	{
		i = 0;
		while (game->map.grid[i])
		{
			printf("[%02d] |%s|\n", i, game->map.grid[i]);
			i++;
		}
	}
	else
		printf("[NULL GRID]\n");
	printf("------------------------\n\n");
}

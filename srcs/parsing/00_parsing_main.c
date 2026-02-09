#include "cub.h"

/*
1. setup the direction textures
2. parse texture also initiliazes
3. then floor and sky box (rgb)
4. check if textures are all set
5. if all set then map grid is parsed
6. if valid ? profit
*/

int	parsing(char *map_name, t_game *game)
{
	// if (validity check here)
	// return (0);
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
	ft_lstclear(&game->map.temp_list, free);
	// floodfill
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
	game->map.floor_col = 255;   // << hardcoded values
	game->map.ceiling_col = 255; // << hardcoded values
	game->map.grid = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.temp_list = NULL;
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

#include "cub.h"

int		parse_texture(t_game *game, char *line);
void	init_game_struct(t_game *game);
int		parse_file(t_game *game, int fd);
int		is_metadata(t_game *game, char *line);
int		save_path(char **dest, char *src);

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
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	init_game_struct(game);
	if (fill_map_struct(game, map_name) == INVALID)
	{
		free_map(game);
		free(game);
		return (0);
	}
	return (0);
}

int	fill_map_struct(t_game *game, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (INVALID);
	if (parse_file(game, fd) == INVALID)
		return (INVALID);
	return (0);
}

int	parse_file(t_game *game, int fd)
{
	char	*line;
	int		count;

	count = 0;
	while ((line = get_next_line(fd)))
	{
		if (count < 6 && is_empty_line(line))
			free(line);
		if (count < 6)
		{
			if (is_metadata(game, line) == SUCCESS)
				count++;
			else
				return (INVALID);
		}
		else
		{
			if (add_to_map_list(game, line) == INVALID)
				return (INVALID);
		}
		free(line);
	}
	close(fd);
	return (count == 6);
}

int	is_metadata(t_game *game, char *line)
{
	char	*trimmed;

	trimmed = skip_spaces(line);
	if (ft_strncmp(trimmed, "NO ", 3) == SUCCESS)
		return (save_path(&game->map.no_path, trimmed + 3));
	if (ft_strncmp(trimmed, "SO ", 3) == SUCCESS)
		return (save_path(&game->map.no_path, trimmed + 3));
	if (ft_strncmp(trimmed, "EA ", 3) == SUCCESS)
		return (save_path(&game->map.no_path, trimmed + 3));
	if (ft_strncmp(trimmed, "WE ", 3) == SUCCESS)
		return (save_path(&game->map.no_path, trimmed + 3));
	// if (ft_strncmp(trimmed, "F ", 2) == 0)
	// save_color(255);
	// if (ft_strncmp(trimmed, "C ", 2) == 0)
	// save_color(255);
	return (INVALID);
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
}

int	save_path(char **dest, char *src)
{
	char	*path;

	if (*dest != NULL)
		return (INVALID);
	path = ft_strtrim(src, " \n\t");
	if (!path)
		return (INVALID);
	if (path[0] == '\0')
	{
		free(path);
		return (INVALID);
	}
	*dest = path;
	return (SUCCESS);
}

int	save_color(char **dest, char *src)
{
	return (INVALID);
	// rgb requires a converter?
}

int	add_to_map_list(t_game *game, char *line)
{
	if (is_valid_map_line == INVALID)
		return (INVALID);

	
}

int	is_valid_map_line(char *line)
{
	while(*line)
	{
		if(is_valid_char(*line) == INVALID);
			return(INVALID);
	}
}

int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == ' ' || c == '\n')
		return (SUCCESS);
	return (INVALID);
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

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

/*
function to find the correct file
do we need this one?
*/

char	*find_file(char *map_name)
{
	char	*path_name;
	char	*extension;
	int		fd;

	extension = ".cub";
	path_name = ft_strnstr(map_name, extension, ft_strlen(map_name));
	fd = open(path_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	close(fd);
	return (path_name);
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
	// convert list to **grid here
	// clean temp list here // check libft
	return (SUCCESS);
}

int	parse_file(t_game *game, int fd)
{
	char	*line;
	int		count;

	count = 0;
	while ((line = get_next_line(fd)))
	{
		if (is_empty_line(line))
		{
			free(line);
			continue ;
		}
		if (count < 6) // change 6 when rgb ready
		{
			if (is_metadata(game, line) == SUCCESS)
				count++;
			else
				return (INVALID);
		}
		else
			add_to_map_list(game, line);
		free(line);
	}
	if (count != 6) // change to 6 when rgb ready
		return (INVALID);
	return (SUCCESS);
}

int	is_metadata(t_game *game, char *line)
{
	char	*trimmed;

	trimmed = skip_spaces(line);
	if (ft_strncmp(trimmed, "NO ", 3) == SUCCESS)
		return (save_path(&game->map.no_path, trimmed + 3));
	if (ft_strncmp(trimmed, "SO ", 3) == SUCCESS)
		return (save_path(&game->map.so_path, trimmed + 3));
	if (ft_strncmp(trimmed, "EA ", 3) == SUCCESS)
		return (save_path(&game->map.ea_path, trimmed + 3));
	if (ft_strncmp(trimmed, "WE ", 3) == SUCCESS)
		return (save_path(&game->map.we_path, trimmed + 3));
	if (ft_strncmp(trimmed, "F ", 2) == SUCCESS)
		return (save_color(&game->map.floor_col, trimmed + 1));
	if (ft_strncmp(trimmed, "C ", 2) == SUCCESS)
		return (save_color(&game->map.ceiling_col, trimmed + 1));
	printf("metadata invalid\n");
	free(line);
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
	game->map.temp_list = NULL;
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

int	save_color(int *dest, char *src)
{
	return (SUCCESS);
	// rgb requires a converter?
}

int	add_to_map_list(t_game *game, char *line)
{
	t_list	*new_node;

	if (is_valid_map_line(line) == INVALID)
		return (INVALID);
	new_node = ft_lstnew(ft_strdup(line));
	if (!new_node)
		return (ALLOC_FAIL);
	ft_lstadd_back(&(game->map.temp_list), new_node);
	update_map_dims(&game->map, line);
	// << check here for Max map limit?
	return (SUCCESS);
}

void	update_map_dims(t_map *map, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	if (len > map->width)
		map->width = len;
	map->height++;
}

int	is_valid_map_line(char *line)
{
	while (*line)
	{
		if (is_valid_char(*line) == INVALID)
			return (INVALID);
		line++;
	}
	return (SUCCESS);
}

int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == ' ' || c == '\n')
		return (SUCCESS);
	return (INVALID);
}

int	convert_list_to_grid(t_game *game)
{
	t_list	*current;
	int		i;

	if (!game->map.temp_list)
		return (INVALID);
	game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.grid)
		return (ALLOC_FAIL);
	current = game->map.temp_list;
	i = 0;
	while (current)
	{
		game->map.grid[i] = ft_strdup(current->content);
		if (!game->map.grid[i])
			return (ALLOC_FAIL); // free?
		current = current->next;
		i++;
	}
	game->map.grid[i] = NULL;
	return (SUCCESS);
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

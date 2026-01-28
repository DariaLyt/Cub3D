#include "cub.h"

int		parse_texture(t_game *game, char *line);
void	init_paths(t_game *game);

/*
1. setup the direction textures
2. parse texture also initiliazes
3. then floor and ceiling colours (rgb)
4. check if textures are all set
5. if all set then map grid is parsed
6. if valid ?
*/

int	parsing(char *map_name, t_game *game)
{
	fill_map_struct(game, map_name);
	return (0);
}

int	fill_map_struct(t_game *game, char *file)
{
	char	*map_string;

	map_string = read_file(file);
	if (map_string == NULL)
		return (0); // call cleanup
	parse_texture(game, map_string);
	// set_floor_col();
	// set_ceiling_col();
	// check_textures();
	// parse_grid();
	return 0;
}

char	*read_file(char *file)
{
	char	*line;
	char	*map_string;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_string = ft_strdup("");
	line = get_next_line(fd);
	while (line != NULL)
	{
		map_string = ft_strjoin_and_free(map_string, line);
		if (!map_string)
			;
		return (NULL);
		line = get_next_line(fd);
		printf("%s", line); // remove <<<
	}
	close(fd);
	return (map_string);
}

int	parse_texture(t_game *game, char *line)
{
	init_paths(game);
	// find_path_no(game, line);
	// find_path_so(game, line);
	// find_path_ea(game, line);
	// find_path_we(game, line);
	return 0;
}

void	init_paths(t_game *game)
{
	game->map->no_path = NULL;
	game->map->so_path = NULL;
	game->map->ea_path = NULL;
	game->map->we_path = NULL;
	game->map->grid = NULL;
}

int	find_path_no(t_game *game, char *line)
{
	char	*path;

	// path = ft_strchr("NO ./");
	open(path, O_RDONLY);
	return 0;
}

int	find_path_so(void)
{
}

int	find_path_we(void)
{
}

int	find_path_ea(void)
{
}

/*
rgb conversion and validation
255/255/255
*/

int	rgb_conversion(void)
{
}

int	set_floor_col(void)
{
}

int	set_ceiling_col(void)
{
}

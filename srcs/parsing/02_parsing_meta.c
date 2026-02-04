#include "cub.h"

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

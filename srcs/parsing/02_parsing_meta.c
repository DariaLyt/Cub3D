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
		return (save_color(&game->map.floor_col, trimmed + 2));
	if (ft_strncmp(trimmed, "C ", 2) == SUCCESS)
		return (save_color(&game->map.ceiling_col, trimmed + 2));
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

static int assign_rgb(char *rgb)
{
	char *color;
	int i = 0;

	while(rgb[i])
	{
		if(rgb[i] > 0 && rgb[i] < 9)
			color[i] = rgb[i];
		if(rgb[i] == ',')
			break;
		else
			return(INVALID);
		i++;
	}
	return(ft_atoi(color));
}

int	save_color(int *dest, char *src)
{
	char *path;
	int r, g, b;

	if(*dest != -1)
		return(INVALID);
	path = ft_strtrim(src, " \n\t");
	if(!path)
		return(INVALID);
	if(path[0] == '\0')
	{
		free(path);
		return(INVALID);
	}
	r = assign_rgb(path);
	g = assign_rgb(path);
	b = assign_rgb(path);
	printf("r:%d g:%d b:%d \n", r, g ,b);
	*dest = mk_col(r, g, b);
	printf("save colour debug\n");
	return (SUCCESS);
}

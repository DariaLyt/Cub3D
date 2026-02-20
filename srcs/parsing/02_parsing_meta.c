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

int	assign_rgb(char **m_str)
{
	int		rgb;
	char	*pos;

	pos = *m_str;
	while (*pos && (*pos == ' ' || *pos == '\t'))
		pos++;
	if (!ft_isdigit(*pos))
		return (INVALID);
	rgb = atoi(pos);
	while (*pos && ft_isdigit(*pos))
		pos++;
	while (*pos && (*pos == ' ' || *pos == '\t'))
		pos++;
	if (*pos == ',')
		pos++;
	*m_str = pos;
	return (rgb);
}

int	save_color(int *dest, char *src)
{
	char	*path;
	char	*tmp;

	int r, g, b;
	if (*dest != -1)
	{
		free(path);
		return (INVALID);
	}
	path = ft_strtrim(src, " \n\t");
	tmp = path;
	r = assign_rgb(&tmp);
	printf("%d\n", r); // Delete me after
	g = assign_rgb(&tmp);
	printf("%d\n", g); // Delete me after
	b = assign_rgb(&tmp);
	printf("%d\n", b); // Delete me after
	free(path);
	// while(*tmp && (*tmp == ' ' || *tmp == '\t'))
	// 	tmp++;
	// if(*tmp != '\0')
	// 	return(INVALID);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (INVALID);
	*dest = (r << 16 | g << 8 | b);
	return (SUCCESS);
}
